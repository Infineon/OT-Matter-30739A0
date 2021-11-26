#
# $ Copyright 2016-YEAR Cypress Semiconductor $
#

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

#
# gdb command line launch
#
CY_GDB_CLIENT=$(CY_COMPILER_DIR_BWC)/bin/arm-none-eabi-gdb
CY_GDB_SYM=$(CY_CONFIG_DIR)/$(APPNAME).elf
CY_GDB_ARGS=$(CY_INTERNAL_BASELIB_PATH)/make/scripts/gdbinit

#
# openocd gdb server command line launch
#
CY_OPENOCD_SEARCH=-s $(CY_OPENOCD_DIR)/scripts -s $(CY_BASELIB_PATH)/platforms
CY_OPENOCD_CONFIG=-f CYW$(CY_TARGET_DEVICE)_openocd.cfg
CY_OPENOCD_GDB_SERVER_ARGS=$(CY_OPENOCD_SEARCH) $(CY_OPENOCD_CONFIG)

#
# jlink gdb server command line launch
#
CY_JLINK_GDB_SERVER_PATH=.
CY_JLINK_GDB_SERVER=$(CY_JLINK_GDB_SERVER_PATH)/JLinkGDBServerCL
ifeq ($(CY_TARGET_DEVICE),20706A2)
CY_JLINK_GDB_SERVER_ARGS=-USB -device Cortex-M3 -endian little -if SWD -speed auto -noir -LocalhostOnly
else
CY_JLINK_GDB_SERVER_ARGS=-USB -device Cortex-M4 -endian little -if SWD -speed auto -noir -LocalhostOnly
endif
# set to same port as openocd default
CY_JLINK_GDB_SERVER_ARGS+= -port 3333

#
# gdb server selection
#
ifeq ($(GDB_SERVER),jlink)
GDB_SERVER_COMMAND=$(CY_JLINK_GDB_SERVER) $(CY_JLINK_GDB_SERVER_ARGS)
endif
GDB_SERVER_COMMAND?=$(CY_OPENOCD_DIR)/bin/openocd $(CY_OPENOCD_GDB_SERVER_ARGS)

#
# custom download
#
CY_DOWNLOAD_CMD=\
	bash "$(CY_INTERNAL_BASELIB_PATH)/make/scripts/bt_program.bash"\
	--shell="$(CY_MODUS_SHELL_DIR_BWC)"\
	--tools="$(CY_WICED_TOOLS_DIR)"\
	--scripts="$(CY_INTERNAL_BASELIB_PATH)/make/scripts"\
	--hex="$(CY_CONFIG_DIR)/$(APPNAME)_download.hex"\
	--elf="$(CY_CONFIG_DIR)/$(APPNAME).elf"\
	--uart=$(UART)\
	--direct=$(DIRECT_LOAD)\
	$(if $(VERBOSE),--verbose)

program: build qprogram

$(CY_CONFIG_DIR)/$(APPNAME).hex: $(CY_CONFIG_DIR)/$(APPNAME).elf
	$(CY_NOISE)$(CY_RECIPE_POSTBUILD) $(CY_CMD_TERM)

$(CY_CONFIG_DIR)/$(APPNAME).hcd: $(CY_CONFIG_DIR)/$(APPNAME).elf
	$(CY_NOISE)$(CY_RECIPE_POSTBUILD) $(CY_CMD_TERM)

#
# only program if it is not a lib project, and if not DIRECT_LOAD
#
ifeq ($(LIBNAME),)
qprogram: $(CY_CONFIG_DIR)/$(APPNAME).hex
	@echo "Programming target device ... "
	$(if $(VERBOSE),@echo $(CY_DOWNLOAD_CMD))
	@$(CY_DOWNLOAD_CMD)
	@echo "Programming complete"
else
qprogram:
	@echo "Library application detected. Skip programming... ";\
	echo
endif

debug: program qdebug

qdebug: qprogram
ifeq ($(LIBNAME),)
	@echo;\
	echo ==============================================================================;\
	echo "Instruction:";\
	echo "Open a separate shell and run the attach target (make attach)";\
	echo "to start the GDB client. Then use the GDB commands to debug.";\
	echo ==============================================================================;\
	echo;\
	echo "Opening GDB port ... ";\
	$(GDB_SERVER_COMMAND)
else
	@echo "Library application detected. Skip debug... ";\
	echo
endif

attach:
	@echo;\
	@echo "Starting GDB Client... ";\
	$(CY_GDB_CLIENT) -s $(CY_GDB_SYM) -x $(CY_GDB_ARGS)

.PHONY: program qprogram debug qdebug

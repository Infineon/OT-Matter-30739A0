/***********************************************************************************************//**
 * \file cy_result.h
 *
 * \brief
 * Basic function result handling. Defines a simple type for conveying
 * information about whether something succeeded or details about any issues
 * that were detected.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2021 Cypress Semiconductor Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/
#pragma once

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
  * @brief Provides the result of an operation as a structured bitfield.
  *
  * See the \ref anchor_general_description "General Description"
  * for more details on structure and usage.
  */
typedef uint32_t cy_rslt_t;
typedef enum
{
    /** The result code is informational-only */
    CY_RSLT_TYPE_INFO = 0U,
    /** The result code is warning of a problem but will proceed */
    CY_RSLT_TYPE_WARNING = 1U,
    /** The result code is an error */
    CY_RSLT_TYPE_ERROR = 2U,
    /** The result code is a fatal error */
    CY_RSLT_TYPE_FATAL = 3U
} cy_en_rslt_type_t;

/** @ref cy_rslt_t return value indicating success */
#define CY_RSLT_SUCCESS                    ((cy_rslt_t)0x00000000U)

/** \cond INTERNAL */
/** Mask for the bit at position "x" */
#define CY_BIT_MASK(x)                     ((1UL << (x)) - 1U)

/** Bit position of the result type */
#define CY_RSLT_TYPE_POSITION              (16U)
/** Bit width of the result type */
#define CY_RSLT_TYPE_WIDTH                 (2U)
/** Bit position of the module identifier */
#define CY_RSLT_MODULE_POSITION            (18U)
/** Bit width of the module identifier */
#define CY_RSLT_MODULE_WIDTH               (14U)
/** Bit position of the result code */
#define CY_RSLT_CODE_POSITION              (0U)
/** Bit width of the result code */
#define CY_RSLT_CODE_WIDTH                 (16U)

/** Mask for the result type */
#define CY_RSLT_TYPE_MASK                  CY_BIT_MASK(CY_RSLT_TYPE_WIDTH)
/** Mask for the module identifier */
#define CY_RSLT_MODULE_MASK                CY_BIT_MASK(CY_RSLT_MODULE_WIDTH)
/** Mask for the result code */
#define CY_RSLT_CODE_MASK                  CY_BIT_MASK(CY_RSLT_CODE_WIDTH)
/** Module identifier for the SSD1306 OLED Controller Library */
#define CY_RSLT_MODULE_BOARD_HARDWARE_SSD1306       (0x01C3U)

/**
  * @brief Create a new @ref cy_rslt_t value that encodes the specified type, module, and result code.
  * @param type one of @ref CY_RSLT_TYPE_INFO, @ref CY_RSLT_TYPE_WARNING,
  *  @ref CY_RSLT_TYPE_ERROR, @ref CY_RSLT_TYPE_FATAL
  * @param module Identifies the module where this result originated; see @ref anchor_modules "Modules".
  * @param code a module-defined identifier to identify the specific situation that
  * this result describes.
  */
#define CY_RSLT_CREATE(type, module, code) \
    ((((module) & CY_RSLT_MODULE_MASK) << CY_RSLT_MODULE_POSITION) | \
    (((code) & CY_RSLT_CODE_MASK) << CY_RSLT_CODE_POSITION) | \
    (((type) & CY_RSLT_TYPE_MASK) << CY_RSLT_TYPE_POSITION))

/** Simple macro to supress the unused parameter warning by casting to void. */
#define CY_UNUSED_PARAMETER(x) ( (void)(x) )

#define CY_ASSERT(x)    do  \
                        {   \
                        } while(0)

#ifdef __cplusplus
}
#endif

/** \} group_result */

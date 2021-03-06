/*
 * \file tbx_iotypes.h
 * \brief
 *    An In Out type definition for the toolbox.
 *
 * This file is part of toolbox
 *
 * Copyright (C) 2014 Houtouridis Christos (http://www.houtouridis.net)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef __tbx_iotypes_h__
#define __tbx_iotypes_h__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef uint8_t  byte_t;         /*!< 8 bits wide */
typedef uint16_t word_t;         /*!< 16 bits wide */
typedef uint32_t dword_t;        /*!< 32 bits wide */

typedef uint32_t bytecount_t;    /*!< general counter */
typedef uint32_t address_t;      /*!< general index/address type */

/*!
 * Pin function pointers
 * \note
 *    These function pointers do not correspond to pin levels.
 *    They correspond to the enable/disable functionality of that pin.
 */
typedef uint8_t (*drv_pinin_ft)  (void);
typedef    void (*drv_pinout_ft) (uint8_t);
typedef uint8_t (*drv_pinio_ft)  (uint8_t);
typedef    void (*drv_pindir_ft) (uint8_t);

/*!
 * Analog input function pointer
 */
typedef  float (*drv_ain_f_ft) (void);
typedef    int (*drv_ain_i_ft) (void);

/*!
 * Digital I/O function pointers
 * \note
 *    These function pointers do not correspond to circuit/port/pin levels.
 *    They correspond to the enable/disable functionality.
 */
typedef  uint8_t (*drv_din_ft)   (void);
typedef     void (*drv_dout_ft)  (uint8_t);
typedef     void (*drv_out_i_ft) (int);
typedef     void (*drv_out_f_ft) (float);

/*!
 * This is a toolbox wide generic driver status type.
 * \note
 *    DRV_NOINIT = 0, so after memset to zero called by XXXX_deinit() the
 *    module/device will automatically set to NOINIT state.
 */
typedef enum
{
   DRV_NODEV=-1,     /*!< No device/module */
   DRV_NOINIT=0,     /*!< Module/Device exist but no initialized */
   DRV_READY,        /*!< Module/Device initialized succesfully */
   DRV_BUSY,         /*!< Module/Device busy */
   //DRV_COMPLETE,     /*!< Module/device operation complete status */
   DRV_ERROR         /*!< Module/Device error */
}drv_status_en;

/*!
 * Complex types
 */
typedef double _Complex    complex_d_t;
typedef float _Complex     complex_f_t;
#ifdef __GNUC__
typedef int _Complex       complex_i_t;
#endif

#define  real(_z)       (((double*)&(_z))[0])
#define  imag(_z)       (((double*)&(_z))[1])
#define  realf(_z)      (((float*)&(_z))[0])
#define  imagf(_z)      (((float*)&(_z))[1])
#ifdef __GNUC__
#define  reali(_z)      (((int*)&(_z))[0])
#define  imagi(_z)      (((int*)&(_z))[1])
#endif
#ifdef __cplusplus
}
#endif

#endif //#ifndef __tbx_iotypes_h__

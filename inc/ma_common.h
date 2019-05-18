/**
@file		ma_common.h
@brief		This module contains commonly used utilities definitions
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0

ma_clib is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ma_clib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ma_clib.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef _MA_COMMON_H_
#define _MA_COMMON_H_
#include <ma_types.h>
#include <ma_error.h>

#define MA_CMN_PLT_END	0	//0: Little Endian - 1: Big Endian

#define MA_CMN_GEN_MASK_8(num_bits, pos)	((_t_ma_u8)(((((_t_ma_u8)1<<(num_bits))-1)) << (pos)))
#define MA_CMN_GEN_MASK_16(num_bits, pos)	((_t_ma_u16)(((((_t_ma_u16)1<<(num_bits))-1)) << (pos)))
#define MA_CMN_GEN_MASK_32(num_bits, pos)	((_t_ma_u32)(((((_t_ma_u32)1<<(num_bits))-1)) << (pos)))

#define MA_CMN_BIT_MSK_B(x)				((_t_ma_u8)(1 << (((_t_ma_u8)x)%8)))
#define MA_CMN_GET_BIT(x, b)			(((_t_ma_u8)(b) & BIT_MSK_B((x)))>>(((_t_ma_u8)x)%8))
#define MA_CMN_GET_BYTE(w, b_idx)		((_t_ma_u8)((w)>>((b_idx)<<3) & 0xff))


#if (1 == MA_CMN_PLT_END)
#define MA_CMN_ROTL8(x,shift) ((_t_ma_u8) ((x) << (shift)) | ((x) >> (8 - (shift))))
#define MA_CMN_ROTL16(x,shift) ((_t_ma_u16) ((x) << (shift)) | ((x) >> (16 - (shift))))
#define MA_CMN_ROTL32(x,shift) ((_t_ma_u32) ((x) << (shift)) | ((x) >> (32 - (shift))))
#define MA_CMN_ROTR8(x,shift) ((_t_ma_u8) ((x) >> (shift)) | ((x) << (8 - (shift))))
#define MA_CMN_ROTR16(x,shift) ((_t_ma_u16) ((x) >> (shift)) | ((x) << (16 - (shift))))
#define MA_CMN_ROTR32(x,shift) ((_t_ma_u32) ((x) >> (shift)) | ((x) << (32 - (shift))))
#elif (0 == MA_CMN_PLT_END)
#define MA_CMN_ROTL8(x,shift) ((_t_ma_u8) ((x) >> (shift)) | ((x) << (8 - (shift))))
#define MA_CMN_ROTL16(x,shift) ((_t_ma_u16) ((x) >> (shift)) | ((x) << (16 - (shift))))
#define MA_CMN_ROTL32(x,shift) ((_t_ma_u32) ((x) >> (shift)) | ((x) << (32 - (shift))))
#define MA_CMN_ROTR8(x,shift) ((_t_ma_u8) ((x) << (shift)) | ((x) >> (8 - (shift))))
#define MA_CMN_ROTR16(x,shift) ((_t_ma_u16) ((x) << (shift)) | ((x) >> (16 - (shift))))
#define MA_CMN_ROTR32(x,shift) ((_t_ma_u32) ((x) << (shift)) | ((x) >> (32 - (shift))))
#endif

/**
@function	ma_cmn_memcpy
@brief		Memory copy
@param[IN]	src: Pointer to source byte array
@param[OUT]	dst: Pointer to destination byte array
@param[IN]	len: Length of dst/src arrays
@return		NO Return
@notes		No input parameters error checking is performed.
			The caller is responsible for the validity of the passed parameters.
			Buffers overlapping isn't supported
@author		M. Abdelmawla
@date		18 MAY 2019
@version	1.0
*/
void ma_cmn_memcpy(_t_ma_u8* src, _t_ma_u8* dst, int len);


#endif //_MA_COMMON_H_

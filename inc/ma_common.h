/**
@file		ma_common.h
@brief		This module contains commonly used utilities definitions
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0
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

#endif //_MA_COMMON_H_
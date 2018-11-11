/**
@file		ma_aes.h
@brief		This module contains AES APIs declaration
@author		M. Abdelmawla
@date		08 JAN 2018
@version	1.0
*/
#ifndef _MA_AES_H_
#define _MA_AES_H_
#include "ma_common.h"

/*!< AES Operations */
#define MA_AES_OP_NUM_BITS		1
#define MA_AES_OP_SHIFT			0
#define MA_AES_OP_MSK			MA_CMN_GEN_MASK_32(MA_AES_OP_NUM_BITS,MA_AES_OP_SHIFT)
#define MA_AES_OP_ENC			0
#define MA_AES_OP_DEC			1

/*!< AES MODE */
#define MA_AES_MODE_NUM_BITS	8
#define MA_AES_MODE_SHIFT		(MA_AES_OP_SHIFT + MA_AES_OP_NUM_BITS)
#define MA_AES_MODE_MSK			MA_CMN_GEN_MASK_32(MA_AES_MODE_NUM_BITS,MA_AES_MODE_SHIFT)
#define MA_AES_MODE_ECB			0
#define MA_AES_MODE_CBC			1

/*!< AES CFG */
#define MA_AES_CFG(op,mode)		\
	((((_t_ma_u32)(op) & MA_CMN_GEN_MASK_32(MA_AES_OP_NUM_BITS,0)) << MA_AES_OP_SHIFT) | \
	(((_t_ma_u32)(mode) & MA_CMN_GEN_MASK_32(MA_AES_MODE_NUM_BITS, 0)) << MA_AES_MODE_SHIFT))

/*!< AES GET OP CFG */
#define MA_AES_GET_OP(cfg)	(((cfg) & MA_AES_OP_MSK)>>MA_AES_OP_SHIFT)

/*!< AES GET MODE CFG */
#define MA_AES_GET_MODE(cfg)	(((cfg) & MA_AES_MODE_MSK)>>MA_AES_MODE_SHIFT)

_t_ma_err ma_aes();
#endif _MA_AES_H_
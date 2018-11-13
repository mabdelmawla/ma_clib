/**
@file		ma_error.h
@brief		This module contains error codes definitions
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
#ifndef _MA_ERRROR_H_
#define _MA_ERRROR_H_
#include <ma_types.h>

typedef _t_ma_s32 _t_ma_err;

#define GEN_ERR_CODE(base, val)	(((_t_ma_s32)(base & 0xFFFF) << 16)| ((_t_ma_s32)val & 0xFFFF))

// error codes bases
#define MA_ERR_DEF_BASE	((_t_ma_s32)0)
#define MA_ERR_AES_BASE	((_t_ma_s32)1)

// general error codes
#define MA_ERR_OK				GEN_ERR_CODE(MA_ERR_DEF_BASE,0)
#define MA_ERR_NOT_OK			GEN_ERR_CODE(MA_ERR_DEF_BASE,1)
#define MA_ERR_NOT_SUPPORTED	GEN_ERR_CODE(MA_ERR_DEF_BASE,2)

#endif //_MA_ERRROR_H_

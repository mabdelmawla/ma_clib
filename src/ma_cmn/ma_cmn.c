/*
 * ma_cmn.c
 *
 *  Created on: May 18, 2019
 *      Author: mabdelmawla
 */

#include <ma_common.h>

void ma_cmn_memcpy(_t_ma_u8* src, _t_ma_u8* dst, int len){
	while(len > 0){
		*dst = *src;
		dst++;
		src++;
		len--;
	}
}

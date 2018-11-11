#include <stdio.h>
#include <memory.h>
#include <string.h>

#include "ma_aes.h"

#include "tst_ma_utils.h"

void tst_gen_mask(void){
	printf("%08X\n", MA_AES_CFG(MA_AES_OP_DEC, MA_AES_MODE_CBC));
	printf("op = %d, mode =  %d\n", MA_AES_GET_OP(3UL), MA_AES_GET_MODE(3UL));
}

int main(void){
	//tst_gen_mask();
	tst_run(MA_TST_MODULE_ID_AES, MA_TST_SCOPE_ALL);
	return 0;
}
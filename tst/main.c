#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <ma_aes.h>

#include "tst/tst_ma_utils.h"

int main(void){
	//tst_gen_mask();
	tst_run(MA_TST_MODULE_ID_AES, MA_TST_SCOPE_ALL);
	return 0;
}


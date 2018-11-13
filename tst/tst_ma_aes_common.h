#ifndef _TST_MA_AES_CMN_H_
#define _TST_MA_AES_CMN_H_
#include "src/ma_aes/ma_aes_common.h"

_t_ma_err tst_ma_aes_cmn_shift_rows(char*);
_t_ma_err tst_ma_aes_cmn_mix_columns(char*);
_t_ma_err tst_ma_aes_cmn_key_expansion_128(char*);
_t_ma_err tst_ma_aes_cmn_key_expansion_192(char*);
_t_ma_err tst_ma_aes_cmn_key_expansion_256(char*);

#endif

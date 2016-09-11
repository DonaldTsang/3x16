#ifndef X16R_H
#define X16R_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void x16r_hash(const char* input, uint32_t x, char* output);

#ifdef __cplusplus
}
#endif

#endif

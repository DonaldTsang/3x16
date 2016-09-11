#ifndef X16C_H
#define X16C_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void x16c_hash(const char* input, uint32_t x, char* output);

#ifdef __cplusplus
}
#endif

#endif

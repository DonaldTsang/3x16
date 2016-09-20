#ifndef X16O_H
#define X16O_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void x16o512_hash(const char* input, uint32_t x, char* output);
void x16o256_hash(const char* input, uint32_t x, char* output);

#ifdef __cplusplus
}
#endif

#endif

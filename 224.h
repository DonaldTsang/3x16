#ifndef 224_H
#define 224_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

#define HASHS224(name) \
void hash_224 ## name(const char* input, uint32_t x, char* output);

HASHS224(blake)
HASHS224(bmw)
HASHS224(groestl)
HASHS224(jh)
HASHS224(keccak)
HASHS224(skein)
HASHS224(luffa)
HASHS224(cubehash)
HASHS224(shavite)
HASHS224(simd)
HASHS224(echo)
HASHS224(hamsi)
HASHS224(fugue)
HASHS224(shabal)
HASHS224(whirl)
HASHS224(sha)

#ifdef __cplusplus
}
#endif

#endif
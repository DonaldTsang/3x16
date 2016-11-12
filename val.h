#ifndef VAL_H
#define VAL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define HASHS320(name) \
typedef hash_ ## name ## 320_context hash_ ## name ## 384_context; \
void hash_ ## name ## 320_init(void *cc) \
void hash_ ## name ## 320(void *cc, const void *data, size_t len) \
void hash_ ## name ## 320_close(void *cc, void *dst) \

#define HASHS448(name) \
typedef hash_ ## name ## 448_context hash_ ## name ## 512_context; \
void hash_ ## name ## 448_init(void *cc) \
void hash_ ## name ## 448(void *cc, const void *data, size_t len) \
void hash_ ## name ## 448_close(void *cc, void *dst)

HASHS320(blake)
HASHS320(bmw)
HASHS320(groestl)
HASHS320(jh)
HASHS320(keccak)
HASHS320(skein)
HASHS320(luffa)
HASHS320(cubehash)
HASHS320(shavite)
HASHS320(simd)
HASHS320(echo)
HASHS320(hamsi)
HASHS320(fugue)
HASHS320(shabal)
HASHS320(whirl)
HASHS320(sha)

HASHS448(blake)
HASHS448(bmw)
HASHS448(groestl)
HASHS448(jh)
HASHS448(keccak)
HASHS448(skein)
HASHS448(luffa)
HASHS448(cubehash)
HASHS448(shavite)
HASHS448(simd)
HASHS448(echo)
HASHS448(hamsi)
HASHS448(fugue)
HASHS448(shabal)
HASHS448(whirl)
HASHS448(sha)

#ifdef __cplusplus
}
#endif

#endif
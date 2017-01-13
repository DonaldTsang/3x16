#ifndef VAL_H
#define VAL_H

#include <stdint.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"
#include "sha3/sph_hamsi.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_shabal.h"
#include "sha3/sph_whirlpond.h"
#include "sha3/sph_sha2.h"

#ifdef __cplusplus
extern "C"{
#endif

#define HASHS320(name) \
typedef sph_ ## name ## 384_context sph_ ## name ## 320_context; \
void sph_ ## name ## 320_init(void *cc); \
void sph_ ## name ## 320(void *cc, const void *data, size_t len); \
void sph_ ## name ## 320_close(void *cc, void *dst);

#define HASHS448(name) \
typedef sph_ ## name ## 512_context sph_ ## name ## 448_context; \
void sph_ ## name ## 448_init(void *cc); \
void sph_ ## name ## 448(void *cc, const void *data, size_t len); \
void sph_ ## name ## 448_close(void *cc, void *dst);

#define HASHS128(name) \
typedef sph_ ## name ## 256_context sph_ ## name ## 128_context; \
void sph_ ## name ## 128_init(void *cc); \
void sph_ ## name ## 128(void *cc, const void *data, size_t len); \
void sph_ ## name ## 128_close(void *cc, void *dst);

#define HASHS160(name) \
typedef sph_ ## name ## 320_context sph_ ## name ## 160_context; \
void sph_ ## name ## 160_init(void *cc); \
void sph_ ## name ## 160(void *cc, const void *data, size_t len); \
void sph_ ## name ## 160_close(void *cc, void *dst);

#define HASHS192(name) \
typedef sph_ ## name ## 384_context sph_ ## name ## 192_context; \
void sph_ ## name ## 192_init(void *cc); \
void sph_ ## name ## 192(void *cc, const void *data, size_t len); \
void sph_ ## name ## 192_close(void *cc, void *dst);

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

HASHS128(blake)
HASHS128(bmw)
HASHS128(groestl)
HASHS128(jh)
HASHS128(keccak)
HASHS128(skein)
HASHS128(luffa)
HASHS128(cubehash)
HASHS128(shavite)
HASHS128(simd)
HASHS128(echo)
HASHS128(hamsi)
HASHS128(fugue)
HASHS128(shabal)
HASHS128(whirl)
HASHS128(sha)

HASHS160(blake)
HASHS160(bmw)
HASHS160(groestl)
HASHS160(jh)
HASHS160(keccak)
HASHS160(skein)
HASHS160(luffa)
HASHS160(cubehash)
HASHS160(shavite)
HASHS160(simd)
HASHS160(echo)
HASHS160(hamsi)
HASHS160(fugue)
HASHS160(shabal)
HASHS160(whirl)
HASHS160(sha)

HASHS192(blake)
HASHS192(bmw)
HASHS192(groestl)
HASHS192(jh)
HASHS192(keccak)
HASHS192(skein)
HASHS192(luffa)
HASHS192(cubehash)
HASHS192(shavite)
HASHS192(simd)
HASHS192(echo)
HASHS192(hamsi)
HASHS192(fugue)
HASHS192(shabal)
HASHS192(whirl)
HASHS192(sha)

#ifdef __cplusplus
}
#endif

#endif
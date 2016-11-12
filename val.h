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
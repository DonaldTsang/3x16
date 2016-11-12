#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

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

#define HASH320(name) \
void sph_ ## name ## 320_init(void *cc) \
{ \
	sph_ ## name ## 384_init(cc); \
} \
void sph_ ## name ## 320(void *cc, const void *data, size_t len) \
{ \
	sph_ ## name ## 384(cc, data, len); \
} \
void sph_ ## name ## 320_close(void *cc, void *dst) \
{ \
	uint16_t var0[24], var1[20]; \
	sph_ ## name ## 384_close(cc, var0); \
	uint8_t i; \
	for (i = 0; i < 20; i += 1){ \
		var1[i] = var0[i] ^ var0[4+i]; \
	} \
	memcpy(dst, var1, 40); \
}

#define HASH448(name) \
void sph_ ## name ## 448_init(void *cc) \
{ \
	sph_ ## name ## 512_init(cc); \
} \
void sph_ ## name ## 448(void *cc, const void *data, size_t len) \
{ \
	sph_ ## name ## 512(cc, data, len); \
} \
void sph_ ## name ## 448_close(void *cc, void *dst) \
{ \
	uint16_t var0[32], var1[28]; \
	sph_ ## name ## 512_close(cc, var0); \
	uint8_t i; \
	for (i = 0; i < 28; i += 1){ \
		var1[i] = var0[i] ^ var0[4+i]; \
	} \
	memcpy(dst, var1, 56); \
}

HASH320(blake)
HASH320(bmw)
HASH320(groestl)
HASH320(jh)
HASH320(keccak)
HASH320(skein)
HASH320(luffa)
HASH320(cubehash)
HASH320(shavite)
HASH320(simd)
HASH320(echo)
HASH320(hamsi)
HASH320(fugue)
HASH320(shabal)
HASH320(whirl)
HASH320(sha)

HASH448(blake)
HASH448(bmw)
HASH448(groestl)
HASH448(jh)
HASH448(keccak)
HASH448(skein)
HASH448(luffa)
HASH448(cubehash)
HASH448(shavite)
HASH448(simd)
HASH448(echo)
HASH448(hamsi)
HASH448(fugue)
HASH448(shabal)
HASH448(whirl)
HASH448(sha)

#ifdef __cplusplus
}
#endif
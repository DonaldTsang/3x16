#include "val.h"
#include <stdint.h>
#include <string.h>

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

#define HASH128(name) \
void sph_ ## name ## 128_init(void *cc) \
{ \
    sph_ ## name ## 256_init(cc); \
} \
void sph_ ## name ## 128(void *cc, const void *data, size_t len) \
{ \
    sph_ ## name ## 256(cc, data, len); \
} \
void sph_ ## name ## 128_close(void *cc, void *dst) \
{ \
    uint16_t var0[16], var1[8]; \
    sph_ ## name ## 256_close(cc, var0); \
    uint8_t i; \
    for (i = 0; i < 8; i += 1){ \
        var1[i] = var0[i] ^ var0[8+i]; \
    } \
    memcpy(dst, var1, 16); \
}

#define HASH160(name) \
void sph_ ## name ## 160_init(void *cc) \
{ \
    sph_ ## name ## 320_init(cc); \
} \
void sph_ ## name ## 160(void *cc, const void *data, size_t len) \
{ \
    sph_ ## name ## 320(cc, data, len); \
} \
void sph_ ## name ## 160_close(void *cc, void *dst) \
{ \
    uint16_t var0[20], var1[10]; \
    sph_ ## name ## 320_close(cc, var0); \
    uint8_t i; \
    for (i = 0; i < 10; i += 1){ \
        var1[i] = var0[i] ^ var0[10+i]; \
    } \
    memcpy(dst, var1, 20); \
}

#define HASH192(name) \
void sph_ ## name ## 192_init(void *cc) \
{ \
    sph_ ## name ## 384_init(cc); \
} \
void sph_ ## name ## 192(void *cc, const void *data, size_t len) \
{ \
    sph_ ## name ## 384(cc, data, len); \
} \
void sph_ ## name ## 192_close(void *cc, void *dst) \
{ \
    uint16_t var0[24], var1[12]; \
    sph_ ## name ## 384_close(cc, var0); \
    uint8_t i; \
    for (i = 0; i < 12; i += 1){ \
        var1[i] = var0[i] ^ var0[12+i]; \
    } \
    memcpy(dst, var1, 24); \
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

HASH128(blake)
HASH128(bmw)
HASH128(groestl)
HASH128(jh)
HASH128(keccak)
HASH128(skein)
HASH128(luffa)
HASH128(cubehash)
HASH128(shavite)
HASH128(simd)
HASH128(echo)
HASH128(hamsi)
HASH128(fugue)
HASH128(shabal)
HASH128(whirl)
HASH128(sha)

HASH160(blake)
HASH160(bmw)
HASH160(groestl)
HASH160(jh)
HASH160(keccak)
HASH160(skein)
HASH160(luffa)
HASH160(cubehash)
HASH160(shavite)
HASH160(simd)
HASH160(echo)
HASH160(hamsi)
HASH160(fugue)
HASH160(shabal)
HASH160(whirl)
HASH160(sha)

HASH192(blake)
HASH192(bmw)
HASH192(groestl)
HASH192(jh)
HASH192(keccak)
HASH192(skein)
HASH192(luffa)
HASH192(cubehash)
HASH192(shavite)
HASH192(simd)
HASH192(echo)
HASH192(hamsi)
HASH192(fugue)
HASH192(shabal)
HASH192(whirl)
HASH192(sha)

#ifdef __cplusplus
}
#endif
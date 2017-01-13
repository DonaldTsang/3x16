#include "224.h"
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

#define HASH224(name) \
void hash_224 ## name(const char* input, uint32_t x, char* output) \
{ \
    sph_ ## name ## 224_context ctx; \
    sph_ ## name ## 224_init(&ctx); \
    sph_ ## name ## 224(&ctx, input, x); \
    sph_ ## name ## 224_close(&ctx, output); \
}

HASH224(blake)
HASH224(bmw)
HASH224(groestl)
HASH224(jh)
HASH224(keccak)
HASH224(skein)
HASH224(luffa)
HASH224(cubehash)
HASH224(shavite)
HASH224(simd)
HASH224(echo)
HASH224(hamsi)
HASH224(fugue)
HASH224(shabal)
HASH224(whirl)
HASH224(sha)

#ifdef __cplusplus
}
#endif
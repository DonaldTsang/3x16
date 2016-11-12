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

#define SIMPLE(name, size) \
void hash_ ## size ## ## name(const char* input, uint32_t x, char* output) \
{ \
    sph_ ## name ## ## size ## _context ctx; \
    sph_ ## name ## ## size ## _init(&ctx); \
    sph_ ## name ## ## size(&ctx, input, x); \
    sph_ ## name ## ## size ## _close(&ctx, output); \
}

#define SIMPLE_LOOP(name) \
SIMPLE(name, 256) \
SIMPLE(name, 384) \
SIMPLE(name, 512)

SIMPLE_LOOP(blake)
SIMPLE_LOOP(bmw)
SIMPLE_LOOP(groestl)
SIMPLE_LOOP(jh)
SIMPLE_LOOP(keccak)
SIMPLE_LOOP(skein)
SIMPLE_LOOP(luffa)
SIMPLE_LOOP(cubehash)
SIMPLE_LOOP(shavite)
SIMPLE_LOOP(simd)
SIMPLE_LOOP(echo)
SIMPLE_LOOP(hamsi)
SIMPLE_LOOP(fugue)
SIMPLE_LOOP(shabal)
SIMPLE_LOOP(whirl)
SIMPLE_LOOP(sha)

#ifdef __cplusplus
}
#endif
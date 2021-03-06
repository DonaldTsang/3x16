#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define SIMPLER(name, size) \
void hash_ ## size ## ## name(const char* input, uint32_t x, char* output);

#define SIMPLER_LOOP(name) \
SIMPLER(name, 256) \
SIMPLER(name, 384) \
SIMPLER(name, 512)

#define SIMPLERZ_LOOP(name) \
SIMPLER(name, 320) \
SIMPLER(name, 448)

#define SIMPLRY_LOOP(name) \
SIMPLE(name, 128) \
SIMPLE(name, 160) \
SIMPLE(name, 192) \
SIMPLE(name, 224)

SIMPLER_LOOP(blake)
SIMPLER_LOOP(bmw)
SIMPLER_LOOP(groestl)
SIMPLER_LOOP(jh)
SIMPLER_LOOP(keccak)
SIMPLER_LOOP(skein)
SIMPLER_LOOP(luffa)
SIMPLER_LOOP(cubehash)
SIMPLER_LOOP(shavite)
SIMPLER_LOOP(simd)
SIMPLER_LOOP(echo)
SIMPLER_LOOP(hamsi)
SIMPLER_LOOP(fugue)
SIMPLER_LOOP(shabal)
SIMPLER_LOOP(whirl)
SIMPLER_LOOP(sha)

SIMPLERZ_LOOP(blake)
SIMPLERZ_LOOP(bmw)
SIMPLERZ_LOOP(groestl)
SIMPLERZ_LOOP(jh)
SIMPLERZ_LOOP(keccak)
SIMPLERZ_LOOP(skein)
SIMPLERZ_LOOP(luffa)
SIMPLERZ_LOOP(cubehash)
SIMPLERZ_LOOP(shavite)
SIMPLERZ_LOOP(simd)
SIMPLERZ_LOOP(echo)
SIMPLERZ_LOOP(hamsi)
SIMPLERZ_LOOP(fugue)
SIMPLERZ_LOOP(shabal)
SIMPLERZ_LOOP(whirl)
SIMPLERZ_LOOP(sha)

SIMPLRY_LOOP(blake)
SIMPLRY_LOOP(bmw)
SIMPLRY_LOOP(groestl)
SIMPLRY_LOOP(jh)
SIMPLRY_LOOP(keccak)
SIMPLRY_LOOP(skein)
SIMPLRY_LOOP(luffa)
SIMPLRY_LOOP(cubehash)
SIMPLRY_LOOP(shavite)
SIMPLRY_LOOP(simd)
SIMPLRY_LOOP(echo)
SIMPLRY_LOOP(hamsi)
SIMPLRY_LOOP(fugue)
SIMPLRY_LOOP(shabal)
SIMPLRY_LOOP(whirl)
SIMPLRY_LOOP(sha)

#ifdef __cplusplus
}
#endif

#endif
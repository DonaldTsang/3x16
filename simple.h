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

SIMPLER_LOOP(sha)

SIMPLER(whirlpool, )
SIMPLER(whirlpond, )
SIMPLER(whirlpudl, )

#ifdef __cplusplus
}
#endif

#endif
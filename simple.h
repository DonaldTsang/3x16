#ifndef SIMPLE_H
#define SIMPLE_H

#ifdef __cplusplus
extern "C"{
#endif

#define SIMPLE_H(name) \
void hash_ ## name(const char* input, uint32_t x, char* output)

#define SIMPLE_H_LOOP(name) \
SIMPLE_H(256 ## name) \
SIMPLE_H(384 ## name) \
SIMPLE_H(512 ## name)

SIMPLE_H_LOOP(blake)
SIMPLE_H_LOOP(bmw)
SIMPLE_H_LOOP(groestl)
SIMPLE_H_LOOP(jh)
SIMPLE_H_LOOP(keccak)
SIMPLE_H_LOOP(skein)
SIMPLE_H_LOOP(luffa)
SIMPLE_H_LOOP(cubehash)
SIMPLE_H_LOOP(shavite)
SIMPLE_H_LOOP(simd)
SIMPLE_H_LOOP(echo)
SIMPLE_H_LOOP(hamsi)
SIMPLE_H_LOOP(fugue)
SIMPLE_H_LOOP(shabal)

SIMPLE_H_LOOP(sha)

SIMPLE_H(whirlpool)
SIMPLE_H(whirlpond)
SIMPLE_H(whirlpudl)

#ifdef __cplusplus
}
#endif
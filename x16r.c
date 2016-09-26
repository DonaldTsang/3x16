#include "x16r.h"
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

void xor512_hash(const uint32_t input[16], uint32_t output[16])
{
    char i;
    for (i = 0; i < 16; i += 1){
        output[i] ^= input[i];
    }
}

void xor256_hash(const uint16_t input[16], uint16_t output[16])
{
    char i;
    for (i = 0; i < 16; i += 1){
        output[i] ^= input[i];
    }
}

void x16r512_hash(const char* input, uint32_t x, char* output)
{
    sph_blake512_context    ctx_blake;
    sph_bmw512_context      ctx_bmw;
    sph_groestl512_context  ctx_groestl;
    sph_skein512_context    ctx_skein;
    sph_jh512_context       ctx_jh;
    sph_keccak512_context   ctx_keccak;
    sph_luffa512_context    ctx_luffa1;
    sph_cubehash512_context ctx_cubehash1;
    sph_shavite512_context  ctx_shavite1;
    sph_simd512_context     ctx_simd1;
    sph_echo512_context     ctx_echo1;
    sph_hamsi512_context    ctx_hamsi1;
    sph_fugue512_context    ctx_fugue1;
    sph_shabal512_context   ctx_shabal1;
    sph_whirlpool_context   ctx_whirlpool1;
    sph_sha512_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];
    memset(hashB, 0, 64);

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, x);
    sph_blake512_close (&ctx_blake, hashA);

    xor512_hash(hashA, hashB);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, input, x);
    sph_bmw512_close(&ctx_bmw, hashA);

    xor512_hash(hashA, hashB);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, input, x);
    sph_groestl512_close(&ctx_groestl, hashA);

    xor512_hash(hashA, hashB);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, input, x);
    sph_skein512_close (&ctx_skein, hashA);

    xor512_hash(hashA, hashB);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, input, x);
    sph_jh512_close(&ctx_jh, hashA);

    xor512_hash(hashA, hashB);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, input, x);
    sph_keccak512_close(&ctx_keccak, hashA);

    xor512_hash(hashA, hashB);

    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, input, x);
    sph_luffa512_close (&ctx_luffa1, hashA);

    xor512_hash(hashA, hashB);

    sph_cubehash512_init (&ctx_cubehash1); 
    sph_cubehash512 (&ctx_cubehash1, input, x);
    sph_cubehash512_close(&ctx_cubehash1, hashA);

    xor512_hash(hashA, hashB);

    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, input, x);
    sph_shavite512_close(&ctx_shavite1, hashA);

    xor512_hash(hashA, hashB);

    sph_simd512_init (&ctx_simd1);
    sph_simd512 (&ctx_simd1, input, x);
    sph_simd512_close(&ctx_simd1, hashA);

    xor512_hash(hashA, hashB);

    sph_echo512_init (&ctx_echo1); 
    sph_echo512 (&ctx_echo1, input, x);
    sph_echo512_close(&ctx_echo1, hashA);

    xor512_hash(hashA, hashB);

    sph_hamsi512_init (&ctx_hamsi1);
    sph_hamsi512 (&ctx_hamsi1, input, x);
    sph_hamsi512_close(&ctx_hamsi1, hashA);

    xor512_hash(hashA, hashB);

    sph_fugue512_init (&ctx_fugue1);
    sph_fugue512 (&ctx_fugue1, input, x);
    sph_fugue512_close(&ctx_fugue1, hashA);

    xor512_hash(hashA, hashB);

    sph_shabal512_init (&ctx_shabal1);
    sph_shabal512 (&ctx_shabal1, input, x);
    sph_shabal512_close(&ctx_shabal1, hashA);

    xor512_hash(hashA, hashB);

    sph_whirlpool_init (&ctx_whirlpool1);
    sph_whirlpool (&ctx_whirlpool1, input, x);
    sph_whirlpool_close(&ctx_whirlpool1, hashA);

    xor512_hash(hashA, hashB);

    sph_sha512_init (&ctx_sha2);
    sph_sha512 (&ctx_sha2, input, x);
    sph_sha512_close(&ctx_sha2, hashA);

    xor512_hash(hashA, hashB);

    memcpy(output, hashB, 64);

}

void x16r256_hash(const char* input, uint32_t x, char* output)
{
    sph_blake256_context    ctx_blake;
    sph_bmw256_context      ctx_bmw;
    sph_groestl256_context  ctx_groestl;
    sph_skein256_context    ctx_skein;
    sph_jh256_context       ctx_jh;
    sph_keccak256_context   ctx_keccak;
    sph_luffa256_context    ctx_luffa1;
    sph_cubehash256_context ctx_cubehash1;
    sph_shavite256_context  ctx_shavite1;
    sph_simd256_context     ctx_simd1;
    sph_echo256_context     ctx_echo1;
    sph_hamsi256_context    ctx_hamsi1;
    sph_fugue256_context    ctx_fugue1;
    sph_shabal256_context   ctx_shabal1;
    sph_whirlpond_context   ctx_whirlpond1;
    sph_sha256_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint16_t hashA[16], hashB[16];
    memset(hashB, 0, 32);

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, x);
    sph_blake256_close (&ctx_blake, hashA);

    xor256_hash(hashA, hashB);

    sph_bmw256_init(&ctx_bmw);
    sph_bmw256 (&ctx_bmw, input, x);
    sph_bmw256_close(&ctx_bmw, hashA);

    xor256_hash(hashA, hashB);

    sph_groestl256_init(&ctx_groestl);
    sph_groestl256 (&ctx_groestl, input, x);
    sph_groestl256_close(&ctx_groestl, hashA);

    xor256_hash(hashA, hashB);

    sph_skein256_init(&ctx_skein);
    sph_skein256 (&ctx_skein, input, x);
    sph_skein256_close (&ctx_skein, hashA);

    xor256_hash(hashA, hashB);

    sph_jh256_init(&ctx_jh);
    sph_jh256 (&ctx_jh, input, x);
    sph_jh256_close(&ctx_jh, hashA);

    xor256_hash(hashA, hashB);

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, input, x);
    sph_keccak256_close(&ctx_keccak, hashA);

    xor256_hash(hashA, hashB);

    sph_luffa256_init (&ctx_luffa1);
    sph_luffa256 (&ctx_luffa1, input, x);
    sph_luffa256_close (&ctx_luffa1, hashA);

    xor256_hash(hashA, hashB);

    sph_cubehash256_init (&ctx_cubehash1); 
    sph_cubehash256 (&ctx_cubehash1, input, x);
    sph_cubehash256_close(&ctx_cubehash1, hashA);

    xor256_hash(hashA, hashB);

    sph_shavite256_init (&ctx_shavite1);
    sph_shavite256 (&ctx_shavite1, input, x);
    sph_shavite256_close(&ctx_shavite1, hashA);

    xor256_hash(hashA, hashB);

    sph_simd256_init (&ctx_simd1);
    sph_simd256 (&ctx_simd1, input, x);
    sph_simd256_close(&ctx_simd1, hashA);

    xor256_hash(hashA, hashB);

    sph_echo256_init (&ctx_echo1); 
    sph_echo256 (&ctx_echo1, input, x);
    sph_echo256_close(&ctx_echo1, hashA);

    xor256_hash(hashA, hashB);

    sph_hamsi256_init (&ctx_hamsi1);
    sph_hamsi256 (&ctx_hamsi1, input, x);
    sph_hamsi256_close(&ctx_hamsi1, hashA);

    xor256_hash(hashA, hashB);

    sph_fugue256_init (&ctx_fugue1);
    sph_fugue256 (&ctx_fugue1, input, x);
    sph_fugue256_close(&ctx_fugue1, hashA);

    xor256_hash(hashA, hashB);

    sph_shabal256_init (&ctx_shabal1);
    sph_shabal256 (&ctx_shabal1, input, x);
    sph_shabal256_close(&ctx_shabal1, hashA);

    xor256_hash(hashA, hashB);

    sph_whirlpond_init (&ctx_whirlpond1);
    sph_whirlpond (&ctx_whirlpond1, input, x);
    sph_whirlpond_close(&ctx_whirlpond1, hashA);

    xor256_hash(hashA, hashB);

    sph_sha256_init (&ctx_sha2);
    sph_sha256 (&ctx_sha2, input, x);
    sph_sha256_close(&ctx_sha2, hashA);

    xor256_hash(hashA, hashB);

    memcpy(output, hashB, 32);

}
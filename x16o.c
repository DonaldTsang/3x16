#include "x16o.h"
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

void x16o512_hash(const char* input, uint32_t x, char* output)
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
    sph_whirl512_context   ctx_whirlpool1;
    sph_sha512_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];	

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, x);
    sph_blake512_close (&ctx_blake, hashA);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hashA, 64);
    sph_bmw512_close(&ctx_bmw, hashB);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hashB, 64);
    sph_groestl512_close(&ctx_groestl, hashA);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hashA, 64);
    sph_skein512_close (&ctx_skein, hashB);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hashB, 64);
    sph_jh512_close(&ctx_jh, hashA);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hashA, 64);
    sph_keccak512_close(&ctx_keccak, hashB);

    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, hashB, 64);
    sph_luffa512_close (&ctx_luffa1, hashA);

    sph_cubehash512_init (&ctx_cubehash1); 
    sph_cubehash512 (&ctx_cubehash1, hashA, 64);
    sph_cubehash512_close(&ctx_cubehash1, hashB);

    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, hashB, 64);
    sph_shavite512_close(&ctx_shavite1, hashA);

    sph_simd512_init (&ctx_simd1);
    sph_simd512 (&ctx_simd1, hashA, 64);
    sph_simd512_close(&ctx_simd1, hashB);

    sph_echo512_init (&ctx_echo1);
    sph_echo512 (&ctx_echo1, hashB, 64);
    sph_echo512_close(&ctx_echo1, hashA);

    sph_hamsi512_init (&ctx_hamsi1);
    sph_hamsi512 (&ctx_hamsi1, hashA, 64);
    sph_hamsi512_close(&ctx_hamsi1, hashB);

    sph_fugue512_init (&ctx_fugue1);
    sph_fugue512 (&ctx_fugue1, hashB, 64);
    sph_fugue512_close(&ctx_fugue1, hashA);

    sph_shabal512_init (&ctx_shabal1);
    sph_shabal512 (&ctx_shabal1, hashA, 64);
    sph_shabal512_close(&ctx_shabal1, hashB);

    sph_whirl512_init (&ctx_whirlpool1);
    sph_whirl512 (&ctx_whirlpool1, hashB, 64);
    sph_whirl512_close(&ctx_whirlpool1, hashA);

    sph_sha512_init (&ctx_sha2);
    sph_sha512 (&ctx_sha2, hashA, 64);
    sph_sha512_close(&ctx_sha2, hashB);

    memcpy(output, hashA, 64);

}

void x16o256_hash(const char* input, uint32_t x, char* output)
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
    sph_whirl256_context   ctx_whirlpond1;
    sph_sha256_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint16_t hashA[16], hashB[16];	

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, x);
    sph_blake256_close (&ctx_blake, hashA);

    sph_bmw256_init(&ctx_bmw);
    sph_bmw256 (&ctx_bmw, hashA, 32);
    sph_bmw256_close(&ctx_bmw, hashB);

    sph_groestl256_init(&ctx_groestl);
    sph_groestl256 (&ctx_groestl, hashB, 32);
    sph_groestl256_close(&ctx_groestl, hashA);

    sph_skein256_init(&ctx_skein);
    sph_skein256 (&ctx_skein, hashA, 32);
    sph_skein256_close (&ctx_skein, hashB);

    sph_jh256_init(&ctx_jh);
    sph_jh256 (&ctx_jh, hashB, 32);
    sph_jh256_close(&ctx_jh, hashA);

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, hashA, 32);
    sph_keccak256_close(&ctx_keccak, hashB);

    sph_luffa256_init (&ctx_luffa1);
    sph_luffa256 (&ctx_luffa1, hashB, 32);
    sph_luffa256_close (&ctx_luffa1, hashA);

    sph_cubehash256_init (&ctx_cubehash1); 
    sph_cubehash256 (&ctx_cubehash1, hashA, 32);
    sph_cubehash256_close(&ctx_cubehash1, hashB);

    sph_shavite256_init (&ctx_shavite1);
    sph_shavite256 (&ctx_shavite1, hashB, 32);
    sph_shavite256_close(&ctx_shavite1, hashA);

    sph_simd256_init (&ctx_simd1);
    sph_simd256 (&ctx_simd1, hashA, 32);
    sph_simd256_close(&ctx_simd1, hashB);

    sph_echo256_init (&ctx_echo1);
    sph_echo256 (&ctx_echo1, hashB, 32);
    sph_echo256_close(&ctx_echo1, hashA);

    sph_hamsi256_init (&ctx_hamsi1);
    sph_hamsi256 (&ctx_hamsi1, hashA, 32);
    sph_hamsi256_close(&ctx_hamsi1, hashB);

    sph_fugue256_init (&ctx_fugue1);
    sph_fugue256 (&ctx_fugue1, hashB, 32);
    sph_fugue256_close(&ctx_fugue1, hashA);

    sph_shabal256_init (&ctx_shabal1);
    sph_shabal256 (&ctx_shabal1, hashA, 32);
    sph_shabal256_close(&ctx_shabal1, hashB);

    sph_whirl256_init (&ctx_whirlpond1);
    sph_whirl256 (&ctx_whirlpond1, hashB, 32);
    sph_whirl256_close(&ctx_whirlpond1, hashA);

    sph_sha256_init (&ctx_sha2);
    sph_sha256 (&ctx_sha2, hashA, 32);
    sph_sha256_close(&ctx_sha2, hashB);

    memcpy(output, hashA, 32);

}

void x16o384_hash(const char* input, uint32_t x, char* output)
{
    sph_blake384_context    ctx_blake;
    sph_bmw384_context      ctx_bmw;
    sph_groestl384_context  ctx_groestl;
    sph_skein384_context    ctx_skein;
    sph_jh384_context       ctx_jh;
    sph_keccak384_context   ctx_keccak;
    sph_luffa384_context    ctx_luffa1;
    sph_cubehash384_context ctx_cubehash1;
    sph_shavite384_context  ctx_shavite1;
    sph_simd384_context     ctx_simd1;
    sph_echo384_context     ctx_echo1;
    sph_hamsi384_context    ctx_hamsi1;
    sph_fugue384_context    ctx_fugue1;
    sph_shabal384_context   ctx_shabal1;
    sph_whirl384_context   ctx_whirlpudl1;
    sph_sha384_context      ctx_sha2;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint16_t hashA[24], hashB[24];	

    sph_blake384_init(&ctx_blake);
    sph_blake384 (&ctx_blake, input, x);
    sph_blake384_close (&ctx_blake, hashA);

    sph_bmw384_init(&ctx_bmw);
    sph_bmw384 (&ctx_bmw, hashA, 48);
    sph_bmw384_close(&ctx_bmw, hashB);

    sph_groestl384_init(&ctx_groestl);
    sph_groestl384 (&ctx_groestl, hashB, 48);
    sph_groestl384_close(&ctx_groestl, hashA);

    sph_skein384_init(&ctx_skein);
    sph_skein384 (&ctx_skein, hashA, 48);
    sph_skein384_close (&ctx_skein, hashB);

    sph_jh384_init(&ctx_jh);
    sph_jh384 (&ctx_jh, hashB, 48);
    sph_jh384_close(&ctx_jh, hashA);

    sph_keccak384_init(&ctx_keccak);
    sph_keccak384 (&ctx_keccak, hashA, 48);
    sph_keccak384_close(&ctx_keccak, hashB);

    sph_luffa384_init (&ctx_luffa1);
    sph_luffa384 (&ctx_luffa1, hashB, 48);
    sph_luffa384_close (&ctx_luffa1, hashA);

    sph_cubehash384_init (&ctx_cubehash1); 
    sph_cubehash384 (&ctx_cubehash1, hashA, 48);
    sph_cubehash384_close(&ctx_cubehash1, hashB);

    sph_shavite384_init (&ctx_shavite1);
    sph_shavite384 (&ctx_shavite1, hashB, 48);
    sph_shavite384_close(&ctx_shavite1, hashA);

    sph_simd384_init (&ctx_simd1);
    sph_simd384 (&ctx_simd1, hashA, 48);
    sph_simd384_close(&ctx_simd1, hashB);

    sph_echo384_init (&ctx_echo1);
    sph_echo384 (&ctx_echo1, hashB, 48);
    sph_echo384_close(&ctx_echo1, hashA);

    sph_hamsi384_init (&ctx_hamsi1);
    sph_hamsi384 (&ctx_hamsi1, hashA, 48);
    sph_hamsi384_close(&ctx_hamsi1, hashB);

    sph_fugue384_init (&ctx_fugue1);
    sph_fugue384 (&ctx_fugue1, hashB, 48);
    sph_fugue384_close(&ctx_fugue1, hashA);

    sph_shabal384_init (&ctx_shabal1);
    sph_shabal384 (&ctx_shabal1, hashA, 48);
    sph_shabal384_close(&ctx_shabal1, hashB);

    sph_whirl384_init (&ctx_whirlpudl1);
    sph_whirl384 (&ctx_whirlpudl1, hashB, 48);
    sph_whirl384_close(&ctx_whirlpudl1, hashA);

    sph_sha384_init (&ctx_sha2);
    sph_sha384 (&ctx_sha2, hashA, 48);
    sph_sha384_close(&ctx_sha2, hashB);

    memcpy(output, hashA, 48);

}
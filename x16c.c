#include "x16c.h"
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

void x16c512_hash(const char* input, uint32_t x, char* output)
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
    uint32_t hash0[16][16];
    uint32_t hash1[256];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, x);
    sph_blake512_close (&ctx_blake, hash0[0]);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, input, x);
    sph_bmw512_close(&ctx_bmw, hash0[1]);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, input, x);
    sph_groestl512_close(&ctx_groestl, hash0[2]);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, input, x);
    sph_skein512_close (&ctx_skein, hash0[3]);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, input, x);
    sph_jh512_close(&ctx_jh, hash0[4]);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, input, x);
    sph_keccak512_close(&ctx_keccak, hash0[5]);

    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, input, x);
    sph_luffa512_close (&ctx_luffa1, hash0[6]);

    sph_cubehash512_init (&ctx_cubehash1);
    sph_cubehash512 (&ctx_cubehash1, input, x);
    sph_cubehash512_close(&ctx_cubehash1, hash0[7]);

    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, input, x);
    sph_shavite512_close(&ctx_shavite1, hash0[8]);

    sph_simd512_init (&ctx_simd1); 
    sph_simd512 (&ctx_simd1, input, x);
    sph_simd512_close(&ctx_simd1, hash0[9]);

    sph_echo512_init (&ctx_echo1); 
    sph_echo512 (&ctx_echo1, input, x);
    sph_echo512_close(&ctx_echo1, hash0[10]);

    sph_hamsi512_init (&ctx_hamsi1);
    sph_hamsi512 (&ctx_hamsi1, input, x);
    sph_hamsi512_close(&ctx_hamsi1, hash0[11]);

    sph_fugue512_init (&ctx_fugue1);
    sph_fugue512 (&ctx_fugue1, input, x);
    sph_fugue512_close(&ctx_fugue1, hash0[12]);

    sph_shabal512_init (&ctx_shabal1);
    sph_shabal512 (&ctx_shabal1, input, x);
    sph_shabal512_close(&ctx_shabal1, hash0[13]);

    sph_whirlpool_init (&ctx_whirlpool1);
    sph_whirlpool (&ctx_whirlpool1, input, x);
    sph_whirlpool_close(&ctx_whirlpool1, hash0[14]);

    sph_sha512_init (&ctx_sha2);
    sph_sha512 (&ctx_sha2, input, x);
    sph_sha512_close(&ctx_sha2, hash0[15]);

    uint8_t i, j;
    for (j = 0; j < 16; j += 1){
        for (i = 0; i < 16; i += 1){
            hash1[16*j+i] = hash0[i][j];
        }
    }

    memcpy(output, hash1, 1024);

}

void x16c256_hash(const char* input, uint32_t x, char* output)
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

    //these uint256 in the c++ source of the client are backed by an array of uint32
    uint16_t hash0[16][16];
    uint16_t hash1[256];

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, x);
    sph_blake256_close (&ctx_blake, hash0[0]);

    sph_bmw256_init(&ctx_bmw);
    sph_bmw256 (&ctx_bmw, input, x);
    sph_bmw256_close(&ctx_bmw, hash0[1]);

    sph_groestl256_init(&ctx_groestl);
    sph_groestl256 (&ctx_groestl, input, x);
    sph_groestl256_close(&ctx_groestl, hash0[2]);

    sph_skein256_init(&ctx_skein);
    sph_skein256 (&ctx_skein, input, x);
    sph_skein256_close (&ctx_skein, hash0[3]);

    sph_jh256_init(&ctx_jh);
    sph_jh256 (&ctx_jh, input, x);
    sph_jh256_close(&ctx_jh, hash0[4]);

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, input, x);
    sph_keccak256_close(&ctx_keccak, hash0[5]);

    sph_luffa256_init (&ctx_luffa1);
    sph_luffa256 (&ctx_luffa1, input, x);
    sph_luffa256_close (&ctx_luffa1, hash0[6]);

    sph_cubehash256_init (&ctx_cubehash1);
    sph_cubehash256 (&ctx_cubehash1, input, x);
    sph_cubehash256_close(&ctx_cubehash1, hash0[7]);

    sph_shavite256_init (&ctx_shavite1);
    sph_shavite256 (&ctx_shavite1, input, x);
    sph_shavite256_close(&ctx_shavite1, hash0[8]);

    sph_simd256_init (&ctx_simd1); 
    sph_simd256 (&ctx_simd1, input, x);
    sph_simd256_close(&ctx_simd1, hash0[9]);

    sph_echo256_init (&ctx_echo1); 
    sph_echo256 (&ctx_echo1, input, x);
    sph_echo256_close(&ctx_echo1, hash0[10]);

    sph_hamsi256_init (&ctx_hamsi1);
    sph_hamsi256 (&ctx_hamsi1, input, x);
    sph_hamsi256_close(&ctx_hamsi1, hash0[11]);

    sph_fugue256_init (&ctx_fugue1);
    sph_fugue256 (&ctx_fugue1, input, x);
    sph_fugue256_close(&ctx_fugue1, hash0[12]);

    sph_shabal256_init (&ctx_shabal1);
    sph_shabal256 (&ctx_shabal1, input, x);
    sph_shabal256_close(&ctx_shabal1, hash0[13]);

    sph_whirlpond_init (&ctx_whirlpond1);
    sph_whirlpond (&ctx_whirlpond1, input, x);
    sph_whirlpond_close(&ctx_whirlpond1, hash0[14]);

    sph_sha256_init (&ctx_sha2);
    sph_sha256 (&ctx_sha2, input, x);
    sph_sha256_close(&ctx_sha2, hash0[15]);

    uint8_t i, j;
    for (j = 0; j < 16; j += 1){
        for (i = 0; i < 16; i += 1){
            hash1[16*j+i] = hash0[i][j];
        }
    }

    memcpy(output, hash1, 512);

}

void x16c384_hash(const char* input, uint32_t x, char* output)
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
    sph_whirlpudl_context   ctx_whirlpond1;
    sph_sha384_context      ctx_sha2;

    //these uint256 in the c++ source of the client are backed by an array of uint32
    uint8_t hash0[16][16][3];
    uint8_t hash1[256][3];

    sph_blake384_init(&ctx_blake);
    sph_blake384 (&ctx_blake, input, x);
    sph_blake384_close (&ctx_blake, hash0[0]);

    sph_bmw384_init(&ctx_bmw);
    sph_bmw384 (&ctx_bmw, input, x);
    sph_bmw384_close(&ctx_bmw, hash0[1]);

    sph_groestl384_init(&ctx_groestl);
    sph_groestl384 (&ctx_groestl, input, x);
    sph_groestl384_close(&ctx_groestl, hash0[2]);

    sph_skein384_init(&ctx_skein);
    sph_skein384 (&ctx_skein, input, x);
    sph_skein384_close (&ctx_skein, hash0[3]);

    sph_jh384_init(&ctx_jh);
    sph_jh384 (&ctx_jh, input, x);
    sph_jh384_close(&ctx_jh, hash0[4]);

    sph_keccak384_init(&ctx_keccak);
    sph_keccak384 (&ctx_keccak, input, x);
    sph_keccak384_close(&ctx_keccak, hash0[5]);

    sph_luffa384_init (&ctx_luffa1);
    sph_luffa384 (&ctx_luffa1, input, x);
    sph_luffa384_close (&ctx_luffa1, hash0[6]);

    sph_cubehash384_init (&ctx_cubehash1);
    sph_cubehash384 (&ctx_cubehash1, input, x);
    sph_cubehash384_close(&ctx_cubehash1, hash0[7]);

    sph_shavite384_init (&ctx_shavite1);
    sph_shavite384 (&ctx_shavite1, input, x);
    sph_shavite384_close(&ctx_shavite1, hash0[8]);

    sph_simd384_init (&ctx_simd1); 
    sph_simd384 (&ctx_simd1, input, x);
    sph_simd384_close(&ctx_simd1, hash0[9]);

    sph_echo384_init (&ctx_echo1); 
    sph_echo384 (&ctx_echo1, input, x);
    sph_echo384_close(&ctx_echo1, hash0[10]);

    sph_hamsi384_init (&ctx_hamsi1);
    sph_hamsi384 (&ctx_hamsi1, input, x);
    sph_hamsi384_close(&ctx_hamsi1, hash0[11]);

    sph_fugue384_init (&ctx_fugue1);
    sph_fugue384 (&ctx_fugue1, input, x);
    sph_fugue384_close(&ctx_fugue1, hash0[12]);

    sph_shabal384_init (&ctx_shabal1);
    sph_shabal384 (&ctx_shabal1, input, x);
    sph_shabal384_close(&ctx_shabal1, hash0[13]);

    sph_whirlpond_init (&ctx_whirlpond1);
    sph_whirlpond (&ctx_whirlpond1, input, x);
    sph_whirlpond_close(&ctx_whirlpond1, hash0[14]);

    sph_sha384_init (&ctx_sha2);
    sph_sha384 (&ctx_sha2, input, x);
    sph_sha384_close(&ctx_sha2, hash0[15]);

    uint8_t i, j;
    for (j = 0; j < 16; j += 1){
        for (i = 0; i < 16; i += 1){
            hash1[16*j+i][0] = hash0[i][j][0];
            hash1[16*j+i][1] = hash0[i][j][1];
            hash1[16*j+i][2] = hash0[i][j][2];
        }
    }

    memcpy(output, hash1, 768);

}
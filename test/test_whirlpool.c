/* $Id: test_whirlpool.c 216 2010-06-08 09:46:57Z tp $ */
/*
 * Unit tests for the WHIRLPOOL hash functions (WHIRLPOOL-0, WHIRLPOOL-1,
 * and the "final" version WHIRLPOOL).
 *
 * ==========================(LICENSE BEGIN)============================
 *
 * Copyright (c) 2007-2010  Projet RNRT SAPHIR
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ===========================(LICENSE END)=============================
 *
 * @author   Thomas Pornin <thomas.pornin@cryptolog.com>
 */

#include "sph_whirlpool.h"
#include "test_digest_helper.c"

#if SPH_64

TEST_DIGEST_INTERNAL(WHIRLPOOL, whirlpool, 64)

static void
test_whirlpool(void)
{
	test_whirlpool_internal("",
    "19FA61D75522A4669B44E39C1D2E1726C530232130D407F89AFEE0964997F7A7"
    "3E83BE698B288FEBCF88E3E03C4F0757EA8964E59B63D93708B138CC42A66EB3");
	test_whirlpool_internal("a",
    "8ACA2602792AEC6F11A67206531FB7D7F0DFF59413145E6973C45001D0087B42"
    "D11BC645413AEFF63A42391A39145A591A92200D560195E53B478584FDAE231A");
	test_whirlpool_internal("abc",
    "4E2448A4C6F486BB16B6562C73B4020BF3043E3A731BCE721AE1B303D97E6D4C"
    "7181EEBDB6C57E277D0E34957114CBD6C797FC9D95D8B582D225292076D4EEF5");
	test_whirlpool_internal("message digest",
    "378C84A4126E2DC6E56DCC7458377AAC838D00032230F53CE1F5700C0FFB4D3B"
    "8421557659EF55C106B4B52AC5A4AAA692ED920052838F3362E86DBD37A8903E");
	test_whirlpool_internal("abcdefghijklmnopqrstuvwxyz",
    "F1D754662636FFE92C82EBB9212A484A8D38631EAD4238F5442EE13B8054E41B"
    "08BF2A9251C30B6A0B8AAE86177AB4A6F68F673E7207865D5D9819A3DBA4EB3B");
	test_whirlpool_internal("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz0123456789",
    "DC37E008CF9EE69BF11F00ED9ABA26901DD7C28CDEC066CC6AF42E40F82F3A1E"
    "08EBA26629129D8FB7CB57211B9281A65517CC879D7B962142C65F5A7AF01467");
	test_whirlpool_internal("123456789012345678901234567890"
		"12345678901234567890123456789012345678901234567890",
    "466EF18BABB0154D25B9D38A6414F5C08784372BCCB204D6549C4AFADB601429"
    "4D5BD8DF2A6C44E538CD047B2681A51A2C60481E88C5A20B2C2A80CF3A9A083B");
	test_whirlpool_internal("abcdbcdecdefdefgefghfghighijhijk",
    "2A987EA40F917061F5D6F0A0E4644F488A7A5A52DEEE656207C562F988E95C69"
    "16BDC8031BC5BE1B7B947639FE050B56939BAAA0ADFF9AE6745B7B181C3BE3FD");

	KAT_MILLION_A(WHIRLPOOL, whirlpool, 64,
    "0C99005BEB57EFF50A7CF005560DDF5D29057FD86B20BFD62DECA0F1CCEA4AF5"
    "1FC15490EDDC47AF32BB2B66C34FF9AD8C6008AD677F77126953B226E4ED8B01");
}

UTEST_MAIN("WHIRLPOOL", test_whirlpool)

#else

#include <stdio.h>

int
main(void)
{
	fprintf(stderr,
		"warning: WHIRLPOOL is not supported (no 64-bit type)\n");
	return 0;
}

#endif
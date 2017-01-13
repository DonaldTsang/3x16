# The 3x16 Manual
- Our files are a modified version of [sphlibs](http://saphir2.com/sphlib/).
    - Headers and footers are added in each hash and helper files.
- Whirlpond is a modified version of Whirlpool with 256/384/512-bit hash.
    - Whirl256(n) = Whirl512(n) ^ Whirl512(256+n) (bracket = bit position)
    - Whirl384l(n) = Whirl512(n) ^ Whirl512(128+n) (bracket = bit position)
- sha3nist.c and sha3nist.h is just a bonus script for reference.
- To use the libaray, just type `python setup.py install`

# Formatting rules
- There are no empty lines at the end of files.
- There are no "double empty lines" anywhere.
- There are single empty lines between:
    - `#include <standard library>`
    - `#include "sphlib .h files"`
    - .c and .h headers and footers.

# Use of each file
- x16module.c is used to use functions from x16 and simple.c
- x16o.c and x16o.h is using hash chaining to combine hashes. 
- x16r.c and x16r.h is using exclusive-or to combine hashes.
- x16c.c and x16c.h is using concatenation to combine hashes.
- simple.c and simple.h is used to bundle init, process and close.
- val.c and val.h is used to generate 320, 448, 128, 160 and 192 bits.
- The sha3 folder contains all 16 different hash algorithms.
    - sph_types.h is required by all hash files.
    - aes_helper.c is required by both shavite.c and echo.c
    - md_helper.c is required by sha2big.c, sha2.c and whirlpond.c
    - each hash .h file is required by it's corrosponding .c file


# Headers for .c and .h files:
```
#ifdef __cplusplus
extern "C"{
#endif
```

# Footers for .c and .h files:
```
#ifdef __cplusplus
}
#endif
```

```
 ___ ___ _ _ ___ ___ ___ 
| | |  _| v | __|__ | . |
|   |  _|> <|__ |__ |__ |
|_|_|___|_^_|___|___|___|
#@@@#@#####@#@@@#@#####@####@@@###@
#@@@#@#@@@@@@#@#@@#@@@@@@@@@#@#@@@#
#####@#####@@@#@@@####@@@###@@@####
#@@@#@#@@@@@@#@#@@@@@@#@@@@@#@@@@@#
#@@@#@#####@#@@@#@####@@####@@@###@
 _   _ _______   ______ ____   ___  
| | | |  ___\ \ / / ___\___ \ / _ \ 
| |_| | |_   \ V /| |__  __| | |_| |
|  _  |  _|   > < \___ \\__ < \__  |
| | | | |___ / ^ \ ___| |__| |  / / 
|_| |_|_____/_/ \_\____/____/  /_/  
```
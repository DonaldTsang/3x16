# The 3x16 Manual
- Our files are a modified version of [sphlibs](http://saphir2.com/sphlib/).
    - Headers and footers are added in each hash and helper files.
- Whirlpond is a modified version of Whirlpool with 256/384-bit hash.
    - The 256-bit and 384-bit version is called "Whirlpond" and "Whirlpudl".
    - Whirlpond(n) = Whirlpool(n) ^ Whirlpool(256+n) (bracket = bit position)
    - Whirlpudl(n) = Whirlpool(n) ^ Whirlpool(128+n) (bracket = bit position)
- sha3nist.c and sha3nist.h is just a bonus script for reference.

# Formatting rules
- There are no empty lines at the end of files.
- There are no "double empty lines" anywhere.
- There are single empty lines between:
    - `#include <standard library>`
    - `#include "sphlib .h files"`
    - .c and .h headers and footers.

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
#@@@#@#####@#@@@#@#####@####@@@###@
#@@@#@#@@@@@@#@#@@#@@@@@@@@@#@#@@@#
#####@#####@@@#@@@####@@@###@@@####
#@@@#@#@@@@@@#@#@@@@@@#@@@@@#@@@@@#
#@@@#@#####@#@@@#@####@@####@@@###@

```
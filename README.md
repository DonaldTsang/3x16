# The 3x16 Manual
- Our files are a modified version of [sphlibs](https://saphir2.com/sphlib/).
    - Headers and footers are added in each hash and helper files.
- Whirlpond is a modified version of Whirlpool with 256/384-bit hash.
- sha3nist.c and sha3nist.h is just a bonus script for reference.

# Format rules
- There are no empty lines at the end of files.
- There are no "double empty lines" anywhere.
- There are single empty lines between:
    - `#include <standard library>`,
    - `#include "sphlib .h files"`,
    - and headers/footers.

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
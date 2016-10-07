#The 3x16 Manual
- Our files are a modified version of sphlibs
- Whirlpond is a modified version of Whirlpool
- sha3nist.c and sha3nist.h is not necessary

#Format rules
- There are no empty lines at the end of files
- There are no "double empty lines"
- There are empty lines between
-- `#include <standard library>`,
-- `#include "sphlib .h files"`,
-- and headers/footers

#Headers for .c and .h files
```
#ifdef __cplusplus
extern "C"{
#endif
```

#Footers for .c and .h files
```
#ifdef __cplusplus
}
#endif
```
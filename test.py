from binascii import unhexlify
import x16_hash


teststart = ''.join((
    '14d079970b29a9418fd0549e7d68a95c7f168621a314201049fd07b22f3a8a34',
    '7c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000'))
testbin = unhexlify(teststart)
print(x16_hash.getHash_512o(testbin))
print(x16_hash.getHash_512r(testbin))
print(x16_hash.getHash_512c(testbin))
print('')
print(x16_hash.getHash_256o(testbin))
print(x16_hash.getHash_256r(testbin))
print(x16_hash.getHash_256c(testbin))
print('')
print(x16_hash.getHash_384o(testbin))
print(x16_hash.getHash_384r(testbin))
print(x16_hash.getHash_384c(testbin))
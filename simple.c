#define SIMPLE(name) \
void simple_ ## name ## (const char* input, uint32_t x, char* output) \
{ \
    sph_ ## name ## _context ctx_ ## name ## ; \
    sph_ ## name ## _init(&ctx_ ## name ## ); \
    sph_ ## name ## (&ctx_ ## name ## , input, x); \
    sph_ ## name ## _close(&ctx_ ## name ## , output); \
}
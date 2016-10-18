// https://gist.github.com/nirenjan/4450419

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define GAP_LENGTH 8
#define GAP_WIDTH  4
#define ROOM_LENGTH (GAP_LENGTH*2+1) // 17
#define ROOM_WIDTH (GAP_WIDTH*2+1) // 9
#define ROOM_SIZE (ROOM_LENGTH*ROOM_WIDTH) // 153
#define ARRAY_LENGTH (ROOM_LENGTH+3) // 20
#define ARRAY_WIDTH (ROOM_WIDTH+2) // 11
#define ARRAY_SIZE (ARRAY_LENGTH*ARRAY_WIDTH) // 220

const char symbols[] = {
    ' ', '.', 'o', '+', '=', '*',
    'B', 'O', 'X', '@', '%', '&',
    '#', '/', '^', 'S', 'E'
};

struct Position {
    int8_t position_x;
    int8_t position_y;
};

void mapping(const uint8_t* input, char* output){
    uint8_t i, j;
    char temp[ARRAY_WIDTH][ARRAY_LENGTH];
    temp[0] = "+--[ RandomArt ]--+\n"; // Top bar
    for (i = 0; i < ROOM_WIDTH; i += 1){
        temp[i+1][0] = "|"; // Left bar
        for (j = 0; j < ROOM_LENGTH; j += 1){
            temp[i+1][j+1] = symbols[input[i][j]];
        }
        temp[i+1][ARRAY_LENGTH-2] = "|"; // Right bar
        temp[i+1][ARRAY_LENGTH-1] = "\n"; // New line
    }
    temp[ARRAY_WIDTH-1] = "+-----------------+\n"; // bottom bar
    memcpy(output, temp, ARRAY_SIZE); // copying output
}

static int check_hex(char c)
{
    if ((c >= '0' && c <= '9') || // Numbers
        (c >= 'A' && c <= 'F') || // Upper case
        (c >= 'a' && c <= 'f')) // Lower case
    {return 1;}
    return 0;
}

static uint8_t output_hex(char c)
{
    if (c <= '9') {return (c - '0');} else // Numbers
    if (c <= 'F') {return (c - 'A' + 10);} else // Upper case 
    if (c <= 'f') {return (c - 'a' + 10);} // Lower case
    return 0;
}

Position new_position(Position pos, uint8_t dir){
    Position temp = pos;
    if (dir & 1 == 0){temp.position_x -= 1;}
    else {temp.position_x += 1;}
    if (dir & 2 == 0){temp.position_y -= 1;}
    else {temp.position_y += 1;}
}
#include <iostream>

#include "opcode.h"
#include "rom.h"

int main() {
    Rom rom = Rom( "/home/willenborg/Downloads/chip8/PONG" );
    for( long i = 0; i < rom.getByteSize() / 2; ++i ) {
        bool found = Opcode::OP_00E0.executeIfMatch( rom.getHalfWord( i ) );
    }
    return 0;
}
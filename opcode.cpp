//
// Created by willenborg on 11/08/16.
//

#include "opcode.h"

std::vector<Opcode*> Opcode::opcodes;

const Opcode Opcode::OP_00E0 = Opcode( ( unsigned char[] ){ 0x00, 0x00, 0x0E, 0x00 }, 4 );
const Opcode Opcode::OP_00EE = Opcode( ( unsigned char[] ){ 0x00, 0x00, 0x0E, 0x00 }, 4 );
const Opcode Opcode::OP_1NNN = Opcode( ( unsigned char[] ){ 0x01, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_2NNN = Opcode( ( unsigned char[] ){ 0x02, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_3XNN = Opcode( ( unsigned char[] ){ 0x03, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_4XNN = Opcode( ( unsigned char[] ){ 0x04, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_5XY0 = Opcode( ( unsigned char[] ){ 0x05, 0xFF, 0xFF, 0x00 }, 4 );
const Opcode Opcode::OP_6XNN = Opcode( ( unsigned char[] ){ 0x06, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_7XNN = Opcode( ( unsigned char[] ){ 0x07, 0xFF, 0xFF, 0xFF }, 4 );
const Opcode Opcode::OP_8XY0 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x00 }, 4 );
const Opcode Opcode::OP_8XY1 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x01 }, 4 );
const Opcode Opcode::OP_8XY2 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x02 }, 4 );
const Opcode Opcode::OP_8XY3 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x03 }, 4 );
const Opcode Opcode::OP_8XY4 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x04 }, 4 );
const Opcode Opcode::OP_8XY5 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x05 }, 4 );
const Opcode Opcode::OP_8XY6 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x06 }, 4 );
const Opcode Opcode::OP_8XY7 = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x07 }, 4 );
const Opcode Opcode::OP_8XYE = Opcode( ( unsigned char[] ){ 0x08, 0xFF, 0xFF, 0x0E }, 4 );
const Opcode Opcode::OP_9XY0 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_ANNN = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_BNNN = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_CXNN = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_DXYN = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_EX9E = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_EXA1 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX07 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX0A = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX15 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX18 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX1E = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX29 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX33 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX55 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );
const Opcode Opcode::OP_FX65 = Opcode( ( unsigned char[] ){ 0x0, 0x0, 0xE, 0x0 }, 4 );

Opcode::Opcode( uint8_t * pattern, std::size_t len ) : pattern( pattern ), size( len ) {
    opcodes.push_back( this );
};

bool Opcode::executeIfMatch( const uint16_t opcode ) const {
    for( int i = 0; i < size; ++i) {
        if ( ( pattern[i] != 0xff ) && ( pattern[i] != getNthHexChar( opcode, i, size ) ) ) {
            return false;
        }
    }
    std::cout << "Executed" << std::endl;
};

void Opcode::printOpcodes() {
    for( auto i = opcodes.begin(); i != opcodes.end(); ++i ) {
        for( int j = 0; j < (*i)->size; ++j) {
            std::cout << (int)(*i)->pattern[j] << " ";
        }
        std::cout << std::endl;
    }
}

uint32_t Opcode::getNthHexChar( uint32_t subject, uint8_t index, size_t size ) {
    return ( subject >> ( ( size - 1 - index ) * 4 ) & 0x000f );
};
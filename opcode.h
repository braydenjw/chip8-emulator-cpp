//
// Created by willenborg on 11/08/16.
//

#ifndef CHIP8_EMULATOR_OPCODE_H
#define CHIP8_EMULATOR_OPCODE_H

#include <vector>
#include <iostream>

class Opcode {
public:
    static const Opcode OP_0NNN;
    static const Opcode OP_00E0;
    static const Opcode OP_00EE;
    static const Opcode OP_1NNN;
    static const Opcode OP_2NNN;
    static const Opcode OP_3XNN;
    static const Opcode OP_4XNN;
    static const Opcode OP_5XY0;
    static const Opcode OP_6XNN;
    static const Opcode OP_7XNN;
    static const Opcode OP_8XY0;
    static const Opcode OP_8XY1;
    static const Opcode OP_8XY2;
    static const Opcode OP_8XY3;
    static const Opcode OP_8XY4;
    static const Opcode OP_8XY5;
    static const Opcode OP_8XY6;
    static const Opcode OP_8XY7;
    static const Opcode OP_8XYE;
    static const Opcode OP_9XY0;
    static const Opcode OP_ANNN;
    static const Opcode OP_BNNN;
    static const Opcode OP_CXNN;
    static const Opcode OP_DXYN;
    static const Opcode OP_EX9E;
    static const Opcode OP_EXA1;
    static const Opcode OP_FX07;
    static const Opcode OP_FX0A;
    static const Opcode OP_FX15;
    static const Opcode OP_FX18;
    static const Opcode OP_FX1E;
    static const Opcode OP_FX29;
    static const Opcode OP_FX33;
    static const Opcode OP_FX55;
    static const Opcode OP_FX65;

private:
    static std::vector<Opcode*> opcodes;
    unsigned char* pattern;
    size_t size;

private:
    Opcode( uint8_t *, std::size_t );

public:
    bool executeIfMatch( const uint16_t ) const;
    static void printOpcodes();
    static uint32_t getNthHexChar( uint32_t , uint8_t, size_t );

};

#endif //CHIP8_EMULATOR_OPCODE_H

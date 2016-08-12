//
// Created by willenborg on 12/08/16.
//

#ifndef CHIP8_EMULATOR_ROM_H
#define CHIP8_EMULATOR_ROM_H

#include <iostream>
#include <fstream>

class Rom {

private:
    char * buffer;
    long length;

public:
    Rom( std::string path );
    ~Rom( );
    static long getIfStreamSize( std::ifstream * );
    long getByteSize( ) const;
    char getByte( long index ) const;
    uint16_t getHalfWord( long index ) const;
};


#endif //CHIP8_EMULATOR_ROM_H

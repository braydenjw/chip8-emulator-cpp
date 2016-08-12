//
// Created by willenborg on 12/08/16.
//

#include "rom.h"

Rom::Rom( std::string path ) {
    std::ifstream is ( path, std::ifstream::binary );
    if (is) {
        length = getIfStreamSize( & is );
        buffer = new char[length];
        is.read ( buffer, length );
        if ( !is ) std::cout << "Error: only " << is.gcount() << " could be read.";
        is.close();
    }
}

Rom::~Rom() {
    delete[] buffer;
}

long Rom::getIfStreamSize( std::ifstream* is ) {
    long currentPos = is->tellg();
    is->seekg ( 0, is->end );
    long length = is->tellg() ;
    is->seekg ( currentPos, is->beg );
    return length;
}

long Rom::getByteSize( ) const {
    return length;
}

char Rom::getByte( long index ) const {
    return buffer[ index ];
}

uint16_t Rom::getHalfWord( long index ) const {
    return ( ( uint16_t(buffer[index * 2] ) << 8 ) + buffer[index * 2 + 1] );
}
#pragma once

#include <memory>

class LFSR
{
public:
    
    unsigned * reg ;
    
    void Init( unsigned * p_block ) ;
    //void Shift() ;
    void Shift64() noexcept ; // shift 8-byte block
    void Shift128() noexcept ; // shift 16-byte block

};


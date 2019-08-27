#include "LFSR.h"

void LFSR::Init( unsigned * p_block )
{
    reg = p_block ;
}

/*
void LFSR::Shift()
{
    // 8-bit
    //unsigned mask = 0xb8 ; // 10111000
    // reversed 00011101 0x1d
    if ( reg[0] & 0x00000001 )
    {
        reg[0] ^= 0x1d ;
        reg[0] >>= 1 ;
        reg[0] |= 0x80 ;
    }
    else
        reg[0] >>= 1 ;
}
*/



void LFSR::Shift64() noexcept
{
    // 64-bit
    //mask  1101 1000 00000000...
    // reversed 0001 1011 0x1b
    if ( reg[0] & 0x00000001 )
    {
        reg[0] ^= 0x1b ; // - that is right
        //shift :
        bool low_bit = reg[1] &  1 ;// 0x80000000 ;
        reg[1] >>= 1 ;

        reg[0] >>= 1 ;
        if ( low_bit )
            reg[0] |= 0x80000000 ;
        //end of shift
        reg[1] |= 0x80000000 ;
    }
    else
    {
        //shift :
        bool low_bit = reg[1] &  1 ;// 0x80000000 ;
        reg[1] >>= 1 ;

        reg[0] >>= 1 ;
        if ( low_bit )
            reg[0] |= 0x80000000 ;
        //end of shift
    }
}
/*
void LFSR::Shift128() noexcept
{
    // 64-bit
    //mask  1110 0001 00000000...
    // reversed 0001 1011 0x1b
    if ( reg[0] & 0x00000001 )
    {
        reg[0] ^= 0x1b ;
        
        //shift :
        bool low_bit = reg[1] &  1 ;// 0x80000000 ;
        reg[1] >>= 1 ;

        reg[0] >>= 1 ;
        if ( low_bit )
            reg[0] |= 0x80000000 ;
        //end of shift
        
        reg[1] |= 0x80000000 ;
    }
    else
    {
        //shift :
        bool low_bit = reg[1] &  1 ;// 0x80000000 ;
        reg[1] >>= 1 ;

        reg[0] >>= 1 ;
        if ( low_bit )
            reg[0] |= 0x80000000 ;
        //end of shift
    }
}

*/
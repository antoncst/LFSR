#include <iostream>
#include "LFSR.h"
#include <memory>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    std::cout << "LFSR 64 bit. All numbers are HEX " << std::hex << std::endl ;
    
    auto p_block = std::make_unique< unsigned [] > ( 4 ) ;
    
    std::vector< uint64_t > vec64 ;
    
    p_block[3] = 0 ;
    p_block[2] = 0 ;
    p_block[1] = 0 ;
    p_block[0] = 1 ;
    
    LFSR lfsr ;
    lfsr.Init( p_block.get() ) ;

    for (unsigned i = 0 ; i < 0xffffffff ; i++ )
    {
        std::cout << " working.  i: "<< std::hex << uint64_t(i) * 0x400 << "  block: " << p_block[0] << " " << p_block[1]  << " "
                /*<< p_block[2] << " " << p_block[3] */<< std::endl ;
        for (unsigned j = 0 ; j < 0x400 ; j++ )
        {
            uint64_t val = ( uint64_t( p_block[1] ) << 32 ) + p_block[0] ;
            vec64.push_back( val ) ;
            
            //std::cout << std::hex << p_block[0]  << " " << p_block[1] << "    ";
            //std::cout.flush() ; //for debugging

            lfsr.Shift64() ;
            val = ( uint64_t( p_block[1] ) << 32 ) + p_block[0] ;
            if ( std::find( std::begin(vec64) , std::end(vec64) , val ) != std::end(vec64)  )
            {
                std::cout << "\nRepeat i: " << uint64_t(i) * 0x400 + j + 1 
                    << ", value: " << val << std::endl ;
                return 1 ;
            }
            /*if ( p_block[1]==0 && p_block[0] == 1 )
            {
                std::cout << " repeat i: " << i << " j: " << j << std::endl ;
                return 1 ;
            }*/
        }
    }
    
	return 0;
}

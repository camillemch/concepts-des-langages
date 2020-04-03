//
//  main.cpp
//  exercice3
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <iostream>
#include <limits>

#include "class.hpp"
#include "gtest/gtest.h"

int main()
{
    Integer n( -3 );
    std::cout << "n = " << n << "\n";
    
    Double d( 7.8 );
    std::cout << "d = " << d << "\n";
    
    while( true ) {
        std::cout << "Exit with CTRL-C\n";
        Number const * n = nullptr;
        double val = 0;
        std::cin >> val;
        if( ! std::cin.fail() ) {
            if( val - int( val ) == 0 ) {
                n = new Integer( int( val ));
                std::cout << "Integer : ";
            }
            else {
                n = new Double( val );
                std::cout << "Double : ";
            }
            std::cout << *n << "\n";
            if( n->intValue() != int( val )) {
                std::cout << "intValue() is wrong\n";
            }
            if( n->doubleValue() != val ) {
                std::cout << "doubleValue() is wrong\n";
            }
            delete n;
        }
        else {
            std::cout << "Invalid input\n";
            std::cin.clear();
        }
        // Ignorer le reste de la ligne
        std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );
        ::testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
}

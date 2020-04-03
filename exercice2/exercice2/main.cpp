//
//  main.cpp
//  exercice2
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <iostream>
#include <cctype>

#include "chiffre.hpp"
#include "gtest/gtest.h"

using namespace std;

int main( int argc, char * argv[] )
{
    while( true ) {
        Nombre n = lecture_nombre( std::cin );
        if( n != nullptr ) {
            std::cout << "lu : ";
            affiche_nombre( n, std::cout );
            std::cout << "\n";
            detruit_nombre( n );
        }
        else break;
    }
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

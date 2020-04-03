//
//  TestChiffre.cpp
//  exercice2
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "chiffre.hpp"
#include "gtest/gtest.h"

TEST( TestNombreV1, TestNombreVide )
{
    std::istringstream is1;
    Nombre n = lecture_nombre( is1 );
    EXPECT_EQ( nullptr, n );
    std::ostringstream os;
    affiche_nombre( n, os );
    EXPECT_EQ( "", os.str() );
    detruit_nombre( n );
    
    std::istringstream is2( "a" );
    n = lecture_nombre( is2 );
    EXPECT_EQ( nullptr, n );
    affiche_nombre( n, os );
    EXPECT_EQ( "", os.str() );
    detruit_nombre( n );
}

TEST( TestNombreV1, TestPoidsFaible )
{
    std::string test( "327" );
    std::istringstream is( test );
    Nombre n = lecture_nombre( is );
    EXPECT_NE( nullptr, n );
    EXPECT_EQ( n->chiffre_, 7 );
    detruit_nombre( n );
}

TEST( TestNombreV1, TestGrandNombre )
{
    std::string test( "123456789123456789123456789123456789" );
    std::istringstream is( test );
    Nombre n = lecture_nombre( is );
    EXPECT_NE( nullptr, n );
    std::ostringstream os;
    affiche_nombre( n, os );
    EXPECT_EQ( test, os.str() );
    detruit_nombre( n );
}

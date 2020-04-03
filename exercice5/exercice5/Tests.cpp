//
//  Tests.cpp
//  exercice5
//
//  Created by Camille Michel on 21/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <stdio.h>
#include <utility>

#include "gtest/gtest.h"
#include "Nombre.hpp"


TEST( TestNombrePerso, TestNombreVide )
{
    Nombre * n = new Nombre("");
    std::ostringstream os, os2;
    os << *n;
    EXPECT_EQ( "", os.str() );
    delete n;
    n = new Nombre("a");
    os2 << *n;
    EXPECT_EQ( "", os2.str() );
    delete n;
}

TEST( TestNombrePerso, TestPoidsFaible )
{
    Nombre * n = new Nombre("321");
    EXPECT_NE( nullptr, n );
    EXPECT_EQ( 1, n->getValuePremier() );
    delete n ;
}

TEST( TestNombrePerso, TestPoidsFaibleInt )
{
    Nombre * n = new Nombre(321);
    EXPECT_NE( nullptr, n );
    EXPECT_EQ( 1, n->getValuePremier() );
    delete n ;
}

TEST( TestNombrePerso, TestGrandNombre )
{
    std::string test( "123456789123456789123456789123456789" );
    Nombre * n = new Nombre( "123456789123456789123456789123456789" );
    EXPECT_NE( nullptr, n );
    std::ostringstream os, os2;
    os << *n;
    EXPECT_EQ( test, os.str() );
    delete n;
    test = "1234567891" ;
    n = new Nombre(1234567891);
    EXPECT_NE( nullptr, n );
    os2 << *n;
    EXPECT_EQ( test, os2.str() );
    delete n;
}

TEST( TestNombrePerso, TestCopyConstructeur )
{
    Nombre n( "123" );
    Nombre n2 = n;
    std::ostringstream os, os2;
    os << n;
    os2 << n2;
    EXPECT_EQ(os.str(), os2.str());
}

TEST( TestNombrePerso, TestCopyAffectation )
{
    Nombre n2(0);
    Nombre n( "123" );
    n2 = n;
    std::ostringstream os, os2;
    os << n;
    os2 << n2;
    EXPECT_EQ(os.str(), os2.str());
}

//TEST( TestNombrePerso, TestDeplacementConstructeur )
//{
//    std::string test( "123" );
//    Nombre n( test );
//    Nombre n2 = std::move(n);
//    std::ostringstream os, os2;
//    os << n;
//    os2 << n2;
//    EXPECT_EQ( "", os.str() );
//    EXPECT_EQ( test, os2.str());
//}
//
//TEST( TestNombrePerso, TestDeplacementAffectation )
//{
//    std::string test( "123" );
//    Nombre n( test );
//    Nombre n2(0);
//    n2 = std::move(n);
//    std::ostringstream os, os2;
//    os << n;
//    os2 << n2;
//    EXPECT_EQ( "", os.str() );
//    EXPECT_EQ( test, os2.str());
//}

TEST( TestNombre, TestMoveConstructor )
{
    Nombre n1( "12345123451234512345" );
    Nombre n2( std::move( n1 ));
    std::ostringstream os1;
    os1 << n1;
    // n1 is in a valid but unspecified state: it can be printed but the result is unspecified
    //EXPECT_EQ( "", os1.str() );
    std::ostringstream os2;
    os2 << n2;
    EXPECT_EQ( "12345123451234512345", os2.str() );
}

TEST( TestNombre, TestMoveAssignment )
{
    Nombre n1( "11111111111111111111" );
    Nombre n2( "22222222222222222222" );
    n2 = std::move( n1 );
    std::ostringstream os1;
    os1 << n1;
    // n1 is in a valid but unspecified state: it can be printed but the result is unspecified
//    EXPECT_EQ( "", os1.str() );
    std::ostringstream os2;
    os2 << n2;
    EXPECT_EQ( "11111111111111111111", os2.str() );
}

TEST( TestNombre, TestSwap )
{
    Nombre n1( "12345123451234512345" );
    Nombre n2( "67890678906789067890" );
    std::swap( n1, n2 );
    std::ostringstream os1;
    os1 << n1;
    EXPECT_EQ( "67890678906789067890", os1.str() );
    std::ostringstream os2;
    os2 << n2;
    EXPECT_EQ( "12345123451234512345", os2.str() );
}

TEST( TestNombrePerso, TestDeleteInstances )
{
    EXPECT_EQ( 0, Nombre::nb_instances());
}

TEST( TestNombre, TestAddition )
{
    Nombre n1( "123456" );
    Nombre n2 = n1 + 2345;
    std::ostringstream os;
    os << n2;
    EXPECT_EQ( "125801", os.str() );
}

TEST( TestNombre, TestFactorielle123 )
{
    std::ostringstream os;
    os << factorielle( 123 );;
    EXPECT_EQ( "12146304367025329675766243241881295855454217088483382315328918161829235892362167668831156960612640202170735835221294047782591091570411651472186029519906261646730733907419814952960000000000000000000000000000", os.str() );
}

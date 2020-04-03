//
//  Tests.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Expression.hpp"
#include "Nombre.hpp"
#include "Variable.hpp"
#include "Operation.hpp"
#include "SousOperation.hpp"

#include "gtest/gtest.h"

//TEST( TestDerivation, TestAffichageNombre )
//{
//    Nombre n( 2 );
//    std::ostringstream os;
//    os << n;
//    EXPECT_EQ( "2", os.str() );
//}
//
//TEST( TestDerivation, TestAffichageVariable )
//{
//    Expression * e = new Variable( 'x' );
//    std::ostringstream os;
//    os << *e;
//    EXPECT_EQ( "x", os.str() );
//    delete e;
//}
//
//TEST( TestDerivation, TestDerivationNombre )
//{
//    Expression * e = new Nombre( -2 );
//    Expression * f = e->derive( 'x' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os;
//    os << *f;
//    EXPECT_EQ( "0", os.str() );
//    delete e;
//    delete f;
//}
//
//TEST( TestDerivation, TestDerivationVariable )
//{
//    Expression * e = new Variable( 'x' );
//    Expression * f = e->derive( 'x' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os1;
//    os1 << *f;
//    EXPECT_EQ( "1", os1.str() );
//    delete f;
//
//    f = e->derive( 'y' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os2;
//    os2 << *f;
//    EXPECT_EQ( "0", os2.str() );
//    delete e;
//    delete f;
//}
//
//
//
//TEST( TestDerivation, TestAffichageAddition )
//{
//    Expression * e = new Addition( new Variable( 'x' ), new Nombre( -2 ));
//    std::ostringstream os;
//    os << *e;
//    EXPECT_EQ( "(x + -2)", os.str() );
//    delete e;
//}
//
//TEST( TestDerivation, TestDerivationAddition )
//{
//    Expression * e = new Addition( new Variable( 'x' ), new Nombre( -10 ));
//    Expression * f = e->derive( 'x' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os;
//    os << *f;
//    EXPECT_EQ( "(1 + 0)", os.str() );
//    delete e;
//    delete f;
//}
//
//TEST( TestDerivation, TestAffichageSoustraction )
//{
//    Expression * e = new Soustraction( new Variable( 'y' ), new Nombre( 3.14 ));
//    std::ostringstream os;
//    os << *e;
//    EXPECT_EQ( "(y - 3.14)", os.str() );
//    delete e;
//}
//
//TEST( TestDerivation, TestDerivationSoustraction )
//{
//    Expression * e = new Soustraction( new Nombre( 2 ), new Variable( 'x' ));
//    Expression * f = e->derive( 'x' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os;
//    os << *f;
//    EXPECT_EQ( "(0 - 1)", os.str() );
//    delete e;
//    delete f;
//}
//
//TEST( TestDerivation, TestAffichageMultiplication )
//{
//    Expression * e = new Multiplication( new Variable( 'y' ), new Variable( 'z' ));
//    std::ostringstream os;
//    os << *e;
//    EXPECT_EQ( "(y * z)", os.str() );
//    delete e;
//}
//
//TEST( TestDerivation, TestDerivationMultiplication )
//{
//    // This test expects (f * g)' = f' * g + f * g'
//    Expression * e = new Multiplication(
//                                        new Variable( 'x' ),
//                                        new Multiplication( new Variable( 'y' ), new Variable( 'z' )));
////    Expression * e = new Multiplication(
////                                        new Variable( 'x' ),
////                                        new Variable( 'y' ));
//
//    Expression * f = e->derive( 'x' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os;
//    os << *f;
//    EXPECT_EQ( "((1 * (y * z)) + (x * ((0 * z) + (y * 0))))", os.str() );
////    EXPECT_EQ( "((1 * y) + (x * 0))", os.str() );
//    delete e;
//    delete f;
//}
//
//TEST( TestDerivation, TestAffichageDivision )
//{
//    Expression * e = new Division( new Variable( 't' ), new Nombre( -222 ));
//    std::ostringstream os;
//    os << *e;
//    EXPECT_EQ( "(t / -222)", os.str() );
//    delete e;
//}
//
//TEST( TestDerivation, TestDerivationDivision )
//{
//    Expression * e = new Division( new Variable( 'y' ), new Variable( 'z' ));
//    Expression * f = e->derive( 'y' );
//    ASSERT_TRUE( nullptr != f );
//    std::ostringstream os;
//    os << *f;
//    EXPECT_EQ( "(((1 * z) - (y * 0)) / (z * z))", os.str() );
//    delete e;
//    delete f;
//}
//
//TEST( TestDerivation, TestSimplificationAddition )
//{
//    Expression * e = new Addition( new Variable( 'x' ), new Nombre( 0 ));
//    Expression * es = e->simplification();
//    Expression * f = new Addition( new Nombre( 5 ), new Nombre( 4 ));
//    Expression * fs = f->simplification();
//    Expression * g = new Addition( new Nombre( 0 ), new Variable( 'y' ));
//    Expression * gs = g->simplification();
//    std::ostringstream os;
//    os << *es;
//    std::ostringstream os1;
//    os1 << *fs;
//    std::ostringstream os2;
//    os2 << *gs;
//    EXPECT_EQ( "x", os.str() );
//    EXPECT_EQ( "9", os1.str() );
//    EXPECT_EQ( "y", os2.str() );
//    delete e;
//    delete es;
//    delete f;
//    delete fs;
//    delete g;
//    delete gs;
//}
//
//TEST( TestDerivation, TestSimplificationSoustraction )
//{
//    Expression * e = new Soustraction( new Variable( 'x' ), new Nombre( 0 ));
//    Expression * es = e->simplification();
//    Expression * f = new Soustraction( new Nombre( 4 ), new Nombre( 4 ));
//    Expression * fs = f->simplification();
//    Expression * g = new Soustraction( new Nombre( 0 ), new Variable( 'y' ));
//    Expression * gs = g->simplification();
//    std::ostringstream os;
//    os << *es;
//    std::ostringstream os1;
//    os1 << *fs;
//    std::ostringstream os2;
//    os2 << *gs;
//    EXPECT_EQ( "x", os.str() );
//    EXPECT_EQ( "0", os1.str() );
//    EXPECT_EQ( "(0 - y)", os2.str() );
//    delete e;
//    delete es;
//    delete f;
//    delete fs;
//    delete g;
//    delete gs;
//}
//
//
//TEST( TestDerivation, TestSimplificationMultiplication )
//{
//    Expression * e = new Multiplication( new Variable( 'x' ), new Nombre( 0 ));
//    Expression * es = e->simplification();
//    Expression * f = new Multiplication( new Nombre( 4 ), new Nombre( 4 ));
//    Expression * fs = f->simplification();
//    Expression * g = new Multiplication( new Nombre( 1 ), new Variable( 'x' ));
//    Expression * gs = g->simplification();
//    std::ostringstream os;
//    os << *es;
//    std::ostringstream os1;
//    os1 << *fs;
//    std::ostringstream os2;
//    os2 << *gs;
//    EXPECT_EQ( "0", os.str() );
//    EXPECT_EQ( "16", os1.str() );
//    EXPECT_EQ( "x", os2.str() );
//    delete e;
//    delete es;
//    delete f;
//    delete fs;
//    delete g;
//    delete gs;
//}
//
//TEST( TestDerivation, TestSimplificationDivision )
//{
//    Expression * e = new Division( new Nombre( 0 ), new Variable( 'x' ));
//    Expression * es = e->simplification();
//    Expression * f = new Division( new Nombre( 8 ), new Nombre( 4 ));
//    Expression * fs = f->simplification();
//    std::ostringstream os;
//    os << *es;
//    std::ostringstream os1;
//    os1 << *fs;
//    EXPECT_EQ( "0", os.str() );
//    EXPECT_EQ( "2", os1.str() );
//    delete e;
//    delete es;
//    delete f;
//    delete fs;
//}

TEST( TestDerivation, TestSimplificationMultiples )
{
    Expression * e = new Multiplication(
                                        new Variable( 'x' ),
                                        new Multiplication(
                                                           new Soustraction(new Nombre (4), new Nombre(2)),
                                                           new Division(
                                                                        new Addition(new Nombre(2), new Nombre(2)),
                                                                        new Nombre(2)
                                                                        )
                                                           )
                                        );
    auto f = e->derive('x');
    Expression * fs = f->simplification();
    std::ostringstream os;
    os << *fs;
    EXPECT_EQ( "4", os.str() );
    delete e;
    delete f;
    delete fs;
}

TEST( TestDerivation, TestDeleteInstances )
{
    std::cout << "Le nombre d'instances crées est:  " << Expression::nb_instances_total() << std::endl;
    EXPECT_EQ( 0, Expression::nb_instances_restant());
}

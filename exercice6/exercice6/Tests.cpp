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

using namespace std;

TEST( TestExercice6, TestAffichageNombre )
{
    Nombre n( 2 );
    ostringstream os;
    os << n;
    EXPECT_EQ( "2", os.str() );
}

TEST( TestExercice6, TestAffichageVariable )
{
    auto e = make_shared<Variable>('x');
    // ou
    //shared_ptr<Expression> e(new Variable( 'x' ));
    // Mieux car make_shared est protégé contre les exceptions
    ostringstream os;
    os << *e;
    EXPECT_EQ( "x", os.str() );
}

TEST( TestExercice6, TestDerivationNombre )
{
    auto e = make_shared<Nombre>( -2 );
    auto f = e->derive( 'x' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os;
    os << *f;
    EXPECT_EQ( "0", os.str() );
}

TEST( TestExercice6, TestDerivationVariable )
{
    auto e = make_shared<Variable>('x');
    auto f = e->derive( 'x' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os1;
    os1 << *f;
    EXPECT_EQ( "1", os1.str() );
    f = e->derive( 'y' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os2;
    os2 << *f;
    EXPECT_EQ( "0", os2.str() );
}

TEST( TestExercice6, TestAffichageAddition )
{
    auto e = make_shared<Addition>(make_shared<Variable>('x'), make_shared<Nombre>( -2 ));
    ostringstream os;
    os << *e;
    EXPECT_EQ( "(x + -2)", os.str() );
}

TEST( TestExercice6, TestDerivationAddition )
{
    auto e = make_shared<Addition>(make_shared<Variable>('x'), make_shared<Nombre>( -10 ));
    auto f = e->derive( 'x' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os;
    os << *f;
    EXPECT_EQ( "(1 + 0)", os.str() );
}

TEST( TestExercice6, TestAffichageSoustraction )
{
    auto e = make_shared<Soustraction>(make_shared<Variable>('y'), make_shared<Nombre>( 3.14 ));
    ostringstream os;
    os << *e;
    EXPECT_EQ( "(y - 3.14)", os.str() );
}

TEST( TestExercice6, TestDerivationSoustraction )
{
    auto e = make_shared<Soustraction>(make_shared<Nombre>( 2 ), make_shared<Variable>( 'x' ));
    auto f = e->derive( 'x' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os;
    os << *f;
    EXPECT_EQ( "(0 - 1)", os.str() );
}

TEST( TestExercice6, TestAffichageMultiplication )
{
    auto e = make_shared<Multiplication>(make_shared<Variable>('y'), make_shared<Variable>('z'));
    ostringstream os;
    os << *e;
    EXPECT_EQ( "(y * z)", os.str() );
}

// Commentez le reste pour faire le test avec l'exercice 4

TEST( TestExercice6, TestDerivationMultiplication )
{
    // This test expects (f * g)' = f' * g + f * g'
    auto e = make_shared<Multiplication>(
                                         make_shared<Variable>('x'),
                                         make_shared<Multiplication>(make_shared<Variable>('y'), make_shared<Variable>('z'))
                                         );
    auto f = e->derive( 'x' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os;
    os << *f;
    EXPECT_EQ( "((1 * (y * z)) + (x * ((0 * z) + (y * 0))))", os.str() );
}

TEST( TestExercice6, TestAffichageDivision )
{
    auto e = make_shared<Division>(make_shared<Variable>('t'), make_shared<Nombre>(-222));
    ostringstream os;
    os << *e;
    EXPECT_EQ( "(t / -222)", os.str() );
}

TEST( TestExercice6, TestDerivationDivision )
{
    auto e = make_shared<Division>(make_shared<Variable>('y'), make_shared<Variable>('z'));
    auto f = e->derive( 'y' );
    ASSERT_TRUE( nullptr != f );
    ostringstream os;
    os << *f;
    EXPECT_EQ( "(((1 * z) - (y * 0)) / (z * z))", os.str() );
}

TEST( TestExercice6, TestSimplificationAddition )
{
    auto e = make_shared<Addition>(make_shared<Variable>('x'), make_shared<Nombre>( 0 ));
    auto es = e->simplification();

    auto f = make_shared<Addition>(make_shared<Nombre>( 5 ), make_shared<Nombre>( 4 ));
    auto fs = f->simplification();

    auto g = make_shared<Addition>(make_shared<Nombre>(0), make_shared<Variable>( 'y' ));
    auto gs = g->simplification();

    ostringstream os;
    os << *es;
    ostringstream os1;
    os1 << *fs;
    ostringstream os2;
    os2 << *gs;
    EXPECT_EQ( "x", os.str() );
    EXPECT_EQ( "9", os1.str() );
    EXPECT_EQ( "y", os2.str() );
}

TEST( TestExercice6, TestSimplificationSoustraction )
{
    shared_ptr<Expression> e(new Soustraction(
                                                   shared_ptr<Expression>(new Variable( 'x' )),
                                                   shared_ptr<Expression>(new Nombre( 0 ))
                                                   )
                                  );
    shared_ptr<Expression> es = e->simplification();
    shared_ptr<Expression> f(new Soustraction(
                                                   shared_ptr<Expression>(new Nombre( 4 )),
                                                   shared_ptr<Expression>(new Nombre( 4 ))
                                                   )
                                  );
    shared_ptr<Expression> fs = f->simplification();
    shared_ptr<Expression> g(new Soustraction(
                                                   shared_ptr<Expression>(new Nombre( 0 )),
                                                   shared_ptr<Expression>(new Variable( 'y' ))
                                                   )
                                  );
    shared_ptr<Expression> gs = g->simplification();
    ostringstream os;
    os << *es;
    ostringstream os1;
    os1 << *fs;
    ostringstream os2;
    os2 << *gs;
    EXPECT_EQ( "x", os.str() );
    EXPECT_EQ( "0", os1.str() );
    EXPECT_EQ( "(0 - y)", os2.str() );
}


TEST( TestExercice6, TestSimplificationMultiplication )
{
    shared_ptr<Expression> e(new Multiplication(
                                                     shared_ptr<Expression>(new Variable( 'x' )),
                                                     shared_ptr<Expression>(new Nombre( 0 ))
                                                     )
                                  );
    shared_ptr<Expression> es = e->simplification();
    shared_ptr<Expression> f(new Multiplication(
                                                     shared_ptr<Expression>(new Nombre( 4 )),
                                                     shared_ptr<Expression>(new Nombre( 4 ))
                                                     )
                                  );
    shared_ptr<Expression> fs = f->simplification();
    shared_ptr<Expression> g(new Multiplication(
                                                     shared_ptr<Expression>(new Nombre( 1 )),
                                                     shared_ptr<Expression>(new Variable( 'x' ))
                                                     )
                                  );
    shared_ptr<Expression> gs = g->simplification();
    ostringstream os;
    os << *es;
    ostringstream os1;
    os1 << *fs;
    ostringstream os2;
    os2 << *gs;
    EXPECT_EQ( "0", os.str() );
    EXPECT_EQ( "16", os1.str() );
    EXPECT_EQ( "x", os2.str() );
}

TEST( TestExercice6, TestSimplificationDivision )
{
    shared_ptr<Expression> e(new Division(
                                               shared_ptr<Expression>(new Nombre( 0 )),
                                               shared_ptr<Expression>(new Variable( 'x' ))
                                               )
                                  );
    shared_ptr<Expression> es = e->simplification();
    shared_ptr<Expression> f(new Division(
                                               shared_ptr<Expression>(new Nombre( 8 )),
                                               shared_ptr<Expression>(new Nombre( 4 ))
                                               )
                                  );
    shared_ptr<Expression> fs = f->simplification();
    ostringstream os;
    os << *es;
    ostringstream os1;
    os1 << *fs;
    EXPECT_EQ( "0", os.str() );
    EXPECT_EQ( "2", os1.str() );
}

TEST( TestExercice6, TestSimplificationMultiples )
{
    shared_ptr<Expression> e(new Multiplication(
                                        shared_ptr<Expression>(new Variable( 'x' )),
                                        shared_ptr<Expression>(new Multiplication(
                                                           shared_ptr<Expression>(new Soustraction(
                                                                                                        shared_ptr<Expression>(new Nombre (4)),
                                                                                                        shared_ptr<Expression>(new Nombre(2)))),
                                                           shared_ptr<Expression>(new Division(
                                                                        shared_ptr<Expression>(new Addition(
                                                                                                                 shared_ptr<Expression>(new Nombre(2)),
                                                                                                                 shared_ptr<Expression>(new Nombre(2)))),
                                                                        shared_ptr<Expression>(new Nombre(2))
                                                                        ))
                                                           )
                                        )));
    auto f = e->derive('x');
    shared_ptr<Expression> fs = f->simplification();
    ostringstream os;
    os << *fs;
    EXPECT_EQ( "4", os.str() );}

TEST( TestExercice6, TestDeleteInstances )
{
    cout << "Le nombre d'instances crées est:  " << Expression::nb_instances_total() << endl;
    EXPECT_EQ( 2, Expression::nb_instances_restant());
}

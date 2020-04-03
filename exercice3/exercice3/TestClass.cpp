//
//  TestClass.cpp
//  exercice3
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "class.hpp"

TEST( TestNumber, TestInteger )
{
    const int test = 56;
    Number * const n = new Integer( test );
    EXPECT_EQ( int(    test ), n->intValue()    );
    EXPECT_EQ( double( test ), n->doubleValue() );
    std::ostringstream os1;
    os1 << test;
    std::ostringstream os2;
    os2 << *n;
    EXPECT_EQ( os1.str(), os2.str() );
    delete n;
}

TEST( TestNumber, TestDouble )
{
    const double test = -3.14159;
    Number const * n = new Double( test );
    EXPECT_EQ( int(    test ), n->intValue()    );
    EXPECT_EQ( double( test ), n->doubleValue() );
    std::ostringstream os1;
    os1 << test;
    std::ostringstream os2;
    os2 << *n;
    EXPECT_EQ( os1.str(), os2.str() );
    delete n;
}

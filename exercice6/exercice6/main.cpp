//
//  main.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <iostream>
#include <cctype>

#include "Expression.hpp"
#include "Nombre.hpp"
#include "Variable.hpp"
#include "Operation.hpp"
#include "SousOperation.hpp"

#include "gtest/gtest.h"

using namespace std;

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

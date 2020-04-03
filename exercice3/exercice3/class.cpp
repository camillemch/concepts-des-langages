//
//  class.cpp
//  exercice3
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#include "class.hpp"

//Integer
Integer::Integer(int value){
    intValue_ = value;
}

int Integer::intValue() const {
    return intValue_;
}

double Integer::doubleValue() const {
    return static_cast< double >( intValue_ );
}

//Double
Double::Double(double value){
    doubleValue_ = value;
}

double Double::doubleValue() const {
    return doubleValue_;
}

int Double::intValue() const {
    return static_cast< int >( doubleValue_ );
}

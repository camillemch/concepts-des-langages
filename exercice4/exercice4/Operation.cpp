//
//  Operation.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Operation.hpp"

Operation::Operation(Expression * opLeft, Expression * opRight){
    opRight_ = opRight;
    opLeft_ = opLeft;
}

Operation::~Operation(){
    delete opLeft_;
    delete opRight_;
}

void Operation::affiche(std::ostream & out) const{
    out << '(' << *opLeft_ << ' ' << symbol() << ' ' << *opRight_ << ')';
};

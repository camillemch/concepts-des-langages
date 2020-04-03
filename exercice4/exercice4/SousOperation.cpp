//
//  Addition.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "SousOperation.hpp"
#include "Nombre.hpp"

// Addition
Expression * Addition::clone() const {
    return new Addition(opLeft_->clone(), opRight_->clone());
}

Expression * Addition::derive(char v) const {
    Expression * e = new Addition( opLeft_->derive(v) , opRight_->derive(v) );
    return e ;
}

char Addition::symbol() const {
    return '+';
}

Expression * Addition::simplification() const {
    Expression * left = opLeft_->simplification();
    Expression * right = opRight_->simplification();
    auto nleft = dynamic_cast<Nombre *>(left);
    auto nright = dynamic_cast<Nombre *>(right);
    if (nleft and nright){
        Expression * e = new Nombre(nleft->getValue() + nright->getValue());
        delete left;
        delete right;
        return e;
    }
    else if (nleft and nleft->getValue() == 0){
        delete left;
        return right;
        
    }
    else if (nright and nright->getValue() == 0){
        delete right;
        return left;
    }
    return new Addition(left, right);
}

// Soustraction
Expression * Soustraction::clone() const {
    return new Soustraction(opLeft_->clone(), opRight_->clone());
}

Expression * Soustraction::derive(char v) const {
    Expression * e = new Soustraction( opLeft_->derive(v) , opRight_->derive(v) );
    return e ;
}

char Soustraction::symbol() const {
    return '-';
}

Expression * Soustraction::simplification() const {
    Expression * left = opLeft_->simplification();
    Expression * right = opRight_->simplification();
    auto nleft = dynamic_cast<Nombre *>(left);
    auto nright = dynamic_cast<Nombre *>(right);
    if (nleft and nright){
        Expression * e = new Nombre(nleft->getValue() - nright->getValue());
        delete left;
        delete right;
        return e;
    }
    else if (nright and nright->getValue() == 0){
        delete right;
        return left;
    }
    return new Soustraction(left, right);
}


// Multiplication
Expression * Multiplication::clone() const {
    return new Multiplication(opLeft_->clone(), opRight_->clone());
}

Expression * Multiplication::derive(char v) const {
    Expression * f = new Addition(
                              new Multiplication(opLeft_->derive(v), opRight_->clone()),
                              new Multiplication(opLeft_->clone(), opRight_->derive(v)));
    return f ;
}

char Multiplication::symbol() const {
    return '*';
}

Expression * Multiplication::simplification() const {
    Expression * left = opLeft_->simplification();
    Expression * right = opRight_->simplification();
    auto nleft = dynamic_cast<Nombre *>(left);
    auto nright = dynamic_cast<Nombre *>(right);
    if (nleft and nright){
        Expression * e = new Nombre(nleft->getValue() * nright->getValue());
        delete left;
        delete right;
        return e;
    }
    if (nleft){
        if (nleft->getValue() == 0 ){
            delete left;
            delete right;
            return new Nombre(0);
        }
        if (nleft->getValue() == 1){
            delete left;
            return right;
        }
    }
    if (nright){
        if (nright->getValue() == 0 ){
            delete left;
            delete right;
            return new Nombre(0);
        }
        if (nright->getValue() == 1){
            delete right;
            return left;
        }
    }
    return new Multiplication(left, right);
}

// Division
Expression * Division::clone() const {
    return new Division(opLeft_->clone(), opRight_->clone());
}

Expression * Division::derive(char v) const {
    Expression * e = new Division(
                                  new Soustraction(
                                                   new Multiplication(opLeft_->derive(v), opRight_->clone()),
                                                   new Multiplication(opLeft_->clone(), opRight_->derive(v))
                                  ),
                                  new Multiplication(opRight_->clone(), opRight_->clone()));
    return e ;
}

char Division::symbol() const {
    return '/';
}

Expression * Division::simplification() const {
    Expression * left = opLeft_->simplification();
    Expression * right = opRight_->simplification();
    auto nleft = dynamic_cast<Nombre *>(left);
    auto nright = dynamic_cast<Nombre *>(right);
    if (nleft){
        if (nleft->getValue() == 0){
            delete left;
            delete right;
            return new Nombre(0);
        }
    }
    if (nleft and nright and ((int(nleft->getValue()) % int(nright->getValue())) == 0)
        ){
        Expression * e = new Nombre((nleft->getValue()) / (nright->getValue()));
        delete left;
        delete right;
        return e;
    }
    return new Division(left, right);
}

//
//  Addition.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "SousOperation.hpp"
#include "Nombre.hpp"

using namespace std;

shared_ptr<Expression> Addition::DoDerive(char v) const {
    return make_shared<Addition>(opLeft_->derive(v) , opRight_->derive(v) );
}

char Addition::DoSymbol() const {
    return '+';
}

shared_ptr<Expression> Addition::DoSimplification() {
    shared_ptr<Expression> left = opLeft_->simplification();
    shared_ptr<Expression> right = opRight_->simplification();
    auto nleft = dynamic_pointer_cast<Nombre>(left);
    auto nright = dynamic_pointer_cast<Nombre>(right);
    if (nleft and nright){
        shared_ptr<Expression> e(new Nombre(nleft->getValue() + nright->getValue()));
        return e;
    }
    else if (nleft and nleft->getValue() == 0){
        return right;
        
    }
    else if (nright and nright->getValue() == 0){
        return left;
    }
    return shared_ptr<Expression>(new Addition(left, right));
}

shared_ptr<Expression> Soustraction::DoDerive(char v) const {
    return shared_ptr<Expression>(new Soustraction( opLeft_->derive(v) , opRight_->derive(v) ));
}

char Soustraction::DoSymbol() const {
    return '-';
}

shared_ptr<Expression> Soustraction::DoSimplification() {
    shared_ptr<Expression> left = opLeft_->simplification();
    shared_ptr<Expression> right = opRight_->simplification();
    auto nleft = dynamic_pointer_cast<Nombre>(left);
    auto nright = dynamic_pointer_cast<Nombre>(right);
    if (nleft and nright){
        shared_ptr<Expression> e (new Nombre(nleft->getValue() - nright->getValue()));
//        delete left;
//        delete right;
        return e;
    }
    else if (nright and nright->getValue() == 0){
//        delete right;
        return left;
    }
    return shared_ptr<Expression>(new Soustraction(left, right));
}

shared_ptr<Expression> Multiplication::DoDerive(char v) const {
    shared_ptr<Expression> f(new Addition(
                              shared_ptr<Expression>(new Multiplication(opLeft_->derive(v), opRight_)),
                              shared_ptr<Expression>(new Multiplication(opLeft_, opRight_->derive(v)))));
    return f ;
}

char Multiplication::DoSymbol() const {
    return '*';
}

shared_ptr<Expression> Multiplication::DoSimplification() {
    shared_ptr<Expression> left = opLeft_->simplification();
    shared_ptr<Expression> right = opRight_->simplification();
    auto nleft = dynamic_pointer_cast<Nombre>(left);
    auto nright = dynamic_pointer_cast<Nombre>(right);
    if (nleft and nright){
        shared_ptr<Expression> e(new Nombre(nleft->getValue() * nright->getValue()));
//        delete left;
//        delete right;
        return e;
    }
    if (nleft){
        if (nleft->getValue() == 0 ){
//            delete left;
//            delete right;
            return shared_ptr<Expression>(new Nombre(0));
        }
        if (nleft->getValue() == 1){
//            delete left;
            return right;
        }
    }
    if (nright){
        if (nright->getValue() == 0 ){
//            delete left;
//            delete right;
            return shared_ptr<Expression>(new Nombre(0));
        }
        if (nright->getValue() == 1){
//            delete right;
            return left;
        }
    }
    return shared_ptr<Expression>(new Multiplication(left, right));
}

shared_ptr<Expression> Division::DoDerive(char v) const {
    shared_ptr<Expression> e(new Division(
                                  shared_ptr<Expression>(new Soustraction(
                                                   shared_ptr<Expression>(new Multiplication(opLeft_->derive(v), opRight_)),
                                                   shared_ptr<Expression>(new Multiplication(opLeft_, opRight_->derive(v)))
                                  )),
                                  shared_ptr<Expression>(new Multiplication(opRight_, opRight_))));
    return e ;
}

char Division::DoSymbol() const {
    return '/';
}

shared_ptr<Expression> Division::DoSimplification() {
    shared_ptr<Expression> left = opLeft_->simplification();
    shared_ptr<Expression> right = opRight_->simplification();
    auto nleft = dynamic_pointer_cast<Nombre>(left);
    auto nright = dynamic_pointer_cast<Nombre>(right);
    if (nleft){
        if (nleft->getValue() == 0){
//            delete left;
//            delete right;
            return shared_ptr<Expression>(new Nombre(0));
        }
    }
    if (nleft and nright and ((int(nleft->getValue()) % int(nright->getValue())) == 0)
        ){
        shared_ptr<Expression> e(new Nombre((nleft->getValue()) / (nright->getValue())));
//        delete left;
//        delete right;
        return e;
    }
    return shared_ptr<Expression>(new Division(left, right));
}

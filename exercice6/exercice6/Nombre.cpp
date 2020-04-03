//
//  Nombre.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Nombre.hpp"

using namespace std;

auto nombreZero = make_shared<Nombre>(0);
auto nombreUn = make_shared<Nombre>(1);

Nombre::Nombre(double value){
    value_ = value;
}

/**
 * \fn Nombre affiche( ostream & out )
 * \brief Print the number value
 *
 * The out flux is just the double value of the number
 *
 * \param out     output flux
 */
void Nombre::DoAffiche(ostream & out) const{
    out << value_;
};

shared_ptr<Expression> Nombre::DoDerive(char v) const {
    return nombreZero;
}

shared_ptr<Expression> Nombre::DoSimplification() {
    return shared_from_this();
}

double Nombre::getValue() const {
    return value_;
}

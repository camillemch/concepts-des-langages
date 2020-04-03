//
//  Nombre.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Nombre.hpp"

Nombre::Nombre(double value){
    value_ = value;
}

/**
 * \fn Nombre affiche( std::ostream & out )
 * \brief Print the number value
 *
 * The out flux is just the double value of the number
 *
 * \param out     output flux
 */
void Nombre::affiche(std::ostream & out) const{
    out << value_;
};

Expression * Nombre::derive(char v) const {
    Expression * e = new Nombre( 0 );
    return e;
}

Expression * Nombre::clone()  const {
    return new Nombre(this->value_);
}

Expression * Nombre::simplification() const {
    return this->clone();
}


double Nombre::getValue() const {
    return value_;
}

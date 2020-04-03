//
//  Variable.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Variable.hpp"
#include "Nombre.hpp"

Variable::Variable(char nom){
    nom_ = nom;
}

/**
 * \fn Variable affiche( std::ostream & out )
 * \brief Print the variable name
 *
 * The out flux is just the the name of the value
 *
 * \param out     output flux
 */
void Variable::affiche(std::ostream & out) const{
    out << nom_;
};

Expression * Variable::derive(char v) const {
    if (nom_ == v){
        Expression * e = new Nombre( 1 );
        return e;
    }
    Expression * e = new Nombre( 0 );
    return e;
}

Expression * Variable::clone()  const {
    return new Variable(this->nom_);
}

Expression * Variable::simplification() const {
    return this->clone();
}

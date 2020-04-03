//
//  Variable.cpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include "Variable.hpp"
#include "Nombre.hpp"

using namespace std;

Variable::Variable(char nom){
    nom_ = nom;
}

/**
 * \fn Variable affiche( ostream & out )
 * \brief Print the variable name
 *
 * The out flux is just the the name of the value
 *
 * \param out     output flux
 */
void Variable::DoAffiche(ostream & out) const{
    out << nom_;
};

shared_ptr<Expression> Variable::DoDerive(char v) const {
    if (nom_ == v){
        return nombreUn;
    }
    return nombreZero;
}

shared_ptr<Expression> Variable::DoSimplification() {
    return shared_from_this();
}

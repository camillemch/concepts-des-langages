//
//  expression.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef expression_hpp
#define expression_hpp

#include <stdio.h>
#include <iostream>

class Expression{
public :
    Expression() {nb_instances_rest ++; nb_instances_tot++;}
    virtual ~Expression(){nb_instances_rest --;};
    
    static int nb_instances_restant();
    static int nb_instances_total();
    // Affiche function print the operand depending on the type
    virtual void affiche( std::ostream & out ) const = 0;
    // Derive fonction prend en argument la variable de dérivation
    virtual Expression * derive(char v) const = 0;
    virtual Expression * clone() const = 0;
    virtual Expression * simplification() const = 0;

protected :
    static int nb_instances_rest;
    static int nb_instances_tot;
};

inline std::ostream & operator<<( std::ostream & out, const Expression & e ) {
    e.affiche( out ) ;
    return out;
};

#endif /* expression_hpp */

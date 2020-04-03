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
#include <memory>
#include <iostream>

using namespace std;

class Expression : public enable_shared_from_this<Expression>{
public :
    Expression() {nb_instances_rest ++; nb_instances_tot++;}
    virtual ~Expression(){nb_instances_rest --;};
    
    static int nb_instances_restant();
    static int nb_instances_total();
    // Affiche function print the operand depending on the type
    void affiche( ostream & out ) const {DoAffiche(out);}
    // Derive fonction prend en argument la variable de dérivation
    shared_ptr<Expression> derive(char v) const {return DoDerive(v);}
    shared_ptr<Expression> simplification() {return DoSimplification();}

private :
    static int nb_instances_rest;
    static int nb_instances_tot;
    virtual void DoAffiche( ostream & out ) const = 0;
    virtual shared_ptr<Expression> DoDerive(char v) const = 0;
    virtual shared_ptr<Expression> DoSimplification() = 0;
};

inline ostream & operator<<( ostream & out, const Expression & e ) {
    e.affiche( out ) ;
    return out;
};


#endif /* expression_hpp */

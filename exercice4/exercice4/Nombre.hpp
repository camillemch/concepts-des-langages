//
//  Nombre.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Nombre_hpp
#define Nombre_hpp

#include <stdio.h>
#include "Expression.hpp"

class Nombre : public Expression{
public:
    Nombre(double value);
    
    void affiche(std::ostream & out) const;
    Expression * derive(char v) const;
    virtual Expression * clone() const;
    virtual Expression * simplification() const ;
    double getValue() const;

protected:
    double value_;
};

#endif /* Nombre_hpp */

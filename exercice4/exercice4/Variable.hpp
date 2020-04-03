//
//  Variable.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include "Expression.hpp"
#include <stdio.h>

class Variable : public Expression{
public:
    Variable(char nom);
    
    void affiche(std::ostream & out) const;
    Expression * derive(char v) const;
    virtual Expression * clone() const ;
    virtual Expression * simplification() const ;
    
private:
    char nom_;
};

#endif /* Variable_hpp */

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

using namespace std;

class Nombre : public Expression{
public:
    Nombre(double value);
    
    void DoAffiche(ostream & out) const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification();
    double getValue() const;

protected:
    double value_;
};

extern shared_ptr<Nombre> nombreZero;
extern shared_ptr<Nombre> nombreUn;


#endif /* Nombre_hpp */

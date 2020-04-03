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

using namespace std;

class Variable : public Expression{
public:
    Variable(char nom);
    
    void DoAffiche(ostream & out) const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification() ;
    
private:
    char nom_;
};

#endif /* Variable_hpp */

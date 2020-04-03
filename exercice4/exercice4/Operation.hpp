//
//  Operation.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Operation_hpp
#define Operation_hpp

#include <stdio.h>
#include "Expression.hpp"

class Operation : public Expression{
public:
    Operation(Expression * opLeft, Expression * opRight);
    ~Operation();
    
    virtual char symbol() const = 0;
    void affiche( std::ostream & out ) const;
    virtual Expression * derive(char v) const = 0;
    virtual Expression * clone()  const = 0;
    virtual Expression * simplification() const = 0;

protected:
    Expression * opLeft_;
    Expression * opRight_;
};

#endif /* Operation_hpp */

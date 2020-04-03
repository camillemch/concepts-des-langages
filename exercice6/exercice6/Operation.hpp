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

using namespace std;

class Operation : public Expression{
public:
    Operation(shared_ptr<Expression> opLeft, shared_ptr<Expression> opRight);
    ~Operation();
    
    char symbol() const {return DoSymbol();};
    void DoAffiche( ostream & out ) const;
//    shared_ptr<Expression> derive(char v) const;
//    shared_ptr<Expression> clone()  const;
//    shared_ptr<Expression> simplification() const;

protected:
    shared_ptr<Expression> opLeft_;
    shared_ptr<Expression> opRight_;
    virtual char DoSymbol() const = 0;
    virtual shared_ptr<Expression> DoDerive(char v) const = 0;
//    virtual shared_ptr<Expression> DoClone()  const = 0;
    virtual shared_ptr<Expression> DoSimplification() = 0;
};

#endif /* Operation_hpp */

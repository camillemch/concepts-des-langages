//
//  SousOperation.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Addition_hpp
#define Addition_hpp

#include <stdio.h>
#include "Operation.hpp"

using namespace std;

class Addition : public Operation{
public:
    using Operation::Operation;
    
    char DoSymbol() const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification() ;
};

class Soustraction : public Operation{
public:
    using Operation::Operation;
    
    char DoSymbol() const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification() ;
};

class Multiplication : public Operation{
public:
    using Operation::Operation;
    
    char DoSymbol() const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification() ;
};

class Division : public Operation{
public:
    using Operation::Operation;
    
    char DoSymbol() const;
    shared_ptr<Expression> DoDerive(char v) const;
    shared_ptr<Expression> DoSimplification() ;
};
#endif /* SousOperation_hpp */

//
//  Addition.hpp
//  exercice4
//
//  Created by Camille Michel on 18/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Addition_hpp
#define Addition_hpp

#include <stdio.h>
#include "Operation.hpp"

class Addition : public Operation{
public:
    using Operation::Operation;
    
    char symbol() const;
    Expression * clone() const; //override;
    Expression * derive(char v) const;
    Expression * simplification()const ;
};

class Soustraction : public Operation{
public:
    using Operation::Operation;
    
    char symbol() const;
    Expression * clone() const ;
    Expression * derive(char v) const;
    Expression * simplification()const ;
};

class Multiplication : public Operation{
public:
    using Operation::Operation;
    
    char symbol() const;
    Expression * clone() const ;
    Expression * derive(char v) const;
    Expression * simplification()const ;
};

class Division : public Operation{
public:
    using Operation::Operation;
    
    char symbol() const;
    Expression * clone() const ;
    Expression * derive(char v) const;
    Expression * simplification()const ;
};
#endif /* Addition_hpp */

//
//  class.hpp
//  exercice3
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef class_hpp
#define class_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Number {
public:
    virtual ~Number(){};

    virtual void affiche( std::ostream & out ) const = 0;
    virtual int intValue() const = 0;
    virtual double doubleValue() const = 0;

};

class Integer : public Number {
public:
    Integer(int intValue_);
//    Integer( const Integer & i );
    
    void affiche(std::ostream & out) const{
        out << intValue_;
    };
    int intValue() const;
    double doubleValue() const;
    
    
private:
    int intValue_;
};


class Double : public Number {
public:
    Double(double doubleValue_);
//    Double( const Double & d );
    
    void affiche(std::ostream & out) const{
        out << doubleValue_;
    };
    
    double doubleValue() const;
    int intValue() const;
    
    
private:
    double doubleValue_;
};


inline std::ostream & operator<<( std::ostream & out, const Number & n ) {
    n.affiche( out ) ;
    return out;
};

#endif /* class_hpp */

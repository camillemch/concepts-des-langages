//
//  Nombre.hpp
//  exercice5
//
//  Created by Camille Michel on 21/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef Nombre_hpp
#define Nombre_hpp

#include <stdio.h>
#include <iostream>

class Nombre {
public:
    Nombre( unsigned int n );
    Nombre( std::string s );
    Nombre( const Nombre & n);          // Constructeur par copie
    Nombre( Nombre && n);               // Constructeur par déplacement
    ~Nombre();
    Nombre & operator=( const Nombre & n );     // Affectation par copie
    Nombre & operator=( Nombre && n );          // Affectation par déplacement
    Nombre & operator+=( const int i );
    Nombre & operator*=( const int i );
    Nombre operator+( const int i );
    Nombre operator*( const int i );
    
    friend std::ostream & operator <<( std::ostream & out, const Nombre & n );
    static int nb_instances();
    void swap( Nombre & n);
    unsigned int getValuePremier() const;
    
private:
    struct Chiffre {
        Chiffre(unsigned int chiffre = 0, Chiffre * suivant = nullptr){chiffre_=chiffre; suivant_=suivant;}
        unsigned int chiffre_;     // entre 0 et 9
        Chiffre * suivant_;        // chiffre de poids supérieur ou nullptr
    };
    Chiffre * premier_;
    Chiffre * dernier_;
    static int nb_instances_;
};

Nombre factorielle( unsigned int n );

#endif /* Nombre_hpp */

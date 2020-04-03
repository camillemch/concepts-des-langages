//
//  chiffre.cpp
//  exercice2
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <iostream>
#include <cctype>

#include "chiffre.hpp"

using namespace std;


Nombre lecture_nombre( std::istream & in )
{
    Nombre res = nullptr;
    // Version itérative pour la lecture
    // La version récursive demande un peu de réflexion
    while( in.good() ) {
        char c = in.get();
        if( std::isdigit( c )) {
            unsigned int d = c - '0';
            Chiffre * nouveau = new Chiffre;
            // d contient le chiffre entre 0 et 9 qui vient d'être lu
            // Affectation de la valeur
            nouveau->chiffre_ = d;
            // Le suivant du nouveau chiffre est le pointeur de l'ancien premier chiffre de la liste
            nouveau->suivant_ = res;
            // Le Nombre devient le pointeur du nouveau chiffre (premier chiffre de la liste)
            res = nouveau;
        }
        else break;
    }
    return res;
}


void affiche_nombre( Nombre n, std::ostream & out )
{
    // Cas d'arret
    if (n == nullptr)
        return;
    affiche_nombre(n->suivant_, out);
    out << n->chiffre_ ;
}


void detruit_nombre( Nombre n )
{
    // Cas d'arret
    if (n == nullptr)
        return;
    detruit_nombre(n->suivant_);
    delete(n);
}



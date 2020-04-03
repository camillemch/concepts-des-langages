//
//  chiffre.hpp
//  exercice2
//
//  Created by Camille Michel on 17/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#ifndef chiffre_hpp
#define chiffre_hpp

#include <cctype>
#include <iostream>

/**
 * \struct Chiffre
 * \brief Représentation d'un nombre entier positif de taille quelconque
 *
 * Un Chiffre est un maillon pour la représentation d'un nombre sous la forme d'une liste
 * simplement chainée de ses chiffres.
 */

struct Chiffre {
    unsigned int chiffre_;   /**< entre 0 et 9 */
    Chiffre * suivant_;      /**< pointeur vers le chiffre de poids supérieur ou nullptr */
};

/**
 * \typedef Nombre
 * \brief Un Nombre est un pointeur sur un Chiffre.
 */
typedef Chiffre * Nombre;

/**
 * \fn Nombre lecture_nombre( std::istream & in )
 * \brief Construction d'un nombre à partir d'un flux d'entrée.
 *
 * Les caractères extraits du flux d'entrée doivent être des chiffres, la construction
 * se termine sur le premier caractère lu qui n'est pas un chiffre (caractère qui est
 * consommé) ou sur la fin du flux.
 *
 * \param in     le flux d'entrée
 * \return       le nombre lu ou nullptr si le premier caractère lu n'est pas un chiffre
 */
Nombre lecture_nombre( std::istream & in );

/**
 * \fn void affiche_nombre( Nombre n, std::ostream & out )
 * \brief Affichage d'un nombre sur un flux de sortie
 *
 * \param n       le nombre à afficher
 * \param out     le flux de sortie
 */
void affiche_nombre( Nombre n, std::ostream & out );

/**
 * \fn void detruit_nombre( Nombre n )
 * \brief Libération de la mémoire utilisée pour représenter un nombre
 *
 * \param n       le nombre à détruire
 */
void detruit_nombre( Nombre n );

#endif /* chiffre_hpp */

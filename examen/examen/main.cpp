//
//  main.cpp
//  examen
//
//  Created by Camille Michel on 20/10/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

/************************************************************************************
 *                        EXAMEN
 *        CURSUS SUPÉLEC - MAJEURE SI - PROMOTION 2020
 * CONCEPTS DES LANGAGES ET TECHNIQUES DE PROGRAMMATION AVEC C++
 *              AUTEUR : DOMINIQUE MARCADET
 ************************************************************************************/

/************************************************************************************
 * PRESENTATION
 *
 * L'exercice porte sur les tas binaires.
 *
 ************************************************************************************/

/************************************************************************************
 * VÉRIFICATION DES RÉPONSES FOURNIES
 *
 * Des programmes de tests sont fournis dans l'énoncé, ils ne doivent pas être modifiés.
 * Ces tests ne sont pas exhaustifs, UN TEST RÉUSSI EST DONC UNE CONDITION NÉCESSAIRE
 * MAIS NON SUFFISANTE POUR QUALIFIER DE CORRECTE UNE RÉPONSE. C'EST LE CORRECTEUR
 * QUI IN FINE ÉVALUERA LA RÉPONSE.
 *
 * LE PROGRAMME DE TEST PRÉCISE EN PARTICULIER LES SIGNATURES SOUHAITÉES DES MÉTHODES
 ************************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <functional>

/************************************************************************************
 * UTILITAIRE
 *
 * La fonction verifie affiche le message reçu si la condition est fausse. La valeur
 * retournée est cette condition.
 * Elle est utilisée pour écrire les programmes de test pour éviter des problèmes
 * à celles ou ceux n'ayant pas réussi à installer Google Test.
 *
 * AUCUN MESSAGE N'EST AFFICHÉ QUAND LES TESTS SONT RÉUSSIS
 ************************************************************************************/
bool verifie( bool condition, std::string message )
{
    if( ! condition ) std::cerr << message << std::endl;
    return condition;
}

/************************************************************************************
 * SEPARATION DES QUESTIONS
 *
 * Afin de permettre une progression entre les questions de l'énoncé, chaque
 * question est dans son propre espace de noms, et vos réponses à une question
 * devront figurer dans l'espace de noms de la question.
 * Lors du changement de question, vous devez copier/coller votre réponse de la
 * question précédente dans la question courante et modifier ensuite cette copie
 * afin de répondre à la nouvelle question.
 * Dans chaque question figure un programme de test qui permet de vérifier partiellement
 * que votre réponse est correcte. L'activation de la vérification d'une question
 * particulière n'est faite que lorsque que la directive correspondante, en
 * dessous de ce commentaire, est dé-commentée.
 *
 * IL NE FAUT DONC PAS MODIFIER LES #ifdef ... #endif FIGURANT DANS L'ÉNONCÉ
 ************************************************************************************/

/************************************************************************************
 * DÉCOMENTEZ LES LIGNES SUIVANTES AU FUR ET A MESURE DE VOTRE PROGRESSION
 ************************************************************************************/
#define QUESTION_1
#define QUESTION_2
#define QUESTION_3
#define QUESTION_4
#define QUESTION_5

//==================================================================================

#ifdef QUESTION_1

namespace question_1 {
    /************************************************************************************
     * QUESTION 1
     *
     * Définir une classe tas_binaire représentant un tas binaire d'entiers. La représentation
     * de ce tas sera faite dans un std::vector< int >, son constructeur recevra comme
     * argument le premier élément du tas, une opération taille() permettra de connaître le
     * nombre d'éléments dans ce tas alors que l'opération racine() donnera accès à celle-ci
     * sans l'extraire.
     ************************************************************************************/
    
    
    class tas_binaire {
    public:
        tas_binaire(int premier){
            tas.push_back(premier);
        }
        tas_binaire( tas_binaire & tasCopie){
            for (int i = 0; i < tasCopie.taille(); i++) {
                tas.push_back(tasCopie.getValue(i));
            }
        }
        unsigned long taille() const {
            return tas.size() ;
        }
        int racine() const {
            return tas[0];
        }
        int getValue(int place) const {
            return tas[place];
        }
    private:
        std::vector<int> tas;
        
    };
    
    
    /************************************************************************************
     * Programme de test
     * NE PAS MODIFIER
     ************************************************************************************/
    
    void test()
    {
        std::cerr << "Test question 1: start\n";
        bool success = true;
        
        tas_binaire tas1( 14 );
        success = verifie( tas1.taille() == 1,   "QUESTION_1 : tas1.taille() incorrect" ) && success;
        success = verifie( tas1.racine() == 14,  "QUESTION_1 : tas1.racine() incorrect" ) && success;
        
        const tas_binaire tas2( tas1 );
        success = verifie( tas2.taille() == 1,   "QUESTION_1 : tas2.taille() incorrect" ) && success;
        success = verifie( tas2.racine() == 14,  "QUESTION_1 : tas2.racine() incorrect" ) && success;
        
        tas_binaire tas3( -1 );
        tas3 = tas2;
        success = verifie( tas3.taille() == 1,   "QUESTION_1 : tas3.taille() incorrect" ) && success;
        success = verifie( tas3.racine() == 14,  "QUESTION_1 : tas3.racine() incorrect" ) && success;
        
        std::cerr << "Test question 1: end: " << ( success ? "OK" : "KO" ) << "\n";
    }
    
}       // namespace question_1

#endif


#ifdef QUESTION_2

namespace question_2 {
    /************************************************************************************
     * QUESTION 2
     *
     * Écrire la méthode d'insertion d'un élément dans le tas.
     ************************************************************************************/
    
    class tas_binaire {
    public:
        tas_binaire(int premier){
            tas.push_back(premier);
        }
        tas_binaire( tas_binaire & tasCopie){
            for (int i = 0; i < tasCopie.taille(); i++) {
                tas.push_back(tasCopie.getValue(i));
            }
        }
        unsigned long taille() const {
            return tas.size() ;
        }
        int racine() const {
            return tas[0];
        }
        int getValue(int position) const {
            return tas[position];
        }
        void insere(int value){
            tas.push_back(value);
            int position = (int) tas.size() - 1;
            // Tant que le fils est inférieur à son père
            while (tas[position] < tas[(position - 1) / 2]){
                iter_swap(tas.begin() + position, tas.begin() + (position - 1) / 2);
                position = (position - 1) / 2;
            }
        }
    private:
        std::vector<int> tas;
        
    };

    
    /************************************************************************************
     * Programme de test
     * NE PAS MODIFIER
     ************************************************************************************/
    
    void test()
    {
        std::cerr << "Test question 2: start\n";
        bool success = true;
        
        tas_binaire tas( 14 );
        
        tas.insere( 18 );
        success = verifie( tas.taille() ==  2, "QUESTION_2a : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() == 14, "QUESTION_2a : tas.racine() incorrect" ) && success;
        
        tas.insere( 9 );
        success = verifie( tas.taille() ==  3, "QUESTION_2b : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() ==  9, "QUESTION_2b : tas.racine() incorrect" ) && success;
        
        tas.insere( 19 );
        success = verifie( tas.taille() ==  4, "QUESTION_2c : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() ==  9, "QUESTION_2c : tas.racine() incorrect" ) && success;
        
        tas.insere( 5 );
        success = verifie( tas.taille() ==  5, "QUESTION_2d : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() ==  5, "QUESTION_2d : tas.racine() incorrect" ) && success;
        
        tas.insere( 21 );
        success = verifie( tas.taille() ==  6, "QUESTION_2e : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() ==  5, "QUESTION_2e : tas.racine() incorrect" ) && success;
        
        tas.insere( 11 );
        success = verifie( tas.taille() ==  7, "QUESTION_2f : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() ==  5, "QUESTION_2f : tas.racine() incorrect" ) && success;
        
        std::cerr << "Test question 2: end: " << ( success ? "OK" : "KO" ) << "\n";
    }
    
}       // namespace question_2

#endif

#ifdef QUESTION_3

namespace question_3 {
    /************************************************************************************
     * QUESTION 3
     *
     * Écrire la méthode d'extraction de la racine du tas. Si le tas est vide, il faudra
     * émettre l'exception std::out_of_range.
     *
     * PRÉCISION
     * L'algorithme de cette opération est plus complexe que celui de l'insertion. Il
     * est donc possible de traiter les questions 4 et 5 avant cette question.
     ************************************************************************************/
    
    class tas_binaire {
    public:
        tas_binaire(int premier){
            tas.push_back(premier);
        }
        tas_binaire( tas_binaire & tasCopie){
            for (int i = 0; i < tasCopie.taille(); i++) {
                tas.push_back(tasCopie.getValue(i));
            }
        }
        unsigned long taille() const {
            return tas.size() ;
        }
        int racine() const {
            return tas[0];
        }
        int getValue(int position) const {
            return tas[position];
        }
        void insere(int value){
            tas.push_back(value);
            int position = (int) tas.size() - 1;
            // Tant que le fils est inférieur à son père
            while (tas[position] < tas[(position - 1) / 2]){
                iter_swap(tas.begin() + position, tas.begin() + (position - 1) / 2);
                position = (position - 1) / 2;
            }
        }
        int extraire(){
            if (tas.empty()){
                throw std::out_of_range("Tas is empty");
            }
            // 1ere étape
            int racine = tas.front();
            iter_swap(tas.begin(), tas.end());
            tas.pop_back();
            // Si l'arbre n'a plus qu'une racine ne pas faire l'étape 2
            if (tas.size() == 1){
                return racine;
            }
            // 2nde étape
            int position = 0;
            int positionFils;
            // Tant que supérieur à un de ses fils
            while(tas[position] > tas[2*position + 1] || tas[position] > tas[2*position + 2]){
                if (tas[2*position + 1] > tas[2*position + 2]){
                    positionFils = 2*position + 2;
                }
                else { positionFils = 2*position + 1;}
                iter_swap(tas.begin() + position, tas.begin() + positionFils);
                position = positionFils;
                // Teste si on arrive sur une feuille
                if (2 * position + 1 >= tas.size()){
                    return racine;
                }
            }
            return racine;
        }
        
    private:
        std::vector<int> tas;
        
    };
    

    /************************************************************************************
     * Programme de test
     * NE PAS MODIFIER
     ************************************************************************************/
    
    void test()
    {
        std::cerr << "Test question 3: start\n";
        bool success = true;
        
        tas_binaire tas( 14 );
        tas.insere( 18 );
        tas.insere( 9 );
        tas.insere( 19 );
        tas.insere( 5 );
        tas.insere( 21 );
        tas.insere( 11 );
        
        try {
            success = verifie( tas.extraire() ==  5, "QUESTION_3a : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() ==  9, "QUESTION_3b : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == 11, "QUESTION_3c : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == 14, "QUESTION_3d : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == 18, "QUESTION_3e : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == 19, "QUESTION_3f : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == 21, "QUESTION_3g : tas.extraire() incorrect" ) && success;
        }
        catch( std::out_of_range ) {
            success = verifie( false, "QUESTION_3h : exception out_of_range emise" ) && success;
        }
        try {
            int n = tas.extraire();
            success = verifie( false, "QUESTION_3i : exception out_of_range non emise" ) && success;
        }
        catch( std::out_of_range ) {
        }
        
        std::cerr << "Test question 3: end: " << ( success ? "OK" : "KO" ) << "\n";
    }
    
}       // namespace question_3

#endif


#ifdef QUESTION_4

namespace question_4 {
    /************************************************************************************
     * QUESTION 4
     *
     * Modifier la définition de votre tas pour qu'il soit générique par rapport au type
     * des éléments stockés (ceux-ci devront pouvoir être comparés avec <)
     ************************************************************************************/
    // Code question 2
    
    template < typename T >
    class tas_binaire {
    public:
        tas_binaire(T premier){
            tas.push_back(premier);
        }
        tas_binaire( tas_binaire & tasCopie){
            for (int i = 0; i < tasCopie.taille(); i++) {
                tas.push_back(tasCopie.getValue(i));
            }
        }
        unsigned long taille() const {
            return tas.size() ;
        }
        T racine() const {
            return tas[0];
        }
        T getValue(int position) const {
            return tas[position];
        }
        void insere(T value){
            tas.push_back(value);
            int position = (int) tas.size() - 1;
            // Tant que le fils est inférieur à son père
            while (tas[position] < tas[(position - 1) / 2]){
                iter_swap(tas.begin() + position, tas.begin() + (position - 1) / 2);
                position = (position - 1) / 2;
            }
        }
        T extraire(){
            if (tas.empty()){
                throw std::out_of_range("Tas is empty");
            }
            // 1ere étape
            T racine = tas.front();
            iter_swap(tas.begin(), tas.end());
            tas.pop_back();
            // Si l'arbre n'a plus qu'une racine ne pas faire l'étape 2
            if (tas.size() == 1){
                return racine;
            }
            // 2nde étape
            int position = 0;
            int positionFils;
            // Tant que supérieur à un de ses fils
            while( tas[position] > tas[2*position + 1] ||  tas[position] >  tas[2*position + 2]){
                if (tas[2*position + 1] > tas[2*position + 2]){
                    positionFils = 2*position + 2;
                }
                else { positionFils = 2*position + 1;}
                iter_swap(tas.begin() + position, tas.begin() + positionFils);
                position = positionFils;
                // Teste si on arrive sur une feuille
                if (2 * position + 1 >= tas.size()){
                    return racine;
                }
            }
            return racine;
        }
    private:
        std::vector< T > tas;
        
    };
    
    /************************************************************************************
     * Programme de test
     * NE PAS MODIFIER
     ************************************************************************************/
    
    void test()
    {
        std::cerr << "Test question 4: start\n";
        bool success = true;
        
        tas_binaire< std::string > tas( "14" );
        success = verifie( tas.racine() == "14", "QUESTION_4a : tas.racine() incorrect" ) && success;
        
        tas.insere( "18" );
        success = verifie( tas.racine() == "14", "QUESTION_4b : tas.racine() incorrect" ) && success;
        
        tas.insere( "09" );
        success = verifie( tas.racine() == "09", "QUESTION_4c : tas.racine() incorrect" ) && success;
        
        tas.insere( "19" );
        success = verifie( tas.racine() == "09", "QUESTION_4d : tas.racine() incorrect" ) && success;
        
        tas.insere( "05" );
        success = verifie( tas.racine() == "05", "QUESTION_4e : tas.racine() incorrect" ) && success;
        
        tas.insere( "21" );
        success = verifie( tas.racine() == "05", "QUESTION_4f : tas.racine() incorrect" ) && success;
        
        tas.insere( "11" );
        success = verifie( tas.taille() ==    7, "QUESTION_4g : tas.taille() incorrect" ) && success;
        success = verifie( tas.racine() == "05", "QUESTION_4h : tas.racine() incorrect" ) && success;
        
#ifdef QUESTION_3
        
        try {
            success = verifie( tas.extraire() == "05", "QUESTION_4i : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "09", "QUESTION_4j : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "11", "QUESTION_4k : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "14", "QUESTION_4l : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "18", "QUESTION_4m : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "19", "QUESTION_4n : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "21", "QUESTION_4o : tas.extraire() incorrect" ) && success;
        }
        catch( std::out_of_range ) {
            success = verifie( false, "QUESTION_4p : exception out_of_range emise" ) && success;
        }
        try {
            auto n = tas.extraire();
            success = verifie( false, "QUESTION_4q : exception out_of_range non emise" ) && success;
        }
        catch( std::out_of_range ) {
        }
        
#endif
        
        std::cerr << "Test question 4: end: " << ( success ? "OK" : "KO" ) << "\n";
    }
    
}       // namespace question_4

#endif


#ifdef QUESTION_5

namespace question_5 {
    /************************************************************************************
     * QUESTION 5
     *
     * Le tas réalisé jusqu'à présent permet d'accéder en temps constant au plus petit
     * élément, on l'apelle tas-min. Il existe aussi des tas-max, et de manière plus générale,
     * l'utilisateur doit pouvoir indiquer comment comparer deux éléments.
     *
     * Modifier votre tas en ajoutant un second paramètre de généricité ; celui-ci sera
     * le type du comparateur à utiliser (un objet fonction) et sera par défaut std::less.
     ************************************************************************************/
    
    template < typename T, typename T2>
    class tas_binaire {
    public:
        tas_binaire(T premier){
            tas.push_back(premier);
        }
        tas_binaire( tas_binaire & tasCopie){
            for (int i = 0; i < tasCopie.taille(); i++) {
                tas.push_back(tasCopie.getValue(i));
            }
        }
        unsigned long taille() const {
            return tas.size() ;
        }
        T racine() const {
            return tas[0];
        }
        T getValue(int position) const {
            return tas[position];
        }
        void insere(T value){
            tas.push_back(value);
            int position = (int) tas.size() - 1;
            // Tant que le fils est inférieur à son père
            while (tas[position] < tas[(position - 1) / 2]){
                iter_swap(tas.begin() + position, tas.begin() + (position - 1) / 2);
                position = (position - 1) / 2;
            }
        }
        T extraire(){
            if (tas.empty()){
                throw std::out_of_range("Tas is empty");
            }
            // 1ere étape
            T racine = tas.front();
            iter_swap(tas.begin(), tas.end());
            tas.pop_back();
            // Si l'arbre n'a plus qu'une racine ne pas faire l'étape 2
            if (tas.size() == 1){
                return racine;
            }
            // 2nde étape
            int position = 0;
            int positionFils;
            // Tant que supérieur à un de ses fils
            while( tas[position] >  tas[2*position + 1] ||  tas[position] >  tas[2*position + 2]){
                if (tas[2*position + 1] > tas[2*position + 2]){
                    positionFils = 2*position + 2;
                }
                else { positionFils = 2*position + 1;}
                iter_swap(tas.begin() + position, tas.begin() + positionFils);
                position = positionFils;
                // Teste si on arrive sur une feuille
                if (2 * position + 1 >= tas.size()){
                    return racine;
                }
            }
            return racine;
        }
    private:
        std::vector< T > tas;
        
};
    
    /************************************************************************************
     * Programme de test
     * NE PAS MODIFIER
     ************************************************************************************/
    
    void test()
    {
        std::cerr << "Test question 5: start\n";
        bool success = true;
        
        tas_binaire< std::string, std::greater< std::string > > tas( "14" );
        success = verifie( tas.racine() == "14", "QUESTION_5b : tas.racine() incorrect" ) && success;
        
        tas.insere( "18" );
        success = verifie( tas.racine() == "18", "QUESTION_5b : tas.racine() incorrect" ) && success;
        
        tas.insere( "09" );
        success = verifie( tas.racine() == "18", "QUESTION_5c : tas.racine() incorrect" ) && success;
        
        tas.insere( "19" );
        success = verifie( tas.racine() == "19", "QUESTION_5d : tas.racine() incorrect" ) && success;
        
        tas.insere( "05" );
        success = verifie( tas.racine() == "19", "QUESTION_5e : tas.racine() incorrect" ) && success;
        
        tas.insere( "21" );
        success = verifie( tas.racine() == "21", "QUESTION_5f : tas.racine() incorrect" ) && success;
        
        tas.insere( "11" );
        success = verifie( tas.racine() == "21", "QUESTION_5g : tas.racine() incorrect" ) && success;
        
#ifdef QUESTION_3
        
        try {
            success = verifie( tas.extraire() == "21", "QUESTION_5h : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "19", "QUESTION_5i : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "18", "QUESTION_5j : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "14", "QUESTION_5k : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "11", "QUESTION_5l : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "09", "QUESTION_5m : tas.extraire() incorrect" ) && success;
            success = verifie( tas.extraire() == "05", "QUESTION_5n : tas.extraire() incorrect" ) && success;
        }
        catch( std::out_of_range ) {
            success = verifie( false, "QUESTION_5o : exception out_of_range non emise" ) && success;
        }
        try {
            auto n = tas.extraire();
            success = verifie( false, "QUESTION_5p : exception out_of_range non emise" ) && success;
        }
        catch( std::out_of_range ) {
        }
        
#endif
        
        std::cerr << "Test question 5: end: " << ( success ? "OK" : "KO" ) << "\n";
    }
    
}       // namespace question_5

#endif


//==================================================================================



/************************************************************************************
 * Programme principal
 * NE PAS MODIFIER
 ************************************************************************************/
int main()
{
    std::cerr << "Début des tests\n";
    
#ifdef QUESTION_1
    question_1::test();
#endif
    
#ifdef QUESTION_2
    question_2::test();
#endif
    
#ifdef QUESTION_3
    question_3::test();
#endif
    
#ifdef QUESTION_4
    question_4::test();
#endif
    
#ifdef QUESTION_5
    question_5::test();
#endif
    
    std::cerr << "Fin des tests\n";
    return 0;
}

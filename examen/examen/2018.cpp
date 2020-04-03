////
////  2018.cpp
////  examen
////
////  Created by Camille Michel on 20/10/2019.
////  Copyright © 2019 Camille Michel. All rights reserved.
////
//
//#include <stdio.h>
//
//
///************************************************************************************
// *                        EXAMEN
// *        CURSUS SUPÉLEC - MAJEURE SI - PROMOTION 2019
// * CONCEPTS DES LANGAGES ET TECHNIQUES DE PROGRAMMATION AVEC C++
// *              AUTEUR : DOMINIQUE MARCADET
// ************************************************************************************/
//
///************************************************************************************
// * PRESENTATION
// *
// * L'objectif de cet exercice est de réaliser une version très simplifiée et non
// * optimale d'un variant.
// *
// * Un type variant est défini à partir d'une liste de types, un variant est un objet
// * de ce type qui peut contenir une valeur appartenant à l'un des types de la liste.
// *
// * Le standard 2017 de C++ inclut la définition d'un tel variant, vous pouvez voir
// * un exemple d'utilisation sur la page :
// *              https://en.cppreference.com/w/cpp/utility/variant
// ************************************************************************************/
//
///************************************************************************************
// * VÉRIFICATION DES RÉPONSES FOURNIES
// *
// * Des programmes de tests sont fournis dans l'énoncé, ils ne doivent pas être modifiés.
// * Ces tests ne sont pas exhaustifs, UN TEST RÉUSSI EST DONC UNE CONDITION NÉCESSAIRE
// * MAIS NON SUFFISANTE POUR QUALIFIER DE CORRECTE UNE RÉPONSE. C'EST LE CORRECTEUR
// * QUI IN FINE ÉVALUERA LA RÉPONSE.
// *
// * LE PROGRAMME DE TEST PRÉCISE EN PARTICULIER LES SIGNATURES SOUHAITÉES DES MÉTHODES
// ************************************************************************************/
//
//#include <iostream>
//#include <string>
//#include <complex>
//#include <utility>
//
///************************************************************************************
// * UTILITAIRE
// *
// * La fonction verifie affiche le message reçu si la condition est fausse. La valeur
// * retournée est cette condition.
// * Elle est utilisée pour écrire les programmes de test pour éviter des problèmes
// * à celles ou ceux n'ayant pas réussi à installer Google Test.
// *
// * AUCUN MESSAGE N'EST AFFICHÉ QUAND LES TESTS SONT RÉUSSIS
// ************************************************************************************/
//bool verifie( bool condition, std::string message )
//{
//    if( ! condition ) std::cerr << message << std::endl;
//    return condition;
//}
//
///************************************************************************************
// * SEPARATION DES QUESTIONS
// *
// * Afin de permettre une progression entre les questions de l'énoncé, chaque
// * question est dans son propre espace de noms, et vos réponses à une question
// * devront figurer dans l'espace de noms de la question.
// * Lors du changement de question, vous devez copier/coller votre réponse de la
// * question précédente dans la question courante et modifier ensuite cette copie
// * afin de répondre à la nouvelle question.
// * Dans chaque question figure un programme de test qui permet de vérifier partiellement
// * que votre réponse est correcte. L'activation de la vérification d'une question
// * particulière n'est faite que lorsque que la directive correspondante, en
// * dessous de ce commentaire, est dé-commentée.
// *
// * IL NE FAUT DONC PAS MODIFIER LES #ifdef ... #endif FIGURANT DANS L'ÉNONCÉ
// ************************************************************************************/
//
///************************************************************************************
// * DÉCOMENTEZ LES LIGNES SUIVANTES AU FUR ET A MESURE DE VOTRE PROGRESSION
// ************************************************************************************/
////#define QUESTION_1
////#define QUESTION_2
////#define QUESTION_3
////#define QUESTION_4
////#define QUESTION_5
////#define QUESTION_6
//
////==================================================================================
//
//#ifdef QUESTION_1
//
//namespace question_1 {
//    /************************************************************************************
//     * QUESTION 1
//     *
//     * Notre variant contiendra soit un entier (int), soit un flottant (double), soit une
//     * chaîne de caractères (std::string). Ces valeurs seront stockées dans 3 attributs
//     * distincts et accessibles par 3 méthodes différentes (cf. programme de test).
//     * Enfin, 3 constructeurs permettront de créer un variant avec des valeurs appartenant
//     * aux 3 types autorisés.
//     *
//     * DANS CETTE VERSION, AUCUNE VÉRIFICATION N'EST EFFECTUÉE PAR LES ACCESSEURS POUR
//     * S'ASSURER QUE LE VARIANT CONTIENT BIEN UNE VALEUR DU TYPE DEMANDÉ. CE POINT SERA
//     * TRAITÉ DANS LA QUESTION 2.
//     ************************************************************************************/
//    
//    class variant {
//    public:
//        variant(int value) {
//            valueInt = value;
//        }
//        
//        variant(double value) {
//            valueDouble = value;
//        }
//        
//        variant(std::string value) {
//            valueString = value;
//        }
//        
//        int int_value() {
//            return valueInt;
//        }
//        double double_value() {
//            return valueDouble;
//        }
//        std::string string_value() {
//            return valueString;
//        }
//        
//    private:
//        int valueInt;
//        double valueDouble;
//        std::string valueString;
//    };
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 1: start\n";
//        bool success = true;
//        
//        variant v1( 23 );
//        success = verifie( v1.int_value() == 23, "QUESTION_1 : int_value() incorrect" ) && success;
//        
//        variant v2( -3.14159 );
//        success = verifie( v2.double_value() == -3.14159, "QUESTION_1 : double_value() incorrect" ) && success;
//        
//        variant v3( "hello world" );
//        success = verifie( v3.string_value() == "hello world", "QUESTION_1 : string_value() incorrect" ) && success;
//        
//        std::cerr << "Test question 1: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_1
//
//#endif  // #ifdef QUESTION_1
//
//
//#ifdef QUESTION_2
//
//namespace question_2 {
//    /************************************************************************************
//     * QUESTION 2
//     *
//     * Nous allons maintenant vérifier que l'appel d'un accesseur se fait bien sur un
//     * variant contenant une valeur du bon type. Pour cela, un attribut mémorisera le type
//     * courant du variant (une énumération peut être utilisée), cet attribut sera
//     * initialisé dans les constructeurs et vérifié par les accesseurs.
//     *
//     * Le variant du standard C++ émet une exception bad_variant_access dans le cas où
//     * le type de la valeur accédée n'est pas conforme au type de la valeur stockée.
//     * Dans notre version, on se contentera de retourner une valeur « nulle » (0 pour les
//     * entiers et flottants, la chaîne vide pour les string : cf. programme de test).
//     *
//     * Notez que le constructeur de copie, l'opérateur d'affectation et le destructeur
//     * générés par le compilateur doivent être naturellement corrects (cf. programme
//     * de test)
//     ************************************************************************************/
//    
//    /************************************************************************************
//     * VOTRE RÉPONSE (COMMENCEZ PAR RECOPIER LA RÉPONSE À LA QUESTION PRÉCÉDENTE PUIS
//     * MODIFIEZ CELLE-CI)
//     ************************************************************************************/
//    
//    namespace NETypeOfVariant
//    {
//        typedef enum
//        {
//            String,
//            Int,
//            Double,
//        }ETypeOfVariant;
//    }
//    
//    class variant {
//    public:
//        variant(int value) {
//            valueInt = value;
//            typeOfVariant = NETypeOfVariant::Int;
//        }
//        
//        variant(double value) {
//            valueDouble = value;
//            typeOfVariant = NETypeOfVariant::Double;
//        }
//        
//        variant(std::string value) {
//            valueString = value;
//            typeOfVariant = NETypeOfVariant::String;
//        }
//        
//        int int_value() {
//            if (typeOfVariant != NETypeOfVariant::Int) {
//                return 0;
//            }
//            return valueInt;
//        }
//        double double_value() {
//            if (typeOfVariant != NETypeOfVariant::Double) {
//                return 0;
//            }
//            return valueDouble;
//        }
//        std::string string_value() {
//            if (typeOfVariant != NETypeOfVariant::String) {
//                return "";
//            }
//            return valueString;
//        }
//        
//    private:
//        int valueInt;
//        double valueDouble;
//        std::string valueString;
//        NETypeOfVariant::ETypeOfVariant typeOfVariant;
//        // TODO: 3 attributs pour les 3 types différents
//    };
//    
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 2: start\n";
//        bool success = true;
//        
//        variant v1( 23 );
//        success = verifie( v1.   int_value() == 23, "QUESTION_2 : v1.   int_value() incorrect" ) && success;
//        success = verifie( v1.double_value() == 0 , "QUESTION_2 : v1.double_value() incorrect" ) && success;
//        success = verifie( v1.string_value() == "", "QUESTION_2 : v1.string_value() incorrect" ) && success;
//        
//        variant v2( -3.14159 );
//        success = verifie( v2.   int_value() == 0       , "QUESTION_2 : v2.i   nt_value() incorrect" ) && success;
//        success = verifie( v2.double_value() == -3.14159, "QUESTION_2 : v2.double_value() incorrect" ) && success;
//        success = verifie( v2.string_value() == ""      , "QUESTION_2 : v2.string_value() incorrect" ) && success;
//        
//        variant v3( "hello world" );
//        success = verifie( v3.   int_value() == 0            , "QUESTION_2 : v3.   int_value() incorrect" ) && success;
//        success = verifie( v3.double_value() == 0            , "QUESTION_2 : v3.double_value() incorrect" ) && success;
//        success = verifie( v3.string_value() == "hello world", "QUESTION_2 : v3.string_value() incorrect" ) && success;
//        
//        variant v4( v1 );
//        success = verifie( v4.   int_value() == 23, "QUESTION_2 : v4.   int_value() incorrect" ) && success;
//        success = verifie( v4.double_value() == 0 , "QUESTION_2 : v4.double_value() incorrect" ) && success;
//        success = verifie( v4.string_value() == "", "QUESTION_2 : v4.string_value() incorrect" ) && success;
//        
//        v1 = v3;
//        success = verifie( v1.   int_value() == 0            , "QUESTION_2 : v1.   int_value() incorrect apres affectation" ) && success;
//        success = verifie( v1.double_value() == 0            , "QUESTION_2 : v1.double_value() incorrect apres affectation" ) && success;
//        success = verifie( v1.string_value() == "hello world", "QUESTION_2 : v1.string_value() incorrect apres affectation" ) && success;
//        
//        v2 = std::string( "bonjour" );      // La conversion explicite en string est ici nécessaire
//        success = verifie( v2.   int_value() == 0        , "QUESTION_2 : v2.   int_value() incorrect apres affectation" ) && success;
//        success = verifie( v2.double_value() == 0        , "QUESTION_2 : v2.double_value() incorrect apres affectation" ) && success;
//        success = verifie( v2.string_value() == "bonjour", "QUESTION_2 : v2.string_value() incorrect apres affectation" ) && success;
//        
//        std::cerr << "Test question 2: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_2
//
//#endif  // #ifdef QUESTION_2
//
//#ifdef QUESTION_3
//
//namespace question_3 {
//    /************************************************************************************
//     * QUESTION 3
//     *
//     * Nous souhaitons maintenant comparer des variants. Seuls les opérateurs == et !=
//     * sont demandés. Si 2 variants ne contiennent pas des valeurs du même type, ils sont
//     * différents. Sinon, le résultat est celui retourné par la comparaison des valeurs
//     * contenues.
//     *
//     * Pour éviter de devoir rendre amies ces fonctions de comparaison, vous pouvez ajouter
//     * une méthode index() qui retourne 0 (pour un int), 1 (pour un double) ou 2 (pour
//     * std::string) selon le type de la valeur contenue dans le variant. Le variant
//     * du standard C++ propose une telle méthode.
//     ************************************************************************************/
//    
//    /************************************************************************************
//     * VOTRE RÉPONSE (COMMENCEZ PAR RECOPIER LA RÉPONSE À LA QUESTION PRÉCÉDENTE PUIS
//     * MODIFIEZ CELLE-CI)
//     ************************************************************************************/
//    
//    
//    namespace NETypeOfVariant
//    {
//        typedef enum
//        {
//            String,
//            Int,
//            Double,
//        }ETypeOfVariant;
//    }
//    
//    class variant {
//    public:
//        variant(int value) {
//            valueInt = value;
//            typeOfVariant = NETypeOfVariant::Int;
//        }
//        
//        variant(double value) {
//            valueDouble = value;
//            typeOfVariant = NETypeOfVariant::Double;
//        }
//        
//        variant(std::string value) {
//            valueString = value;
//            typeOfVariant = NETypeOfVariant::String;
//        }
//        
//        int int_value() {
//            if (typeOfVariant != NETypeOfVariant::Int) {
//                return 0;
//            }
//            return valueInt;
//        }
//        double double_value() {
//            if (typeOfVariant != NETypeOfVariant::Double) {
//                return 0;
//            }
//            return valueDouble;
//        }
//        std::string string_value() {
//            if (typeOfVariant != NETypeOfVariant::String) {
//                return "";
//            }
//            return valueString;
//        }
//        
//        bool operator==(const variant &b) {
//            if (b.typeOfVariant != typeOfVariant) {
//                return false;
//            }
//            switch (typeOfVariant) {
//                case NETypeOfVariant::Int:
//                    return valueInt == b.valueInt;
//                case NETypeOfVariant::Double:
//                    return valueDouble == b.valueDouble;
//                case NETypeOfVariant::String:
//                    return valueString == b.valueString;
//            }
//        };
//        
//        
//        bool operator!=(const variant &b) {
//            return ! (*this == b);
//        }
//        
//        
//    private:
//        int valueInt;
//        double valueDouble;
//        std::string valueString;
//        NETypeOfVariant::ETypeOfVariant typeOfVariant;
//    };
//    
//    
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 3: start\n";
//        bool success = true;
//        
//        variant v1( 23 );
//        variant v2( -3.14159 );
//        variant v3( "hello world" );
//        success = verifie(    v1 == v1  , "QUESTION_3 : v1 == v1 faux" ) && success;
//        success = verifie( !( v2 != v2 ), "QUESTION_3 : v2 != v2 vrai" ) && success;
//        success = verifie(    v3 == v3  , "QUESTION_3 : v3 == v3 faux" ) && success;
//        success = verifie( !( v1 == v3 ), "QUESTION_3 : v1 != v3 vrai" ) && success;
//        success = verifie(    v2 != v3  , "QUESTION_3 : v2 != v3 faux" ) && success;
//        
//        std::cerr << "Test question 3: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_3
//
//#endif  // #ifdef QUESTION_3
//
//#ifdef QUESTION_4
//
//namespace question_4 {
//    /************************************************************************************
//     * QUESTION 4
//     *
//     * Le variant standard n'utilise pas, pour accéder aux valeurs contenues dans le
//     * variant, des méthodes avec des noms différents, mais une fonction générique par
//     * rapport au type accédé.
//     * Ainsi, au lieu de :
//     *      v.int_value();
//     * le standard utilise :
//     *      get< int >( v );
//     *
//     * Dans une première étape, nous resterons avec une approche objet, et donc l'objectif
//     * est de pouvoir écrire :
//     *       v.get< int >();
//     *
//     * Modifier votre variant pour remplacer les accesseurs actuels par cette écriture.
//     *
//     * INDICATIONS :
//     * Vous trouverez sur la page
//     *         http://wdi.supelec.fr/ConceptsLangProg/DemonstrationMethodeGenerique
//     * une présentation d'une technique permettant de répondre à cette question.
//     ************************************************************************************/
//    
//    /************************************************************************************
//     * VOTRE RÉPONSE (COMMENCEZ PAR RECOPIER LA RÉPONSE À LA QUESTION PRÉCÉDENTE PUIS
//     * MODIFIEZ CELLE-CI)
//     ************************************************************************************/
//    
//    
//    namespace NETypeOfVariant
//    {
//        typedef enum
//        {
//            String,
//            Int,
//            Double,
//        }ETypeOfVariant;
//    }
//    
//    class variant {
//    public:
//        variant(int value) {
//            valueInt = value;
//            typeOfVariant = NETypeOfVariant::Int;
//        }
//        
//        variant(double value) {
//            valueDouble = value;
//            typeOfVariant = NETypeOfVariant::Double;
//        }
//        
//        variant(std::string value) {
//            valueString = value;
//            typeOfVariant = NETypeOfVariant::String;
//        }
//        
//        template< typename T >
//        T get() {
//            return get_aux( T() );
//        }
//        
//        bool operator==(const variant &b) {
//            if (b.typeOfVariant != typeOfVariant) {
//                return false;
//            }
//            switch (typeOfVariant) {
//                case NETypeOfVariant::Int:
//                    return valueInt == b.valueInt;
//                case NETypeOfVariant::Double:
//                    return valueDouble == b.valueDouble;
//                case NETypeOfVariant::String:
//                    return valueString == b.valueString;
//            }
//        };
//        
//        
//        bool operator!=(const variant &b) {
//            return ! (*this == b);
//        }
//        
//        
//    private:
//        int valueInt;
//        double valueDouble;
//        std::string valueString;
//        NETypeOfVariant::ETypeOfVariant typeOfVariant;
//        
//        int get_aux(int) {
//            if (typeOfVariant != NETypeOfVariant::Int) {
//                return 0;
//            }
//            return valueInt;
//        }
//        double get_aux(double) {
//            if (typeOfVariant != NETypeOfVariant::Double) {
//                return 0;
//            }
//            return valueDouble;
//        }
//        std::string get_aux(std::string) {
//            if (typeOfVariant != NETypeOfVariant::String) {
//                return "";
//            }
//            return valueString;
//        }
//    };
//    
//    
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 4: start\n";
//        bool success = true;
//        
//        variant v1( 23 );
//        success = verifie( v1.get< int         >() == 23, "QUESTION_4 : v1.get< int         >() incorrect" ) && success;
//        success = verifie( v1.get< double      >() == 0 , "QUESTION_4 : v1.get< double      >() incorrect" ) && success;
//        success = verifie( v1.get< std::string >() == "", "QUESTION_4 : v1.get< std::string >() incorrect" ) && success;
//        
//        variant v2( -3.14159 );
//        success = verifie( v2.get< int         >() == 0       , "QUESTION_4 : v2.get< int         >() incorrect" ) && success;
//        success = verifie( v2.get< double      >() == -3.14159, "QUESTION_4 : v2.get< double      >() incorrect" ) && success;
//        success = verifie( v2.get< std::string >() == ""      , "QUESTION_4 : v2.get< std::string >() incorrect" ) && success;
//        
//        variant v3( "hello world" );
//        success = verifie( v3.get< int         >() == 0            , "QUESTION_4 : v3.get< int         >() incorrect" ) && success;
//        success = verifie( v3.get< double      >() == 0            , "QUESTION_4 : v3.get< double      >() incorrect" ) && success;
//        success = verifie( v3.get< std::string >() == "hello world", "QUESTION_4 : v3.get< std::string >() incorrect" ) && success;
//        
//        variant v4( v1 );
//        success = verifie( v4.get< int         >() == 23, "QUESTION_4 : v4.get< int         >() incorrect" ) && success;
//        success = verifie( v4.get< double      >() == 0 , "QUESTION_4 : v4.get< double      >() incorrect" ) && success;
//        success = verifie( v4.get< std::string >() == "", "QUESTION_4 : v4.get< std::string >() incorrect" ) && success;
//        
//        v1 = v3;
//        success = verifie( v1.get< int         >() == 0            , "QUESTION_4 : v1.get< int         >() incorrect apres affectation" ) && success;
//        success = verifie( v1.get< double      >() == 0            , "QUESTION_4 : v1.get< double      >() incorrect apres affectation" ) && success;
//        success = verifie( v1.get< std::string >() == "hello world", "QUESTION_4 : v1.get< std::string >() incorrect apres affectation" ) && success;
//        
//        v2 = std::string( "bonjour" );      // La conversion explicite en string est ici nécessaire
//        success = verifie( v2.get< int         >() == 0        , "QUESTION_4 : v2.get< int         >() incorrect apres affectation" ) && success;
//        success = verifie( v2.get< double      >() == 0        , "QUESTION_4 : v2.get< double      >() incorrect apres affectation" ) && success;
//        success = verifie( v2.get< std::string >() == "bonjour", "QUESTION_4 : v2.get< std::string >() incorrect apres affectation" ) && success;
//        
//        success = verifie( v1 == v3, "QUESTION_4 : v1 == v3 faux" ) && success;
//        success = verifie( v1 != v2, "QUESTION_4 : v1 != v2 faux" ) && success;
//        
//        std::cerr << "Test question 4: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_4
//
//#endif  // #ifdef QUESTION_4
//
//#ifdef QUESTION_5
//
//namespace question_5 {
//    /************************************************************************************
//     * QUESTION 5
//     *
//     * Proposez une solution pour ajouter la forme fonctionnelle telle qu'utilisée par
//     * le standard :
//     *      get< int >( v );
//     ************************************************************************************/
//    
//    /************************************************************************************
//     * VOTRE RÉPONSE (COMMENCEZ PAR RECOPIER LA RÉPONSE À LA QUESTION PRÉCÉDENTE PUIS
//     * MODIFIEZ CELLE-CI)
//     ************************************************************************************/
//    
//    namespace NETypeOfVariant
//    {
//        typedef enum
//        {
//            String,
//            Int,
//            Double,
//        }ETypeOfVariant;
//    }
//    
//    class variant {
//    public:
//        variant(int value) {
//            valueInt = value;
//            typeOfVariant = NETypeOfVariant::Int;
//        }
//        
//        variant(double value) {
//            valueDouble = value;
//            typeOfVariant = NETypeOfVariant::Double;
//        }
//        
//        variant(std::string value) {
//            valueString = value;
//            typeOfVariant = NETypeOfVariant::String;
//        }
//        
//        template< typename T >
//        T get() {
//            return get_aux( T() );
//        }
//        
//        bool operator==(const variant &b) {
//            if (b.typeOfVariant != typeOfVariant) {
//                return false;
//            }
//            switch (typeOfVariant) {
//                case NETypeOfVariant::Int:
//                    return valueInt == b.valueInt;
//                case NETypeOfVariant::Double:
//                    return valueDouble == b.valueDouble;
//                case NETypeOfVariant::String:
//                    return valueString == b.valueString;
//            }
//        };
//        
//        
//        bool operator!=(const variant &b) {
//            return ! (*this == b);
//        }
//        
//        
//    private:
//        int valueInt;
//        double valueDouble;
//        std::string valueString;
//        NETypeOfVariant::ETypeOfVariant typeOfVariant;
//        
//        int get_aux(int) {
//            if (typeOfVariant != NETypeOfVariant::Int) {
//                return 0;
//            }
//            return valueInt;
//        }
//        double get_aux(double) {
//            if (typeOfVariant != NETypeOfVariant::Double) {
//                return 0;
//            }
//            return valueDouble;
//        }
//        std::string get_aux(std::string) {
//            if (typeOfVariant != NETypeOfVariant::String) {
//                return "";
//            }
//            return valueString;
//        }
//    };
//    
//    
//    template< typename T >
//    T get(variant value) {
//        return value.get<T>();
//    }
//    
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 5: start\n";
//        bool success = true;
//        
//        variant v1( 23 );
//        success = verifie( get< int         >( v1 ) == 23, "QUESTION_5 : get< int         >( v1 ) incorrect" ) && success;
//        success = verifie( get< double      >( v1 ) == 0 , "QUESTION_5 : get< double      >( v1 ) incorrect" ) && success;
//        success = verifie( get< std::string >( v1 ) == "", "QUESTION_5 : get< std::string >( v1 ) incorrect" ) && success;
//        
//        variant v2( -3.14159 );
//        success = verifie( get< int         >( v2 ) == 0       , "QUESTION_5 : get< int         >( v2 ) incorrect" ) && success;
//        success = verifie( get< double      >( v2 ) == -3.14159, "QUESTION_5 : get< double      >( v2 ) incorrect" ) && success;
//        success = verifie( get< std::string >( v2 ) == ""      , "QUESTION_5 : get< std::string >( v2 ) incorrect" ) && success;
//        
//        variant v3( "hello world" );
//        success = verifie( get< int         >( v3 ) == 0            , "QUESTION_5 : get< int         >( v3 ) incorrect" ) && success;
//        success = verifie( get< double      >( v3 ) == 0            , "QUESTION_5 : get< double      >( v3 ) incorrect" ) && success;
//        success = verifie( get< std::string >( v3 ) == "hello world", "QUESTION_5 : get< std::string >( v3 ) incorrect" ) && success;
//        
//        variant v4( v1 );
//        success = verifie( get< int         >( v4 ) == 23, "QUESTION_5 : get< int         >( v4 ) incorrect" ) && success;
//        success = verifie( get< double      >( v4 ) == 0 , "QUESTION_5 : get< double      >( v4 ) incorrect" ) && success;
//        success = verifie( get< std::string >( v4 ) == "", "QUESTION_5 : get< std::string >( v4 ) incorrect" ) && success;
//        
//        v1 = v3;
//        success = verifie( get< int         >( v1 ) == 0            , "QUESTION_5 : get< int         >( v1 ) incorrect apres affectation" ) && success;
//        success = verifie( get< double      >( v1 ) == 0            , "QUESTION_5 : get< double      >( v1 ) incorrect apres affectation" ) && success;
//        success = verifie( get< std::string >( v1 ) == "hello world", "QUESTION_5 : get< std::string >( v1 ) incorrect apres affectation" ) && success;
//        
//        v2 = std::string( "bonjour" );      // La conversion explicite en string est ici nécessaire
//        success = verifie( get< int         >( v2 ) == 0        , "QUESTION_5 : get< int         >( v2 ) incorrect apres affectation" ) && success;
//        success = verifie( get< double      >( v2 ) == 0        , "QUESTION_5 : get< double      >( v2 ) incorrect apres affectation" ) && success;
//        success = verifie( get< std::string >( v2 ) == "bonjour", "QUESTION_5 : get< std::string >( v2 ) incorrect apres affectation" ) && success;
//        
//        success = verifie( v1 == v3, "QUESTION_5 : v1 == v3 faux" ) && success;
//        success = verifie( v1 != v2, "QUESTION_5 : v1 != v2 faux" ) && success;
//        
//        std::cerr << "Test question 5: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_5
//
//#endif  // #ifdef QUESTION_5
//
//#ifdef QUESTION_6
//
//namespace question_6 {
//    /************************************************************************************
//     * QUESTION 6
//     *
//     * Notre variant n'autorise que 3 types bien définis (int, double, std::string) alors
//     * que le variant standard autorise un nombre quelconque de types quelconques.
//     * Nous n'allons pas nous occuper du nombre quelconque de types (qui suppose
//     * l'utilisation de la généricité avec un nombre variable de paramètres), mais nous
//     * allons modifier notre variant pour qu'il puisse autoriser 3 types quelconques.
//     *
//     * Le début de la définition de notre type variant devient donc :
//     *
//     *    template< typename T1, typename T2, typename T3 >
//     *    class variant {
//     *
//     * Nous supposerons que les types T1, T2 et T3 sont tous distincts et se comportent
//     * correctement pour les opérations utilitaires (construction, destruction, affectation,
//     * comparaison)
//     *
//     * La valeur retournée par un accesseur quand le type demandé n'est pas celui actuellement
//     * stocké sera celle obtenu par le constructeur par défaut du type demandé.
//     *
//     * Ne vous préoccupez pas de la comparaison (les tests sont mis en commentaire) tant
//     * que vous n'avez pas une solution fonctionnelle de la classe.
//     * De même, oubliez au départ la forme fonctionnelle de l'accesseur qui nécessite
//     * le même type de syntaxe particulière.
//     ************************************************************************************/
//    
//    /************************************************************************************
//     * VOTRE RÉPONSE (COMMENCEZ PAR RECOPIER LA RÉPONSE À LA QUESTION PRÉCÉDENTE PUIS
//     * MODIFIEZ CELLE-CI)
//     ************************************************************************************/
//    namespace NETypeOfVariant
//    {
//        typedef enum
//        {
//            Type1,
//            Type2,
//            Type3,
//        }ETypeOfVariant;
//    }
//    
//    template< typename T1, typename T2, typename T3 >
//    class variant {
//        
//    public:
//        variant(T1 value) {
//            valueT1 = value;
//            typeOfVariant = NETypeOfVariant::Type1;
//        }
//        
//        variant(T2 value) {
//            valueT2 = value;
//            typeOfVariant = NETypeOfVariant::Type2;
//        }
//        
//        variant(T3 value) {
//            valueT3 = value;
//            typeOfVariant = NETypeOfVariant::Type3;
//        }
//        
//        template< typename T >
//        T get() {
//            return get_aux( T() );
//        }
//        
//        bool operator==(const variant &b) {
//            if (b.typeOfVariant != typeOfVariant) {
//                return false;
//            }
//            switch (typeOfVariant) {
//                case NETypeOfVariant::Type1:
//                    return valueT1 == b.valueT1;
//                case NETypeOfVariant::Type2:
//                    return valueT2 == b.valueT2;
//                case NETypeOfVariant::Type3:
//                    return valueT3 == b.valueT3;
//            }
//        };
//        
//        
//        bool operator!=(const variant &b) {
//            return ! (*this == b);
//        }
//        
//        
//    private:
//        T1 valueT1;
//        T2 valueT2;
//        T3 valueT3;
//        NETypeOfVariant::ETypeOfVariant typeOfVariant;
//        
//        T1 get_aux(T1) {
//            if (typeOfVariant != NETypeOfVariant::Type1) {
//                return T1();
//            }
//            return valueT1;
//        }
//        T2 get_aux(T2) {
//            if (typeOfVariant != NETypeOfVariant::Type2) {
//                return T2();
//            }
//            return valueT2;
//        }
//        T3 get_aux(T3) {
//            if (typeOfVariant != NETypeOfVariant::Type3) {
//                return T3();
//            }
//            return valueT3;
//        }
//    };
//    
//    
//    /************************************************************************************
//     * Programme de test
//     * NE PAS MODIFIER
//     ************************************************************************************/
//    
//    void test()
//    {
//        std::cerr << "Test question 6: start\n";
//        bool success = true;
//        
//        // Pour faciliter la lecture
//        // Si nécessaire, configurer votre compilateur pour qu'il soit au moins au niveau
//        // du standard 2011 de C++
//        using X1 = std::complex< double >;
//        using X2 = int;
//        using X3 = std::pair< std::string, double >;
//        using test_variant = variant< X1, X2, X3 >;
//        const X1 good_x1 = X1( 5, -12 );
//        const X2 good_x2 = X2( 232 );
//        const X3 good_x3 = X3( std::make_pair( "hello", 2.7182818 ));
//        const X1 baad_x1 = X1();
//        const X2 baad_x2 = X2();
//        const X3 baad_x3 = X3();
//        
//        test_variant v1( good_x1 );
//        success = verifie( v1.get< X1 >() == good_x1, "QUESTION_6 : v1.get< X1 >() incorrect" ) && success;
//        success = verifie( v1.get< X2 >() == baad_x2, "QUESTION_6 : v1.get< X2 >() incorrect" ) && success;
//        success = verifie( v1.get< X3 >() == baad_x3, "QUESTION_6 : v1.get< X3 >() incorrect" ) && success;
//        
//        test_variant v2( good_x2 );
//        success = verifie( v2.get< X1 >() == baad_x1, "QUESTION_6 : v2.get< X1 >() incorrect" ) && success;
//        success = verifie( v2.get< X2 >() == good_x2, "QUESTION_6 : v2.get< X2 >() incorrect" ) && success;
//        success = verifie( v2.get< X3 >() == baad_x3, "QUESTION_6 : v2.get< X3 >() incorrect" ) && success;
//        
//        test_variant v3( good_x3 );
//        success = verifie( v3.get< X1 >() == baad_x1, "QUESTION_6 : v3.get< X1 >() incorrect" ) && success;
//        success = verifie( v3.get< X2 >() == baad_x2, "QUESTION_6 : v3.get< X2 >() incorrect" ) && success;
//        success = verifie( v3.get< X3 >() == good_x3, "QUESTION_6 : v3.get< X3 >() incorrect" ) && success;
//        
//        test_variant v4( v1 );
//        success = verifie( v4.get< X1 >() == good_x1, "QUESTION_6 : v4.get< X1 >() incorrect" ) && success;
//        success = verifie( v4.get< X2 >() == baad_x2, "QUESTION_6 : v4.get< X2 >() incorrect" ) && success;
//        success = verifie( v4.get< X3 >() == baad_x3, "QUESTION_6 : v4.get< X3 >() incorrect" ) && success;
//        
//        v1 = v3;
//        success = verifie( v1.get< X1 >() == baad_x1, "QUESTION_6 : v1.get< X1 >() incorrect apres affectation" ) && success;
//        success = verifie( v1.get< X2 >() == baad_x2, "QUESTION_6 : v1.get< X2 >() incorrect apres affectation" ) && success;
//        success = verifie( v1.get< X3 >() == good_x3, "QUESTION_6 : v1.get< X3 >() incorrect apres affectation" ) && success;
//        
//        // Les tests de comparaisons sont désactivés car ils nécessitent
//        // l'utilisation d'une syntaxe très spéciale :
//        // si vous savez par exemple que vos 2 variants v1 et v2 contiennent le même type T1,
//        // il faut écrire pour retourner le résultat de la comparaison des valeurs :
//        //           return v1.template get< T1 >() == v2.template get< T1 >();
//        //
//        // La forme fonctionnelle de l'accesseur nécessite aussi cette syntaxe particulière,
//        // donc le test est aussi désactivé.
//        /*
//         success = verifie( v1 == v3, "QUESTION_6 : v1 == v3 faux" ) && success;
//         success = verifie( v1 != v2, "QUESTION_6 : v1 != v2 faux" ) && success;
//         
//         success = verifie( get< X3 >( v3 ) == good_x3, "QUESTION_6 : get< X3 >( v3 ) incorrect" ) && success;
//         */
//        
//        std::cerr << "Test question 6: end: " << ( success ? "OK" : "KO" ) << "\n";
//    }
//    
//}       // namespace question_6
//
//#endif  // #ifdef QUESTION_6
//
//
///************************************************************************************
// * Programme principal
// * NE PAS MODIFIER
// ************************************************************************************/
////int main()
////{
////    std::cerr << "Début des tests\n";
////    
////#ifdef QUESTION_1
////    question_1::test();
////#endif
////    
////#ifdef QUESTION_2
////    question_2::test();
////#endif
////    
////#ifdef QUESTION_3
////    question_3::test();
////#endif
////    
////#ifdef QUESTION_4
////    question_4::test();
////#endif
////    
////#ifdef QUESTION_5
////    question_5::test();
////#endif
////    
////#ifdef QUESTION_6
////    question_6::test();
////#endif
////    
////    std::cerr << "Fin des tests\n";
////    return 0;
////}

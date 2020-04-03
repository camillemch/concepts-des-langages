//
//  Nombre.cpp
//  exercice5
//
//  Created by Camille Michel on 21/09/2019.
//  Copyright © 2019 Camille Michel. All rights reserved.
//

#include <sstream>
#include <stack>

#include "Nombre.hpp"

bool isinteger(std::string const& n) noexcept{
    if (std::isdigit(n[0]) || (n.size() > 1 && (n[0] == '-' || n[0] == '+')))
    {
        for (std::string::size_type i{ 1 }; i < n.size(); ++i)
            if (!std::isdigit(n[i]))
                return false;
        
        return true;
    }
    return false;
}

int Nombre::nb_instances_ = 0;

int Nombre::nb_instances(){
    return nb_instances_;
}

Nombre::Nombre( unsigned int n ){
    premier_ = nullptr;
    Chiffre * nouveau;
    std::stack< int > sd;
    while (n > 0)
    {
        int digit = n%10;
        n /= 10;
        sd.push(digit);
    }
    while (!sd.empty()){
        nouveau = new Chiffre;
        nouveau->chiffre_ = sd.top();
        nouveau->suivant_ = premier_;
        premier_ = nouveau;
        sd.pop();
    }
    nb_instances_ ++;
}

Nombre::Nombre( std::string s ){
    premier_ = nullptr;
    if (isinteger(s)){
        Chiffre * nouveau;
        for(int i=0; i< s.length() ; i++){
            nouveau = new Chiffre;
            // Conversion car le char renvoyait la valeur ascii
            //  1->49; 2->50 ...
            std::string val;
            val.push_back(s[i]);
            nouveau->chiffre_ = std::stoi(val);
            nouveau->suivant_ = premier_;
            premier_ = nouveau;
        }
    }
    nb_instances_ ++;
}

Nombre::Nombre( const Nombre & n){
//    std::cout << "Construction par copie" << std::endl;
    Chiffre * actuel = n.premier_;
    if (actuel != nullptr){
        dernier_ = premier_ = new Chiffre(actuel->chiffre_);
        for (actuel=actuel->suivant_ ; actuel != nullptr ; actuel=actuel->suivant_){
            dernier_->suivant_= new Chiffre(actuel->chiffre_);
            dernier_ = dernier_->suivant_;
        }
    }
    nb_instances_ ++;
}

Nombre::Nombre(Nombre && n){
    std::cout << "Construction par déplacement" << std::endl;
    premier_ = n.premier_;
    n.premier_ = nullptr;
    nb_instances_ ++;
}

Nombre::~Nombre(){
    Chiffre * ptr = premier_;
    while(ptr!=nullptr){
        Chiffre * tmp = ptr;
        ptr=ptr->suivant_;
        delete tmp;
    }
    nb_instances_ --;
}

Nombre & Nombre::operator=(const Nombre & n)
{
//    std::cout << "Affectation par copie" << std::endl;
    Nombre tmp(n);
    swap(tmp);
    return *this;
}

Nombre & Nombre::operator=( Nombre && n ){
    std::cout << "Affectation par déplacement" << std::endl;
    if (premier_ != n.premier_){
        delete premier_;
        premier_ = n.premier_;
        n.premier_ = nullptr;
    }
    return *this;
}

Nombre & Nombre::operator+=( const int i ){
    Nombre entier(i);
    Chiffre * actuel_int = entier.premier_;
    Chiffre * actuel_nombre = premier_;
    premier_ = nullptr;
    Chiffre * nouveau;
    std::stack< int > sd;
    int reste = 0;
    int somme;
    while (actuel_nombre != nullptr || actuel_int != nullptr){
        if (actuel_nombre != nullptr && actuel_int != nullptr){
            somme = actuel_nombre->chiffre_ + actuel_int->chiffre_ + reste;
            if ( somme >= 10){
                sd.push(somme%10);
                reste = 1;
            }
            else{
                sd.push(somme);
                reste = 0;
            }
            actuel_nombre = actuel_nombre->suivant_;
            actuel_int = actuel_int->suivant_;
        }
        else if (actuel_int == nullptr){
            somme = actuel_nombre->chiffre_ + reste;
            if ( somme >= 10){
                sd.push(somme%10);
                reste = 1;
            }
            else{
                sd.push(somme);
                reste = 0;
            }
            actuel_nombre = actuel_nombre->suivant_;
        }
        else if (actuel_nombre == nullptr){
            somme = actuel_int->chiffre_ + reste;
            if ( somme >= 10){
                sd.push(somme%10);
                reste = 1;
            }
            else{
                sd.push(somme);
                reste = 0;
            }
            actuel_int = actuel_int->suivant_;
        }
    }
    if (reste != 0){
        sd.push(reste);
    }
    while (!sd.empty()){
        nouveau = new Chiffre;
        nouveau->chiffre_ = sd.top();
        nouveau->suivant_ = premier_;
        premier_ = nouveau;
        sd.pop();
    }
    return *this;
}

Nombre Nombre::operator+( const int i ){
    Nombre res = *this;
    return res += i;
}

Nombre & Nombre::operator*=( const int i ){
    Nombre entier(i);
    Chiffre * ret = new Chiffre(0, nullptr);
    Chiffre * res = ret;
    Chiffre * produit = ret;
    Chiffre * num1 = entier.premier_;
    while (num1) {
        produit = res;
        int reste = 0;
        Chiffre* num2 = premier_;
        while (num2) {
            produit->chiffre_ += reste + (num1->chiffre_ * num2->chiffre_);
            if (produit->chiffre_ > 9) {
                reste = produit->chiffre_ / 10;
                produit->chiffre_ = produit->chiffre_ % 10;
            } else
                reste = 0;
            if (!produit->suivant_)
                produit->suivant_ = new Chiffre(0, nullptr);
            produit = produit->suivant_;
            num2 = num2->suivant_;
        }
        if (reste > 0)
            produit->chiffre_ += reste;
        num1 = num1->suivant_;
        res = res->suivant_;
    }
    premier_ = ret;
    // Remove leading 0
    std::ostringstream os;
    os << *this;
    std::string s = os.str();
    s.erase(0, std::min(s.find_first_not_of('0'), s.size()-1));
    Nombre * n = new Nombre(s);
    return *n;
}

Nombre Nombre::operator*( const int i ){
    Nombre res = *this;
    return res *= i;
}

std::ostream & operator<<( std::ostream & out, const Nombre& n ){
    Nombre::Chiffre * actuel = n.premier_;
    std::string s, tmp;
    while (actuel != nullptr)
    {
        tmp = std::to_string(actuel->chiffre_);
        s.append(tmp);
        actuel = actuel->suivant_;
    }
    unsigned long len = s.length();
    for (int i = 0; i < len / 2; i++)
        std::swap(s[i], s[len - i - 1]);
    out << s;
    return out;
}

void Nombre::swap( Nombre & n){
    using std::swap;
    swap(premier_, n.premier_);
}

unsigned int Nombre::getValuePremier() const{
    if (premier_ != nullptr){
        int value = premier_->chiffre_;
        return value;
    }
    return NULL;
}

Nombre factorielle( unsigned int n ){
    if (n == 0){
        return 1;
    }
    return factorielle(n-1) * n;
}

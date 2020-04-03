// StaticLib5.cpp : Définit les fonctions de la bibliothèque statique.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "framework.h"

void Nombre::affiche_nombre(std::ostream& out) const {
	premier_->affiche(out);
}

Nombre::Nombre() {
	premier_ = nullptr;
}

Nombre::Nombre(unsigned int n) {
	std::string str = std::to_string(n);
	premier_ = new Chiffre(str, 0);
}

Nombre::Nombre(std::string s) {
	premier_ = new Chiffre(s, s.size() - 1);
}


Nombre::Nombre(const Nombre & n) {
	premier_ = new Chiffre(*n.premier_);

}

Nombre::Chiffre::Chiffre(const Chiffre & c) {
	chiffre_ = c.chiffre_;
	if (c.suivant_ != nullptr) {
		suivant_ = new Chiffre(*c.suivant_);
	}
	else {
		suivant_ = nullptr;
	}
}

Nombre::Nombre(Nombre&& n) noexcept {
	premier_ = n.premier_;
	n.premier_ = nullptr;
}

Nombre::Chiffre::Chiffre(Chiffre&& c) noexcept{
	chiffre_ = c.chiffre_;
	suivant_ = c.suivant_;
	c.chiffre_ = 0;
	c.suivant_ = nullptr;
}

/*
Nombre& Nombre::operator=(const Nombre& n) {
	if (this != &n) {
		premier_ = new Chiffre(*n.premier_);
	}
	return *this;
}
*/
Nombre& Nombre::operator=(const Nombre& n) {
	if (this != &n) {
		Nombre tmp(n);
		swap(tmp);
	}
	return *this;
}

void Nombre::swap(Nombre& n) {
	using std::swap;
	swap(premier_, n.premier_);
}

Nombre& Nombre::operator=(Nombre&& n) noexcept{
	if (this != &n) {
		premier_ = n.premier_;
		n.premier_ = nullptr;
	}
	return *this;
}

Nombre::Chiffre::Chiffre(std::string s, unsigned int pos) {
	chiffre_ = s[pos] - '0'; //code du digit moins le code du 0 est une conversion de char a int
	if (pos == 0) {
		suivant_ = nullptr;
	}
	else {
		suivant_ = new Chiffre(s, pos - 1);
	}
}

std::ostream& Nombre::Chiffre::affiche(std::ostream& out) const
 {
			Chiffre* c = suivant_;
			if (c != nullptr) {
				c->affiche(out);
			}
			out << chiffre_;
			return out;
		};

void Nombre::operator+=(unsigned int d) 
{
	//premier_ ->operator+=(d);
	*premier_ += d; //meme chose que au-dessus
}

void Nombre::Chiffre::operator+=(unsigned int d)
{
	unsigned int q = (int)(chiffre_ + d) / 10;
	unsigned int r = (int)(chiffre_ + d) % 10;
	chiffre_ = r;
	if (q != 0) {
		if (suivant_ != nullptr) {
			*suivant_ += q;
		}
		else {
			suivant_ = new Chiffre("0", 0);
			*suivant_ += q;
		}
	}
}

void Nombre::operator*=(unsigned int d)
{
	//premier_ ->operator*=(d);
	*premier_ *= d; //meme chose que au-dessus
}

void Nombre::Chiffre::operator*=(unsigned int d)
{
	if (suivant_ != nullptr) {
		*suivant_ *= d;
	}
	unsigned n = chiffre_;
	chiffre_ = 0;
	*this += (n * d);
}

Nombre& Nombre::operator+(unsigned int d) const {
	Nombre* n = new Nombre(*this);
	*n += d;
	return *n;
}

Nombre& Nombre::operator*(unsigned int d) const {
	Nombre* n = new Nombre(*this);
	*n *= d;
	return *n;
}

Nombre factorielle(unsigned int n) {
	if (n > 0) {
		return factorielle(n - 1) * n;
	}
	else {
		return Nombre(1);
	}
}
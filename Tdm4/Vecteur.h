#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include "Matrice.h"
class Vecteur : public Matrice{
public:
	Vecteur();
	Vecteur(int taille);
	Vecteur(int taille, int* tab);
	Vecteur(Matrice vector);

	int& getNbValue();
	int& operator[](const int& ligne) const;
	int operator*(Vecteur& m);
	Matrice operator*(const int& m);

	~Vecteur();
};

#endif
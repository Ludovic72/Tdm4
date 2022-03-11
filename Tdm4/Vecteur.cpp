#include "Vecteur.h"



Vecteur::Vecteur(): Matrice(){}

Vecteur::Vecteur(int taille): Matrice(1, taille){}

Vecteur::Vecteur(int taille, int* tab) : Matrice(1, taille, tab) {}

Vecteur::Vecteur(Matrice vector)
{
	this->m_x = vector.getNbLigne();
	this->m_y = vector.getNbColonne();

	this->m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; i++) {
		this->m_tab[i] = new int[this->m_y];
		for (int j = 0; j < this->m_y; j++) {
			this->m_tab[i][j] = vector.getTab()[i][j];
		}
	}
}

int& Vecteur::getNbValue() {
	return this->m_y;
}

int& Vecteur::operator[](const int& ligne) const
{
	return Matrice::operator[](0)[ligne];
}

int Vecteur::operator*(Vecteur& m)
{
	int resultat = 0;
	for (int i = 0; i < getNbValue(); i++) {
		resultat += this->m_tab[0][i] * m.getTab()[0][i];
	}
	return resultat;
}

Matrice Vecteur::operator*(const int& m)
{
	for (int i = 0; i < this->m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] *= m;
		}
	}
	return *this;

}




Vecteur::~Vecteur()
{
}



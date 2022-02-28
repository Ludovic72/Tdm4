#include "Matrice.h"
#include <iostream>

Matrice::Matrice() {
	this->m_x = 1;
	this->m_y = 1;
	this->m_tab = new int* [m_x];
	*(this->m_tab) = new int[m_y];
	 
	for (int i = 0; i < m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] = 0;
		}
	}
}
Matrice::Matrice(int x,  int y) {
	if (x < 1) {
		this->m_x = 1;
	}
	else {
		this->m_x = x;
	}
	if (y < 1) {
		this->m_y = 1;
	}
	else {
		this->m_y = y;
	}
	this->m_tab = new int* [m_x];
	for (int i = 0; i < m_x; i++) {
		this->m_tab[i] = new int[m_y];
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] = 0;
		}
	}
}
Matrice::Matrice(int x, int y, int* tab) {
	if (x < 1) {
		this->m_x = 1;
	}
	else {
		this->m_x = x;
	}
	if (y < 1) {
		this->m_y = 1;
	}
	else {
		this->m_y = y;
	}
	int c=0;
	this->m_tab = new int* [m_x];
	for (int i = 0; i < m_x; i++) {
		this->m_tab[i] = new int[m_y];
		for (int k = 0; k < this->m_y; k++) {	
			this->m_tab[i][k] = tab[c++];
			
		}
	}
}
Matrice::Matrice(const Matrice& mat) {
	this->m_x = mat.m_x;
	this->m_y = mat.m_y;

	this->m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; i++) {
		this->m_tab[i] = new int[this->m_y];
	}
	for (int i = 0; i < mat.m_x; i++) {
		for (int k = 0; k < mat.m_y; k++) {
			this->m_tab[i][k] = mat.m_tab[i][k];
		}
	}
}

void const Matrice::affiche()const {
	std::cout << "Matrice :" << std::endl;
	for (int i = 0; i < this->m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			std::cout << this->m_tab[i][k] << " ";
		}
		std::cout << std::endl;
	}
}
int Matrice::getNbLigne()const{
	return this->m_x;
}
int Matrice::getNbColonne()const
{
	return this->m_y;
}
int** Matrice::getTab() const
{
	return this->m_tab;
}

const int& Matrice::getValue(int x, int y)
{
	if ((this->m_x <= x || this->m_y <= y)&& (1 >= x || 1 >= y)) {
		std::cout << "ERREUR dans les valeurs voici la première case de la matrice" << std::endl;
		x = 1;
		y = 1;
	}

	return this->m_tab[x][y];
}
void Matrice::setValue(int x, int y, int num)
{
	if ((this->m_x <= x || this->m_y <= y) && (1 >= x || 1 >= y)) {
		std::cout << "ERREUR dans les valeurs aucune modification" << std::endl;
	}

	this->m_tab[x][y] = num;
}

void Matrice::affectation(Matrice& m1) {
	this->m_x = m1.m_x;
	this->m_y = m1.m_y;
	this->m_tab = new int* [m1.m_x];
	for (int i = 0; i < m1.m_x; i++) {
		this->m_tab[i] = new int[m1.m_y];
		for (int k = 0; k < m1.m_y; k++) {
			this->m_tab[i][k] = m1.m_tab[i][k];
		}
	}
}
int Matrice::different(Matrice& m1) {
	if (this->m_x != m1.m_x) {
		return 1;
	}
	if (this->m_y != m1.m_y) {
		return 1;
	}
	
	for (int i = 0; i < m1.m_x; i++) {
		for (int k = 0; k < m1.m_y; k++) {
			if (this->m_tab[i][k] != m1.m_tab[i][k]) {
				return 1;
			}
		}
	}
	return 0;
}
int Matrice::egal(Matrice& m1) {
	if (this->m_x != m1.m_x) {
		return 0;
	}
	if (this->m_y != m1.m_y) {
		return 0;
	}

	for (int i = 0; i < m1.m_x; i++) {
		for (int k = 0; k < m1.m_y; k++) {
			if (this->m_tab[i][k] != m1.m_tab[i][k]) {
				return 0;
			}
		}
	}
	return 1;
}
int& Matrice::value(int x, int y) {
	return this->m_tab[x][y];
}


void Matrice::multiplication(int nombre) {
	for (int i = 0; i < this->m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] *= nombre;
		}
	}
}
void Matrice::addition(Matrice& m1, Matrice& m3) {
	if (m1.m_x != m3.m_x) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return;
	}
	if (m1.m_y != m3.m_y) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return;
	}
	this->m_tab = new int* [m1.m_x];
	for (int i = 0; i < m1.m_x; i++) {
		this->m_tab[i] = new int[m1.m_y];
	}

	for (int i = 0; i < m1.m_x; i++) {
		for (int k = 0; k < m1.m_y; k++) {
			this->m_tab[i][k] = m1.m_tab[i][k]+ m3.m_tab[i][k];
		}
	}
}
void Matrice::soustraction(Matrice& m3, Matrice& m1) {
	if (m1.m_x != m3.m_x) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return;
	}
	if (m1.m_y != m3.m_y) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return;
	}
	this->m_tab = new int* [m1.m_x];
	for (int i = 0; i < m1.m_x; i++) {
		this->m_tab[i] = new int[m1.m_y];
	}
	for (int i = 0; i < m1.m_x; i++) {
		for (int k = 0; k < m1.m_y; k++) {
			this->m_tab[i][k] = m3.m_tab[i][k] - m1.m_tab[i][k];
		}
	}
}
void Matrice::multiplication(Matrice& m1, Matrice& m2) {
	if (m1.m_x < m2.m_x) {
		this->m_x = m1.m_x;
	}
	else {
		this->m_x = m2.m_x;
	}
	if (m1.m_y < m2.m_y) {
		this->m_y = m1.m_y;
	}
	else {
		this->m_y = m2.m_y;
	}


	this->m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; i++) {
		this->m_tab[i] = new int[this->m_y];
	}
	
	
	for (int i = 0; i < m1.m_x; i++) {
		for (int j = 0; j < m2.m_y; j++) {
			this->m_tab[i][j] = 0;
			for (int k = 0; k < m1.m_y; k++){
				this->m_tab[i][j] += m1.m_tab[i][k] * m2.m_tab[k][j];
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Matrice& m)
{
	os << "Matrice :" << std::endl;
	for (int i = 0; i < m.getNbLigne(); i++) {
		for (int k = 0; k < m.getNbColonne(); k++) {
			os << m[i][k] << " ";
		}
		os << std::endl;
	}
	
	return os;
	
}
int* Matrice::operator[](const int& ligne) const
{
	
	return this->m_tab[ligne];
}

Matrice& Matrice::operator=(const Matrice& mat) {
	this->m_y = mat.m_y;
	this->m_x = mat.m_x;
	this->m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; ++i) { 
		this->m_tab[i] = new int[this->m_y];
	}

	for (int i = 0; i < this->m_x; ++i) {
		for (int j = 0; j < this->m_y; ++j) {
			this->m_tab[i][j] = mat.m_tab[i][j];
		}
	}
	return *this;
}
bool Matrice::operator==(const Matrice& m) const{

	for (int i = 0; i < m.getNbLigne(); i++) {
		for (int k = 0; k < m.getNbColonne(); k++) {
			if (this->m_tab[i][k] != m[i][k]) {
				return false;
			}
		}
	}

	return true;
}
bool Matrice::operator!=(const Matrice& m) const {

	return !this->operator==(m);
}

Matrice Matrice::operator+(const Matrice& m) {
	Matrice result;
	if (this->m_x != m.m_x) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return result;
	}
	if (this->m_y != m.m_y) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return result;
	}
	result.m_tab = new int* [m.m_x];
	for (int i = 0; i < m.m_x; i++) {
		result.m_tab[i] = new int[this->m_y];
	}

	for (int i = 0; i < m.m_x; i++) {
		for (int k = 0; k <m.m_y; k++) {
			result.m_tab[i][k] = this->m_tab[i][k] + m.m_tab[i][k];
		}
	}

	result.m_x = m.m_x;
	result.m_y = m.m_y;
	return result;
}
Matrice Matrice::operator-(const Matrice& m) {
	Matrice result;
	if (this->m_x != m.m_x) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return result;
	}
	if (this->m_y != m.m_y) {
		std::cout << "ERREUR les matrices ne sont pas de même base" << std::endl;
		return result;
	}
	result.m_tab = new int* [m.m_x];
	for (int i = 0; i < m.m_x; i++) {
		result.m_tab[i] = new int[this->m_y];
	}

	for (int i = 0; i < this->m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			result.m_tab[i][k] = this->m_tab[i][k] - m.m_tab[i][k];
		}
	}
	result.m_x = m.m_x;
	result.m_y = m.m_y;
	return result;
}
Matrice Matrice::operator*(const Matrice& m) {
	Matrice result;
	if (this->m_x < m.m_x) {
		result.m_x = this->m_x;
	}
	else {
		result.m_x = m.m_x;
	}
	if (this->m_y < m.m_y) {
		result.m_y = this->m_y;
	}
	else {
		result.m_y = m.m_y;
	}


	result.m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; i++) {
		result.m_tab[i] = new int[this->m_y];
	}


	for (int i = 0; i < this->m_x; i++) {
		for (int j = 0; j < m.m_y; j++) {
			result.m_tab[i][j] = 0;
			for (int k = 0; k < this->m_y; k++) {
				result.m_tab[i][j] += this->m_tab[i][k] * m.m_tab[k][j];
			}
		}
	}
	return result;
}
Matrice Matrice::operator*(const int& m) {
	for (int i = 0; i < this->m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] *= m;
		}
	}
	return *this;
}

Matrice::~Matrice() {

	for (int i = 0; i < m_x; i++) {
		delete[] m_tab[i];
	}
	delete[] m_tab;
	this->m_tab = NULL;
}

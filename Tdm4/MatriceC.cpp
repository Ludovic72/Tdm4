#include "MatriceC.h"

MatriceC::MatriceC(){
	this->m_x = 1;
	this->m_y = 1;
	this->m_tab = new int* [m_x];
	*(this->m_tab) = new int[m_y];
	for (int i = 0; i < m_x; i++) {
		for (int k = 0; k < this->m_y; k++) {
			this->m_tab[i][k] = 1;
		}
	}
}

MatriceC::MatriceC(int ligne, int* tab) {

	this->m_x = ligne;
	this->m_y = ligne;
	this->m_tab = new int* [this->m_x];
	int c = 0;
	for (int i = 0; i < ligne; i++) {
		this->m_tab[i] = new int[this->m_y];
		for (int j = 0; j < ligne; j++) {
			this->m_tab[i][j] = tab[c];
			c++;
		}
	}
}

MatriceC::MatriceC(const Matrice& mat)
{
	this->m_x = mat.getNbLigne();
	this->m_y = mat.getNbLigne();

	this->m_tab = new int* [this->m_x];
	for (int i = 0; i < this->m_x; i++) {
		this->m_tab[i] = new int[this->m_y];
		for (int j = 0; j < this->m_y; j++) {
			this->m_tab[i][j] = mat.getTab()[i][j];
		}
	}
}

MatriceC::~MatriceC(){
	
}




#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
class Matrice {
public:
	Matrice();
	Matrice(int x, int y);
	Matrice(int x, int y, int* tab);
	Matrice(const Matrice& mat);
	void const affiche()const;


	int getNbLigne() const;
	int getNbColonne() const;
	int** getTab()const;

	const int& getValue(int x, int y);
	void setValue(int x, int y, int num);

	void affectation(Matrice& m1);
	int different(Matrice& m1);
	int egal(Matrice& m1);
	int& value(int x, int y);

	void multiplication(int nombre);
	void addition(Matrice& m1, Matrice& m3);
	void soustraction(Matrice& m3, Matrice& m1);
	void multiplication(Matrice& m1, Matrice& m2);

	friend std::ostream& operator<<(std::ostream& os, const Matrice& m);
	int* operator[](const int& ligne)const;

	Matrice& operator=(const Matrice& m);
	bool operator==(const Matrice& m)const;
	bool operator!=(const Matrice& m)const;
	
	Matrice operator+(const Matrice& m);
	Matrice operator-(const Matrice& m);
	Matrice operator*(const Matrice& m);
	Matrice operator*(const int& m);

	
	virtual ~Matrice();
	
protected:
	int m_x;
	int m_y;
	int** m_tab;
};

#endif
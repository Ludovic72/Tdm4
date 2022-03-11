#ifndef MATRICEC_H
#define MATRICEC_H
#include <iostream>
#include "Matrice.h"
class MatriceC : public Matrice{
public:
	MatriceC();
	MatriceC(int ligne, int* tab);
	MatriceC(const Matrice& mat);



	~MatriceC();
};
#endif
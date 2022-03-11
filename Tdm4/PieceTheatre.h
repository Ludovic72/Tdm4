#ifndef PieceTheatre_h
#define PieceTheatre_h

#include "Spectacle.h"
#include <string.h>
#include <iostream>

class PieceTheatre : public Spectacle {
public:
	PieceTheatre() = default;
	PieceTheatre(std::string name, std::string style, float duree);
	PieceTheatre(const PieceTheatre& pt);
	std::string style();
	float duree();
	std::string& type();
	void synthese();

private:
	std::string m_style;
	float m_duree;
};

#endif
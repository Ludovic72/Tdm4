#include "PieceTheatre.h"

PieceTheatre::PieceTheatre(std::string name, std::string style, float duree)
{
	this->m_name = name;
	this->m_style = style;
	this->m_duree = duree;
	this->m_type = "Piece de theatre";
}

PieceTheatre::PieceTheatre(const PieceTheatre& pt)
{

	this->m_name = pt.m_name;
	this->m_nb_Date = pt.m_nb_Date;
	this->m_duree = pt.m_duree;
	this->m_style = pt.m_style;
	this->m_prix = pt.m_prix;
	this->m_type = pt.m_type;
	
	for (int i = 0; i < this->m_nb_Date; i++) {
		this->m_LAD[i].m_date = pt.m_LAD[i].m_date;
		this->m_LAD[i].m_lieux = pt.m_LAD[i].m_lieux;
	}
}

std::string PieceTheatre::style()
{
	return this->m_style;
}

float PieceTheatre::duree()
{
	return this->m_duree;
}

std::string& PieceTheatre::type() {
	return this->m_type;
}


void PieceTheatre::synthese()
{

	std::cout << "Style: " << this->m_style << ". duree: " << this->m_duree << std::endl;
	Spectacle::synthese();
}

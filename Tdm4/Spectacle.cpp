#include "Spectacle.h"
#include "Concert.h"
#include "Match.h"
#include "PieceTheatre.h"
Spectacle::Spectacle(){
	this->m_name = "indefinie";
	this->m_type = "indefinie";
	this->m_nb_Date = 0;

	for (int i = 0; i < m_nb_Date; i++) {
		this->m_LAD[i].m_lieux = "";
		this->m_LAD[i].m_date = "";
	}
}

Spectacle::Spectacle(std::string name){
	this->m_name = name;
	this->m_type = "indefinie";
	this->m_nb_Date = 0;
	
	for (int i = 0; i < m_nb_Date; i++) {
		this->m_LAD[i].m_lieux = "";
		this->m_LAD[i].m_date = "";
	}
}

Spectacle::Spectacle(Spectacle& s){
	
	this->m_name = s.m_name;
	this->m_nb_Date = s.m_nb_Date;
	this->m_prix = s.m_prix;
	this->m_type = s.m_type;

	for (int i = 0; i < s.m_nb_Date; i++) {
		this->m_LAD[i].m_lieux = s.m_LAD[i].m_lieux;
		this->m_LAD[i].m_date = s.m_LAD[i].m_date;
	}
}

std::string& Spectacle::nom()
{
	return this->m_name;
	
}

std::string Spectacle::lieu(std::string date)
{

	for (int i = 0; i < this->m_nb_Date; i++) {
		if (this->m_LAD[i].m_date == date) {
			return this->m_LAD[i].m_lieux;
		}
	}
	std::string lieux = "Pas de lieu pour cette date";
	return lieux;
}

void Spectacle::ajoutDate(std::string lieu, std::string date){

	if (this->m_nb_Date < nbDateSpectacle) {
		m_LAD[m_nb_Date].m_lieux = lieu;
		m_LAD[m_nb_Date].m_date = date;
		this->m_nb_Date++;
	}
	else {
		std::cout << "trop de date en cours veuillez supprimer des spectacles avant de poursuivres" << std::endl;
	}
}

int Spectacle::nbDate()
{
	return this->m_nb_Date;
}

int& Spectacle::tarif()
{
	return this->m_prix;
}

void Spectacle::synthese(){
	std::cout << "Nom: " << this->m_name << ", type: " << this->m_type << ". nb dates:" << " " << this->m_nb_Date << std::endl;
	for (int i = 0; i < m_nb_Date; i++) {
		std::cout << this->m_LAD[i].m_date << " " << this->m_LAD[i].m_lieux << std::endl;
	}
}


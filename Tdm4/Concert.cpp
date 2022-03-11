#include "Concert.h"

Concert::Concert() 
{
	
	
	this->m_type = "Concert";

}

Concert::Concert(std::string name, std::string genre, std::string nomTournee) {
	this->m_name = name;
	this->m_type = "Concert";
	this->m_genre = genre;
	this->m_nomTournee = nomTournee;
	for (int i = 0; i < m_nb_Date; i++) {
		this->m_LAD[i].m_lieux = "";
		this->m_LAD[i].m_date = "";
	}
}

Concert::Concert(const Concert& c) {
	this->m_name = c.m_name;
	this->m_genre = c.m_genre;
	this->m_nb_Date = c.m_nb_Date;
	this->m_nomTournee = c.m_nomTournee;
	this->m_prix = c.m_prix;
	this->m_type = c.m_type;
	for (int i = 0; i < this->m_nb_Date; i++) {
		this->m_LAD[i].m_date = c.m_LAD[i].m_date;
		this->m_LAD[i].m_lieux = c.m_LAD[i].m_lieux;
	}
}
std::string& Concert::type(){
	return this->m_type;
}

std::string& Concert::genre()
{
	return this->m_genre;
	
}

std::string& Concert::nomTournee()
{
	return this->m_nomTournee;
}

void Concert::synthese()
{
	std::cout << "Nom de la tournee: " << this->m_nomTournee << ", genre: " << this->m_genre << std::endl;
	Spectacle::synthese();

}


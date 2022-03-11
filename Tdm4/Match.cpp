#include"Match.h"

Match::Match(std::string equipe1, std::string equipe2, std::string sport, std::string typeCompetition)
{
	this->m_name = equipe1 + " VS " + equipe2;
	this->m_equipe1 = equipe1;
	this->m_equipe2 = equipe2;
	this->m_type = "Sport";
	this->m_sport = sport;
	this->m_typeCompetition = typeCompetition;
	for (int i = 0; i < m_nb_Date; i++) {
		this->m_LAD[i].m_lieux = "";
		this->m_LAD[i].m_date = "";
	}
}

Match::Match(const Match& m)
{
	
	this->m_name = m.m_name;
	this->m_sport = m.m_sport;
	this->m_nb_Date = m.m_nb_Date;
	this->m_equipe1= m.m_equipe1;
	this->m_equipe2 = m.m_equipe2;
	this->m_prix = m.m_prix;
	this->m_type = m.m_type;
	this->m_typeCompetition = m.m_typeCompetition;
	for (int i = 0; i < this->m_nb_Date; i++) {
		this->m_LAD[i].m_date = m.m_LAD[i].m_date;
		this->m_LAD[i].m_lieux = m.m_LAD[i].m_lieux;
	}
}
void Match::ajoutDate(std::string lieu, std::string date){
	if (this->m_nb_Date < 1) {
		m_LAD[m_nb_Date].m_lieux = lieu;
		m_LAD[m_nb_Date].m_date = date;
		this->m_nb_Date++;
	}
	else {
		std::cout << "trop de date en cours veuillez supprimer des spectacles avant de poursuivres" << std::endl;
	}
}
std::string& Match::type()
{
	return this->m_type;
}

std::string& Match::sport()
{
	return this->m_sport;
}

std::string& Match::equipe1()
{
	return this->m_equipe1;
}

std::string& Match::equipe2()
{
	return this->m_equipe2;
}

std::string& Match::typeCompetition()
{
	return this->m_typeCompetition;
}


void Match::synthese()
{
	
	std::cout << "Sport: " << this->m_sport << ", competition: " << this->m_typeCompetition << std::endl;
	Spectacle::synthese();

}
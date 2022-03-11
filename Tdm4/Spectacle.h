
#ifndef Spectacle_h
#define Spectacle_h

#include <string>
#include"LAD.h"
#define nbDateSpectacle 100


class Spectacle {

public:
	
	
	Spectacle();
	Spectacle(std::string name);
	Spectacle(Spectacle& s);
	std::string& nom();
	virtual std::string& type()= 0;
	std::string lieu(std::string date);
	void ajoutDate(std::string lieu, std::string date);
	
	int nbDate();
	int& tarif();
	virtual void synthese();
	
protected:
	std::string m_type="";
	std::string m_name="";
	int m_nb_Date=0;
	int m_prix=0;
	lieuAndDate m_LAD[nbDateSpectacle];
	
};

#endif __Spectacle_h__

#ifndef Match_h
#define Match_h

#include "Spectacle.h"
#include <string.h>
#include <iostream>

class Match : public Spectacle {
public:
	Match() = default;
	Match(std::string equipe1, std::string equipe2, std::string type, std::string sport);
	Match(const Match& m);
	std::string& type();
	std::string& sport();
	std::string& equipe1();
	std::string& equipe2();
	std::string& typeCompetition();
	void ajoutDate(std::string lieu, std::string date);
	void synthese();

private:
	std::string m_sport;
	std::string m_equipe1;
	std::string m_equipe2;
	std::string m_typeCompetition;
};

#endif // !Match_h


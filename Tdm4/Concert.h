#ifndef __Concert_h__
#define __Concert_h__
#include "Spectacle.h"
#include <string>
#include <iostream>

class Concert: public Spectacle {

public:

	Concert();
	Concert(std::string name, std::string genre, std::string nomTournee);
	Concert(const Concert& s);
	std::string& type();
	std::string& genre();
	std::string& nomTournee();
	void synthese();

private:
	std::string m_nomTournee;
	std::string m_genre;
	
};



#endif // !1


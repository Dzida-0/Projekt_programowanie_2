#include <string>
#pragma once

using namespace std;
class Data
{
private:
	std::string imie, imie_zle, nazwisko, nazwisko_zle;
	char plec;
	float prawdopod_poprawnosci_danych = 0.5;

public:
	bool poprawnosc_danych;
	std::string* utworz_osobe();

};

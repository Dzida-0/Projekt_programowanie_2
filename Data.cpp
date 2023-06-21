#include "Data.h"
#include "sqlite3/sqlite3.h"
#include <cstdlib>
#include <ctime>

std::string* Data::utworz_osobe()
{
	sqlite3* baza;
	sqlite3_stmt* stmt;
	std::srand(std::time(nullptr));
	//
	sqlite3_open("BazaDanych.db", &baza);
	sqlite3_prepare_v2(baza, "select imie_m,imie_m_zle,imie_k,imie_k_zle from imiona", -1, &stmt, NULL);
	int row = (std::rand() % 95) / 5 + 1;
	for (int i = 0; i < row; i++)
		sqlite3_step(stmt);
	if (std::rand() % 100 < 50)
	{
		imie = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		imie_zle = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		plec = 'M';
	}
	else
	{
		imie = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		imie_zle = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		plec = 'K';
	}
	sqlite3_prepare_v2(baza, "select nazwisko, nazwisko_zle from nazwiska", -1, &stmt, NULL);
	row = (std::rand() % 95) / 5 + 1;
	for (int i = 0; i < row; i++)
		sqlite3_step(stmt);
	nazwisko = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
	nazwisko_zle = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
	sqlite3_close(baza);

	std::string* ret = new std::string[6];
	std::srand(std::time(nullptr));
	if (nazwisko[nazwisko.length() - 1] == '-')
	{
		if (plec == 'K')
		{
			nazwisko[nazwisko.length() - 1] = 'a';
			nazwisko_zle[nazwisko_zle.length() - 1] = 'a';
		}
		else
		{
			nazwisko[nazwisko.length() - 1] = 'i';
			nazwisko_zle[nazwisko_zle.length() - 1] = 'i';
		}
	}
	
	ret[0] = imie;
	ret[1] = imie;
	ret[2] = nazwisko;
	ret[3] = nazwisko;
	std::string x = std::to_string(std::rand() % 31 + 1) + "." + std::to_string(std::rand() % 12 + 1) + "." + std::to_string(std::rand() % 40 + 1950);
	ret[4] = x;
	ret[5] = x;
	poprawnosc_danych = true;
	if (std::rand() % 99 < 100 * prawdopod_poprawnosci_danych)
	{
		poprawnosc_danych = false;
		if (std::rand() % 99 < 50)//czy
		{
			if (std::rand() % 99 < 50)//ktory
			{
				ret[0] = imie_zle;
				ret[1] = imie;
			}
			else
			{
				ret[0] = imie;
				ret[1] = imie_zle;
			}
		}
		if (std::rand() % 99 < 50)//czy
		{
			if (std::rand() % 99 < 50)//ktory
			{
				ret[2] = nazwisko_zle;
				ret[3] = nazwisko;
			}
			else
			{
				ret[2] = nazwisko;
				ret[3] = nazwisko_zle;
			}
		}
		if (std::rand() % 99 < 50)//czy
		{
			std::string z="", y="";
			while (z == y)
			{
				z = std::to_string(std::rand() % 31 + 1) + "." + std::to_string(std::rand() % 12 + 1) + "." + std::to_string(std::rand() % 40 + 1950);
				y = std::to_string(std::rand() % 31 + 1) + "." + std::to_string(std::rand() % 12 + 1) + "." + std::to_string(std::rand() % 40 + 1950);
			}
			ret[4] = z;
			ret[5] = y;
		}
	}
	return ret;
}

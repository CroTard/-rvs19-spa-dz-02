#pragma once
#include"UI.h"
#include"Kocke.h"

struct Pauza
{
public:
	Pauza(bool pause)
	{
		pauza = pause;
	};

	bool set_pause(UI& ui)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			pauza = !pauza;

			ui.pauza_goomb = !ui.pauza_goomb;
		}

		return pauza;
	};

	bool pauza = true;
};

void reset_kocke(std::vector<std::vector<Kvadrat>>& world, sf::RenderWindow& window, Pauza& P, UI& ui)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		ui.reset_goomb = !ui.reset_goomb;
		ui.reset_goomb = !ui.reset_goomb;
		ui.brojac = 0;

		for (unsigned __int64 i = 0; i < world.size(); i++)
		{
			for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
			{
				world.at(i).at(j).set_ziv(false);
			}
		}
	}
}

void ispis_texta() {
	std::cout << "		Conway's Game of Life" << std::endl << "	    	  by Martin Majeric" << std::endl << std::endl;

	std::cout << "Moze se kliktati i po user interface-u." << std::endl << std::endl;

	std::cout << "Kada je igra pauzirana moze se koristiti mis i crtati po gridu. (vidi gumb START dali je utisnut ili ne...)" << std::endl;
	std::cout << "Lijevi klik - stvori " << std::endl;
	std::cout << "Desni klik - izbrisi" << std::endl << std::endl;

	std::cout << "Reset gumb na UI-u postepeno brise stanice, ovisi koliko dugo se drzi. " << std::endl;

	std::cout << "Inc gumb usporava tj. ubrzava igru za 200ms po kliku. (!Usporava sve radnje pa tako i reakcije na druge gumbe!)" << std::endl << std::endl;

	std::cout << "0 - stvara nove random stanice - 25%" << std::endl;
	std::cout << "1 - demo raznih oblika - (!resetiraj za najbolji efekt!)" << std::endl;
	std::cout << "2 - demo raznih oblika " << std::endl;
	std::cout << "3 - demo raznih oblika " << std::endl << std::endl;

	std::cout << "-- Tipkovnica -- " << std::endl;
	std::cout << "Space - pauze " << std::endl;
	std::cout << "    R - reset " << std::endl << std::endl;
}

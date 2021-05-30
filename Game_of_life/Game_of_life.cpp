#include<SFML/Graphics.hpp>
#include<SFML/System/clock.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window/Mouse.hpp>

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

#include"Kocke.h"
#include"World_pushback.h"
#include"Mouse.h"
#include"Susjedi.h"
#include"funkcije.h"
#include"UI.h"

using namespace sf;
using namespace std;

int main()
{
	ispis_texta();

	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Game of life!");

	UI ui(&window);

	window.setFramerateLimit(60);

	//world_pushback() kreira kocke u multid vektor
	//kopiranje vektora u novi - copy elision - nedam se

	std::vector<std::vector<Kvadrat>>* world = new std::vector<std::vector<Kvadrat>>;
	std::vector<std::vector<Kvadrat>> copy(world_pushback());

	*world = copy;

	long count = 0;

	bool pause = true;

	Pauza P(pause);

	while (window.isOpen())
	{
		int brojac = 0;
		sf::Event event;
		sf::View view;
		window.setKeyRepeatEnabled(false);

		window.setView(view);

		window.clear();

		while (window.pollEvent(event))
		{
			//pomicanje misa - kliktanje mijenja vrijednost boje

			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				mouse_button_pressed(window, *world, ui, event);
			}
			else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				mouse_button_released(window, *world, ui, event);
			}
		}

		ui.draw();
		pause = P.set_pause(ui);
		mouse_move(window, *world, ui, event);
		reset_kocke(*world, window, P, ui);

		int sw = 0;

		if (pause == false || ui.pauza_goomb == false)
		{
			sw = 2;
		}
		if (ui.reset_goomb == false)
		{
			sw = 1;
		}

		std::vector<std::vector<Kvadrat>> new_gen(*world);

		switch (sw)
		{
		case 1:
			//brise plocu - postepeno - nez zasto neda mi se istrazivat - its a feature
			for (unsigned __int64 i = 0; i < world->size(); i++)
			{
				for (unsigned __int64 j = 0; j < world->at(i).size(); j++)
				{
					world->at(i).at(j).set_ziv(false);
				}
			}

		case 2:

			//Crtanje multid. vektora

			for (unsigned __int64 i = 1; i < new_gen.size() - 1; i++)
			{
				for (unsigned __int64 j = 1; j < new_gen.at(i).size() - 1; j++)
				{
					//Susjedi - pravilo returna broj susjeda od vektora

					if (new_gen.at(i).at(j).ziv == true && susjedi_funk(new_gen, i, j) < 2 || susjedi_funk(new_gen, i, j) > 3)
					{
						world->at(i).at(j).set_ziv(false);
						world->at(i).at(j).set_color();
					}

					if (new_gen.at(i).at(j).ziv == false && susjedi_funk_ded(new_gen, i, j) == 3)
					{
						world->at(i).at(j).set_ziv(true);
						world->at(i).at(j).set_color();
					}
				}
			}

		default:
			for (unsigned __int64 i = 1; i < world->size() - 1; i++)
			{
				for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
				{
					if (world->at(i).at(j).ziv == true)
					{
						brojac++;
						ui.set_brojac(brojac);
					}
					window.draw(world->at(i).at(j).kocka);
				}
			}
			break;
		}

		sf::Time Sleep = sf::milliseconds(ui.inc_broj_ret());
		sleep(Sleep);

		//std::cout << std::endl;
		//cout << brojac << endl;
		window.display();
	}

	delete world;

	return 0;
}
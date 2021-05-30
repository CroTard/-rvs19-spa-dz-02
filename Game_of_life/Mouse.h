#pragma once

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window/Mouse.hpp>
#include<SFML/System/clock.hpp>
#include<SFML/Audio.hpp>
#include"Kocke.h"
#include"UI.h"

using namespace sf;

void mouse_move(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, UI& ui, sf::Event& event)
{
	Vector2i mouse_poz = Mouse::getPosition(window);
	Vector2f world_poz = window.mapPixelToCoords(mouse_poz);

	bool Mouse_klik_L = Mouse::isButtonPressed(Mouse::Button::Left);
	bool Mouse_klik_R = Mouse::isButtonPressed(Mouse::Button::Right);

	for (unsigned __int64 i = 1; i < world.size() - 1; i++)

	{
		for (unsigned __int64 j = 1; j < world.at(i).size() - 1; j++)
		{
			if (world.at(i).at(j).kocka.getGlobalBounds().contains(world_poz.x, world_poz.y))
			{
				if (Mouse_klik_L)
				{
					//world.at(i).at(j).kocka.setFillColor(Color(255, 0, 0));
					world.at(i).at(j).set_ziv(true);
					world.at(i).at(j).set_color();

					//std::cout << "world.at(" << i << ").at(" << j << ").set_ziv(true);" << std::endl;
				}
				else if (Mouse_klik_R)
				{
					//	world.at(i).at(j).kocka.setFillColor(Color(255, 255, 255));
					world.at(i).at(j).set_ziv(false);
					world.at(i).at(j).set_color();
					//std::cout << "	Redak: J	" << j << "	Stupac: i	" << i << std::endl;
				}
			}
		}
	}
};
void mouse_button_released(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, UI& ui, sf::Event& event)
{
	Vector2i mouse_poz = Mouse::getPosition(window);
	Vector2f world_poz = window.mapPixelToCoords(mouse_poz);

	//std::cout << "x: " << mouse_poz.x << "	y: 	" << mouse_poz.y << std::endl;

	if (ui.gumb_pauza_placeholder.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		ui.pauza_goomb = !ui.pauza_goomb;
	}

	if (ui.gumb_reset_placeholder.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		ui.reset_goomb = true;
		ui.brojac = 0;
	}
	if (ui.gumb_inc_R_placeholder.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		ui.gumb_inc_broj -= 200;
	}

	if (ui.gumb_inc_L_placeholder.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		ui.gumb_inc_broj += 200;
	}

	if (ui.demo0.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		srand(time(nullptr));
		for (unsigned __int64 i = 0; i < world.size(); i++)
		{
			for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
			{
				int broj = rand() % 4 + 1;

				if (broj == 1 && world.at(i).at(j).granicni == false)
				{
					world.at(i).at(j).set_ziv(true);
					world.at(i).at(j).set_color();
				}
				else
				{
					world.at(i).at(j).set_ziv(false);
					world.at(i).at(j).set_color();
				}
			}
		}
	}
	if (ui.demo1.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		world.at(1).at(7).set_ziv(true);
		world.at(1).at(8).set_ziv(true);
		world.at(2).at(7).set_ziv(true);
		world.at(2).at(8).set_ziv(true);

		world.at(11).at(7).set_ziv(true);
		world.at(11).at(8).set_ziv(true);
		world.at(11).at(9).set_ziv(true);
		world.at(12).at(6).set_ziv(true);
		world.at(12).at(10).set_ziv(true);

		world.at(15).at(8).set_ziv(true);
		world.at(16).at(6).set_ziv(true);

		world.at(17).at(7).set_ziv(true);
		world.at(17).at(8).set_ziv(true);
		world.at(17).at(9).set_ziv(true);

		world.at(16).at(10).set_ziv(true);
		world.at(18).at(8).set_ziv(true);

		world.at(21).at(7).set_ziv(true);
		world.at(21).at(6).set_ziv(true);
		world.at(21).at(5).set_ziv(true);

		world.at(22).at(7).set_ziv(true);
		world.at(22).at(6).set_ziv(true);
		world.at(22).at(5).set_ziv(true);

		world.at(23).at(4).set_ziv(true);
		world.at(23).at(8).set_ziv(true);

		world.at(25).at(3).set_ziv(true);
		world.at(25).at(4).set_ziv(true);
		world.at(25).at(8).set_ziv(true);
		world.at(25).at(9).set_ziv(true);

		world.at(35).at(5).set_ziv(true);
		world.at(35).at(6).set_ziv(true);
		world.at(36).at(5).set_ziv(true);
		world.at(36).at(6).set_ziv(true);

		world.at(13).at(5).set_ziv(true);
		world.at(13).at(11).set_ziv(true);
		world.at(14).at(5).set_ziv(true);
		world.at(14).at(11).set_ziv(true);

		world.at(5).at(26).set_ziv(true);
		world.at(5).at(27).set_ziv(true);
		world.at(6).at(27).set_ziv(true);
		world.at(6).at(28).set_ziv(true);
		world.at(7).at(27).set_ziv(true);
		world.at(7).at(29).set_ziv(true);
		world.at(8).at(28).set_ziv(true);
		world.at(8).at(29).set_ziv(true);
		world.at(9).at(29).set_ziv(true);
		world.at(9).at(27).set_ziv(true);
		world.at(10).at(28).set_ziv(true);
		world.at(10).at(27).set_ziv(true);
		world.at(10).at(26).set_ziv(true);
		world.at(8).at(26).set_ziv(true);
		world.at(8).at(25).set_ziv(true);
		world.at(9).at(25).set_ziv(true);
		world.at(8).at(24).set_ziv(true);
		world.at(7).at(24).set_ziv(true);

		world.at(7).at(31).set_ziv(true);
		world.at(8).at(31).set_ziv(true);
		world.at(9).at(31).set_ziv(true);
		world.at(8).at(32).set_ziv(true);
		world.at(9).at(33).set_ziv(true);
		world.at(10).at(33).set_ziv(true);
		world.at(10).at(32).set_ziv(true);
		world.at(10).at(34).set_ziv(true);
		world.at(7).at(33).set_ziv(true);
		world.at(6).at(33).set_ziv(true);
		world.at(6).at(32).set_ziv(true);
		world.at(5).at(33).set_ziv(true);
		world.at(5).at(34).set_ziv(true);
		world.at(8).at(34).set_ziv(true);
		world.at(8).at(34).set_ziv(true);
		world.at(8).at(35).set_ziv(true);
		world.at(9).at(35).set_ziv(true);
		world.at(8).at(36).set_ziv(true);
		world.at(7).at(36).set_ziv(true);

		world.at(12).at(26).set_ziv(true);
		world.at(12).at(27).set_ziv(true);
		world.at(12).at(28).set_ziv(true);
		world.at(13).at(27).set_ziv(true);
		world.at(13).at(29).set_ziv(true);
		world.at(13).at(29).set_ziv(true);
		world.at(14).at(29).set_ziv(true);
		world.at(14).at(28).set_ziv(true);
		world.at(15).at(29).set_ziv(true);
		world.at(13).at(31).set_ziv(true);
		world.at(14).at(31).set_ziv(true);
		world.at(15).at(31).set_ziv(true);
		world.at(14).at(32).set_ziv(true);
		world.at(12).at(32).set_ziv(true);
		world.at(12).at(33).set_ziv(true);
		world.at(12).at(34).set_ziv(true);
		world.at(13).at(33).set_ziv(true);
		world.at(14).at(26).set_ziv(true);
		world.at(14).at(25).set_ziv(true);
		world.at(14).at(24).set_ziv(true);
		world.at(15).at(24).set_ziv(true);
		world.at(13).at(25).set_ziv(true);
		world.at(15).at(27).set_ziv(true);
		world.at(16).at(27).set_ziv(true);
		world.at(16).at(28).set_ziv(true);
		world.at(17).at(27).set_ziv(true);
		world.at(17).at(26).set_ziv(true);
		world.at(14).at(34).set_ziv(true);
		world.at(14).at(35).set_ziv(true);
		world.at(14).at(36).set_ziv(true);
		world.at(13).at(35).set_ziv(true);
		world.at(15).at(36).set_ziv(true);
		world.at(15).at(33).set_ziv(true);
		world.at(16).at(33).set_ziv(true);
		world.at(16).at(32).set_ziv(true);
		world.at(16).at(32).set_ziv(true);
		world.at(17).at(33).set_ziv(true);
		world.at(17).at(34).set_ziv(true);

		for (unsigned __int64 i = 0; i < world.size(); i++)
		{
			for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
			{
				if (world.at(i).at(j).ziv == false)
				{
					world.at(i).at(j).set_ziv(false);
				}
				else
				{
					world.at(i).at(j).set_color();
					window.draw(world.at(i).at(j).kocka);
				}
			}
		}
	}
	if (ui.demo2.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		world.at(4).at(8).set_ziv(true);
		world.at(4).at(9).set_ziv(true);
		world.at(5).at(8).set_ziv(true);
		world.at(5).at(9).set_ziv(true);
		world.at(6).at(10).set_ziv(true);
		world.at(6).at(11).set_ziv(true);
		world.at(7).at(11).set_ziv(true);
		world.at(7).at(10).set_ziv(true);
		world.at(11).at(7).set_ziv(true);
		world.at(11).at(8).set_ziv(true);
		world.at(11).at(9).set_ziv(true);
		world.at(13).at(5).set_ziv(true);
		world.at(14).at(5).set_ziv(true);
		world.at(15).at(5).set_ziv(true);
		world.at(13).at(11).set_ziv(true);
		world.at(14).at(11).set_ziv(true);
		world.at(15).at(11).set_ziv(true);
		world.at(17).at(7).set_ziv(true);
		world.at(17).at(8).set_ziv(true);
		world.at(17).at(9).set_ziv(true);
		world.at(5).at(18).set_ziv(true);
		world.at(5).at(18).set_ziv(true);
		world.at(6).at(18).set_ziv(true);
		world.at(7).at(18).set_ziv(true);
		world.at(11).at(19).set_ziv(true);
		world.at(11).at(20).set_ziv(true);
		world.at(11).at(21).set_ziv(true);
		world.at(13).at(32).set_ziv(true);
		world.at(13).at(33).set_ziv(true);
		world.at(12).at(33).set_ziv(true);
		world.at(14).at(33).set_ziv(true);

		world.at(23).at(20).set_ziv(true);
		world.at(23).at(20).set_ziv(true);
		world.at(23).at(21).set_ziv(true);
		world.at(23).at(22).set_ziv(true);
		world.at(22).at(22).set_ziv(true);
		world.at(24).at(22).set_ziv(true);
		world.at(24).at(22).set_ziv(true);
		world.at(22).at(25).set_ziv(true);
		world.at(23).at(25).set_ziv(true);
		world.at(24).at(25).set_ziv(true);
		world.at(23).at(26).set_ziv(true);
		world.at(23).at(27).set_ziv(true);
		world.at(23).at(27).set_ziv(true);
		world.at(23).at(28).set_ziv(true);
		world.at(23).at(29).set_ziv(true);
		world.at(22).at(30).set_ziv(true);
		world.at(23).at(30).set_ziv(true);
		world.at(24).at(30).set_ziv(true);
		world.at(22).at(33).set_ziv(true);
		world.at(23).at(33).set_ziv(true);
		world.at(24).at(33).set_ziv(true);
		world.at(23).at(34).set_ziv(true);
		world.at(23).at(34).set_ziv(true);
		world.at(23).at(35).set_ziv(true);

		world.at(36).at(7).set_ziv(true);
		world.at(36).at(8).set_ziv(true);
		world.at(36).at(8).set_ziv(true);
		world.at(35).at(8).set_ziv(true);
		world.at(34).at(8).set_ziv(true);
		world.at(33).at(9).set_ziv(true);
		world.at(33).at(9).set_ziv(true);
		world.at(33).at(10).set_ziv(true);
		world.at(34).at(11).set_ziv(true);
		world.at(35).at(11).set_ziv(true);
		world.at(35).at(10).set_ziv(true);
		world.at(37).at(9).set_ziv(true);
		world.at(37).at(11).set_ziv(true);
		world.at(37).at(11).set_ziv(true);
		world.at(39).at(10).set_ziv(true);
		world.at(39).at(11).set_ziv(true);
		world.at(40).at(11).set_ziv(true);
		world.at(41).at(10).set_ziv(true);
		world.at(41).at(10).set_ziv(true);
		world.at(41).at(9).set_ziv(true);
		world.at(40).at(8).set_ziv(true);
		world.at(38).at(7).set_ziv(true);
		world.at(38).at(8).set_ziv(true);
		world.at(39).at(8).set_ziv(true);
		world.at(37).at(13).set_ziv(true);
		world.at(37).at(15).set_ziv(true);
		world.at(34).at(13).set_ziv(true);
		world.at(35).at(13).set_ziv(true);
		world.at(35).at(14).set_ziv(true);
		world.at(39).at(13).set_ziv(true);
		world.at(39).at(14).set_ziv(true);
		world.at(40).at(13).set_ziv(true);
		world.at(41).at(14).set_ziv(true);
		world.at(41).at(15).set_ziv(true);
		world.at(33).at(14).set_ziv(true);
		world.at(33).at(15).set_ziv(true);
		world.at(34).at(16).set_ziv(true);
		world.at(35).at(16).set_ziv(true);
		world.at(36).at(16).set_ziv(true);
		world.at(36).at(17).set_ziv(true);
		world.at(38).at(16).set_ziv(true);
		world.at(38).at(17).set_ziv(true);
		world.at(39).at(16).set_ziv(true);
		world.at(40).at(16).set_ziv(true);

		world.at(44).at(43).set_ziv(true);
		world.at(44).at(45).set_ziv(true);
		world.at(43).at(46).set_ziv(true);
		world.at(42).at(46).set_ziv(true);
		world.at(40).at(46).set_ziv(true);
		world.at(41).at(46).set_ziv(true);
		world.at(39).at(46).set_ziv(true);
		world.at(39).at(45).set_ziv(true);
		world.at(39).at(44).set_ziv(true);
		world.at(40).at(43).set_ziv(true);
		world.at(42).at(42).set_ziv(true);

		for (unsigned __int64 i = 0; i < world.size(); i++)
		{
			for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
			{
				if (world.at(i).at(j).ziv == false)
				{
					world.at(i).at(j).set_ziv(false);
				}
				else
				{
					world.at(i).at(j).set_color();
					window.draw(world.at(i).at(j).kocka);
				}
			}
		}
	}
	if (ui.demo3.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		world.at(47).at(16).set_ziv(true);
		world.at(47).at(17).set_ziv(true);
		world.at(46).at(16).set_ziv(true);
		world.at(46).at(17).set_ziv(true);
		world.at(46).at(18).set_ziv(true);
		world.at(45).at(16).set_ziv(true);
		world.at(45).at(17).set_ziv(true);
		world.at(45).at(18).set_ziv(true);
		world.at(44).at(17).set_ziv(true);
		world.at(44).at(15).set_ziv(true);
		world.at(43).at(15).set_ziv(true);
		world.at(43).at(16).set_ziv(true);
		world.at(42).at(16).set_ziv(true);
		world.at(42).at(17).set_ziv(true);
		world.at(41).at(17).set_ziv(true);
		world.at(41).at(18).set_ziv(true);
		world.at(42).at(18).set_ziv(true);
		world.at(43).at(19).set_ziv(true);
		world.at(43).at(19).set_ziv(true);
		world.at(42).at(20).set_ziv(true);
		world.at(40).at(19).set_ziv(true);
		world.at(40).at(20).set_ziv(true);
		world.at(39).at(18).set_ziv(true);
		world.at(38).at(18).set_ziv(true);
		world.at(38).at(20).set_ziv(true);
		world.at(36).at(20).set_ziv(true);
		world.at(36).at(20).set_ziv(true);
		world.at(37).at(21).set_ziv(true);
		world.at(37).at(22).set_ziv(true);
		world.at(36).at(23).set_ziv(true);
		world.at(38).at(23).set_ziv(true);
		world.at(38).at(25).set_ziv(true);
		world.at(39).at(25).set_ziv(true);
		world.at(40).at(24).set_ziv(true);
		world.at(40).at(23).set_ziv(true);
		world.at(41).at(25).set_ziv(true);
		world.at(41).at(26).set_ziv(true);
		world.at(42).at(26).set_ziv(true);
		world.at(42).at(25).set_ziv(true);
		world.at(42).at(23).set_ziv(true);
		world.at(43).at(24).set_ziv(true);
		world.at(42).at(27).set_ziv(true);
		world.at(43).at(27).set_ziv(true);
		world.at(43).at(28).set_ziv(true);
		world.at(44).at(28).set_ziv(true);
		world.at(44).at(26).set_ziv(true);
		world.at(45).at(25).set_ziv(true);
		world.at(45).at(26).set_ziv(true);
		world.at(45).at(27).set_ziv(true);
		world.at(46).at(25).set_ziv(true);
		world.at(46).at(26).set_ziv(true);
		world.at(46).at(27).set_ziv(true);
		world.at(47).at(26).set_ziv(true);
		world.at(47).at(27).set_ziv(true);
		world.at(35).at(19).set_ziv(true);
		world.at(34).at(18).set_ziv(true);
		world.at(33).at(18).set_ziv(true);
		world.at(35).at(24).set_ziv(true);
		world.at(34).at(25).set_ziv(true);
		world.at(33).at(25).set_ziv(true);
		world.at(31).at(17).set_ziv(true);
		world.at(31).at(17).set_ziv(true);
		world.at(30).at(16).set_ziv(true);
		world.at(30).at(15).set_ziv(true);
		world.at(30).at(14).set_ziv(true);
		world.at(31).at(14).set_ziv(true);
		world.at(32).at(14).set_ziv(true);
		world.at(33).at(14).set_ziv(true);
		world.at(34).at(14).set_ziv(true);
		world.at(35).at(15).set_ziv(true);
		world.at(31).at(26).set_ziv(true);
		world.at(31).at(26).set_ziv(true);
		world.at(30).at(27).set_ziv(true);
		world.at(30).at(28).set_ziv(true);
		world.at(30).at(29).set_ziv(true);
		world.at(31).at(29).set_ziv(true);
		world.at(32).at(29).set_ziv(true);
		world.at(33).at(29).set_ziv(true);
		world.at(34).at(29).set_ziv(true);
		world.at(35).at(28).set_ziv(true);

		for (unsigned __int64 i = 0; i < world.size(); i++)
		{
			for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
			{
				if (world.at(i).at(j).ziv == false)
				{
					world.at(i).at(j).set_ziv(false);
				}
				else
				{
					world.at(i).at(j).set_color();
					window.draw(world.at(i).at(j).kocka);
				}
			}
		}
	}
}

void mouse_button_pressed(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, UI& ui, sf::Event& event)
{
	Vector2i mouse_poz = Mouse::getPosition(window);
	Vector2f world_poz = window.mapPixelToCoords(mouse_poz);

	if (ui.gumb_reset_placeholder.getGlobalBounds().contains(world_poz.x, world_poz.y))
	{
		ui.reset_goomb = !ui.reset_goomb;
	}
}
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

struct Kvadrat
{
	Kvadrat(sf::Color boja, int x, int y, bool ziv, bool granicni);
	Kvadrat();

	sf::Color get_color();

	void set_color();
	void set_ziv(bool ziv);
	void set_xy(int x, int y);
	int provjera();

	bool check_ziv();

	sf::RectangleShape kocka;
	int x, y;
	sf::Color boja;
	bool ziv;
	bool granicni;
};

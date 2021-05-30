#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class UI
{
public:

	UI(sf::RenderWindow* window);

	void set_window(sf::RenderWindow* window);

	void backgroud();

	void ploca();

	void pauza_gumb();

	void pauza_placeholder();

	void reset_gumb();

	void reset_placeholder();

	void inc_gumb();

	void inc_placeholder_L();

	void inc_placeholder_R();

	int inc_broj_ret();

	void demo_gumb_0_1();
	void demo_gumb_2_3();

	void demo_placeholder_0();
	void demo_placeholder_1();
	void demo_placeholder_2();
	void demo_placeholder_3();

	void display_cell_numb();

	void set_brojac(int brojac);

	string to_string();

	void draw();

	bool pauza_goomb = true;
	sf::VertexArray gumb;
	sf::VertexArray gumb_reset;

	bool reset_goomb = true;
	sf::RectangleShape gumb_pauza_placeholder;
	sf::RectangleShape gumb_reset_placeholder;

	int gumb_inc_broj;
	sf::RectangleShape gumb_inc_R_placeholder;
	sf::RectangleShape gumb_inc_L_placeholder;

	sf::RectangleShape demo0;
	sf::RectangleShape demo1;
	sf::RectangleShape demo2;
	sf::RectangleShape demo3;

	int brojac;

private:

	sf::RenderWindow* window;
};
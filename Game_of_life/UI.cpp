#include "UI.h"

void UI::backgroud()
{
	sf::VertexArray pozadina(sf::Quads, 4);

	pozadina[0].position = sf::Vector2f(0, 0);
	pozadina[1].position = sf::Vector2f(0, 1000);
	pozadina[2].position = sf::Vector2f(1000, 1000);
	pozadina[3].position = sf::Vector2f(1000, 0);

	sf::Texture tex;
	if (!tex.loadFromFile("triangles_final4.png"))
	{
		std::cout << "Error - texture not found! UI - backgorund" << std::endl;
	}

	pozadina[0].texCoords = sf::Vector2f(0, 0);
	pozadina[1].texCoords = sf::Vector2f(0, 600);
	pozadina[2].texCoords = sf::Vector2f(600, 600);
	pozadina[3].texCoords = sf::Vector2f(600, 0);

	window->draw(pozadina, &tex);
}

void UI::ploca()
{
	sf::VertexArray ploca(sf::TrianglesFan, 6);

	ploca[0].position = sf::Vector2f(760, 760);
	ploca[1].position = sf::Vector2f(15, 760);
	ploca[2].position = sf::Vector2f(15, 970);
	ploca[3].position = sf::Vector2f(970, 970);
	ploca[4].position = sf::Vector2f(970, 15);
	ploca[5].position = sf::Vector2f(760, 15);

	ploca[0].color = sf::Color(0, 0, 0, 110);
	ploca[1].color = sf::Color(0, 0, 0, 110);
	ploca[2].color = sf::Color(0, 0, 0, 110);
	ploca[3].color = sf::Color(0, 0, 0, 110);
	ploca[4].color = sf::Color(0, 0, 0, 110);
	ploca[5].color = sf::Color(0, 0, 0, 110);

	window->draw(ploca);
}

void UI::pauza_gumb()
{
	sf::VertexArray gumb(sf::Quads, 4);

	this->gumb = gumb;

	if (pauza_goomb == true)
	{
		gumb[0].position = sf::Vector2f(780, 65);
		gumb[1].position = sf::Vector2f(950, 65);
		gumb[2].position = sf::Vector2f(950, 150);
		gumb[3].position = sf::Vector2f(780, 150);

		sf::Texture tex;
		if (!tex.loadFromFile("pauza1.png"))
		{
			std::cout << "Error - texture not found! UI - pauza1" << std::endl;
		}
		gumb[0].texCoords = sf::Vector2f(0, 0);
		gumb[1].texCoords = sf::Vector2f(316, 0);
		gumb[2].texCoords = sf::Vector2f(316, 129);
		gumb[3].texCoords = sf::Vector2f(0, 129);
		window->draw(gumb, &tex);
	}
	else
	{
		gumb[0].position = sf::Vector2f(780, 65);
		gumb[1].position = sf::Vector2f(950, 65);
		gumb[2].position = sf::Vector2f(950, 150);
		gumb[3].position = sf::Vector2f(780, 150);
		sf::Texture tex;
		if (!tex.loadFromFile("pauza2.png"))
		{
			std::cout << "Error - texture not found! UI - pauza1" << std::endl;
		}
		gumb[0].texCoords = sf::Vector2f(0, 0);
		gumb[1].texCoords = sf::Vector2f(316, 0);
		gumb[2].texCoords = sf::Vector2f(316, 129);
		gumb[3].texCoords = sf::Vector2f(0, 129);
		window->draw(gumb, &tex);
	}
}

void UI::pauza_placeholder()
{
	gumb_pauza_placeholder = sf::RectangleShape(sf::Vector2f(150, 70));
	gumb_pauza_placeholder.setPosition(790, 60);
	gumb_pauza_placeholder.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(gumb_pauza_placeholder);
}

void UI::reset_gumb()
{
	sf::VertexArray gumb(sf::Quads, 4);

	this->gumb_reset = gumb;

	if (reset_goomb == true)
	{
		gumb[0].position = sf::Vector2f(780, 65 + 100);
		gumb[1].position = sf::Vector2f(950, 65 + 100);
		gumb[2].position = sf::Vector2f(950, 150 + 100);
		gumb[3].position = sf::Vector2f(780, 150 + 100);

		sf::Texture tex;
		if (!tex.loadFromFile("reset1.png"))
		{
			std::cout << "Error - texture not found! UI - reset1" << std::endl;
		}
		gumb[0].texCoords = sf::Vector2f(0, 0);
		gumb[1].texCoords = sf::Vector2f(316, 0);
		gumb[2].texCoords = sf::Vector2f(316, 129);
		gumb[3].texCoords = sf::Vector2f(0, 129);

		window->draw(gumb, &tex);
	}
	else
	{
		gumb[0].position = sf::Vector2f(780, 65 + 100);
		gumb[1].position = sf::Vector2f(950, 65 + 100);
		gumb[2].position = sf::Vector2f(950, 150 + 100);
		gumb[3].position = sf::Vector2f(780, 150 + 100);

		sf::Texture tex;

		if (!tex.loadFromFile("reset2.png"))
		{
			std::cout << "Error - texture not found! UI - reset2" << std::endl;
		}

		gumb[0].texCoords = sf::Vector2f(0, 0);
		gumb[1].texCoords = sf::Vector2f(316, 0);
		gumb[2].texCoords = sf::Vector2f(316, 129);
		gumb[3].texCoords = sf::Vector2f(0, 129);

		window->draw(gumb, &tex);
	}
}

void UI::reset_placeholder()
{
	gumb_reset_placeholder = sf::RectangleShape(sf::Vector2f(150, 70));
	gumb_reset_placeholder.setPosition(790, 60 + 100);
	gumb_reset_placeholder.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(gumb_reset_placeholder);
}

void UI::inc_gumb()
{
	gumb[0].position = sf::Vector2f(780, 65 + 200);
	gumb[1].position = sf::Vector2f(950, 65 + 200);
	gumb[2].position = sf::Vector2f(950, 150 + 200);
	gumb[3].position = sf::Vector2f(780, 150 + 200);

	sf::Texture tex;
	if (!tex.loadFromFile("inc.png"))
	{
		std::cout << "Error - texture not found! UI - inc" << std::endl;
	}
	gumb[0].texCoords = sf::Vector2f(0, 0);
	gumb[1].texCoords = sf::Vector2f(316, 0);
	gumb[2].texCoords = sf::Vector2f(316, 129);
	gumb[3].texCoords = sf::Vector2f(0, 129);

	window->draw(gumb, &tex);
}

void UI::inc_placeholder_L()
{
	gumb_inc_L_placeholder = sf::RectangleShape(sf::Vector2f(70, 70));
	gumb_inc_L_placeholder.setPosition(790 - 15, 60 + 210);
	gumb_inc_L_placeholder.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(gumb_inc_L_placeholder);
}

void UI::inc_placeholder_R()
{
	gumb_inc_R_placeholder = sf::RectangleShape(sf::Vector2f(70, 70));
	gumb_inc_R_placeholder.setPosition(790 + 90, 60 + 210);
	gumb_inc_R_placeholder.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(gumb_inc_R_placeholder);
}

int UI::inc_broj_ret()
{
	return gumb_inc_broj;
}

void UI::demo_gumb_0_1()
{
	gumb[0].position = sf::Vector2f(780, 65 + 400);
	gumb[1].position = sf::Vector2f(950, 65 + 400);
	gumb[2].position = sf::Vector2f(950, 150 + 400);
	gumb[3].position = sf::Vector2f(780, 150 + 400);

	sf::Texture tex;
	if (!tex.loadFromFile("0-1.png"))
	{
		std::cout << "Error - texture not found! UI - 0-1" << std::endl;
	}
	gumb[0].texCoords = sf::Vector2f(0, 0);
	gumb[1].texCoords = sf::Vector2f(316, 0);
	gumb[2].texCoords = sf::Vector2f(316, 129);
	gumb[3].texCoords = sf::Vector2f(0, 129);

	window->draw(gumb, &tex);
}

void UI::demo_gumb_2_3()
{
	gumb[0].position = sf::Vector2f(780, 65 + 500);
	gumb[1].position = sf::Vector2f(950, 65 + 500);
	gumb[2].position = sf::Vector2f(950, 150 + 500);
	gumb[3].position = sf::Vector2f(780, 150 + 500);

	sf::Texture tex;
	if (!tex.loadFromFile("2-3.png"))
	{
		std::cout << "Error - texture not found! UI - 2-3" << std::endl;
	}
	gumb[0].texCoords = sf::Vector2f(0, 0);
	gumb[1].texCoords = sf::Vector2f(316, 0);
	gumb[2].texCoords = sf::Vector2f(316, 129);
	gumb[3].texCoords = sf::Vector2f(0, 129);

	window->draw(gumb, &tex);
}

void UI::demo_placeholder_0()
{
	demo0 = sf::RectangleShape(sf::Vector2f(70, 70));
	demo0.setPosition(790 - 15, 60 + 410);
	demo0.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(demo0);
}

void UI::demo_placeholder_1()
{
	demo1 = sf::RectangleShape(sf::Vector2f(70, 70));
	demo1.setPosition(790 + 90, 60 + 410);
	demo1.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(demo1);
}

void UI::demo_placeholder_2()
{
	demo2 = sf::RectangleShape(sf::Vector2f(70, 70));
	demo2.setPosition(790 - 15, 60 + 510);
	demo2.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(demo2);
}

void UI::demo_placeholder_3()
{
	demo3 = sf::RectangleShape(sf::Vector2f(70, 70));
	demo3.setPosition(790 + 90, 60 + 510);
	demo3.setFillColor(sf::Color(0, 0, 0, 0));

	window->draw(demo3);
}

void UI::display_cell_numb() {
	sf::Font font;

	if (!font.loadFromFile("COPRGTB.TTF"))
	{
		std::cout << "Error nema fonta - COPRGTB.TTF " << std::endl;
	}

	sf::Text text;
	text.setPosition(780, 370);
	text.setFont(font);
	text.setString("Population: ");
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);

	window->draw(text);

	sf::Text text2;
	text2.setPosition(780, 410);
	text2.setFont(font);
	text2.setString(to_string());
	text2.setCharacterSize(24);
	text2.setFillColor(sf::Color::Black);
	window->draw(text2);
}

void UI::set_brojac(int brojac)
{
	this->brojac = brojac;
}

string UI::to_string()
{
	stringstream ss;

	ss << brojac;

	return ss.str();
}

UI::UI(sf::RenderWindow* window)
{
	set_window(window);
}

void UI::set_window(sf::RenderWindow* window)
{
	this->window = window;
}

void UI::draw()
{
	backgroud();
	//ploca();
	pauza_gumb();
	pauza_placeholder();
	reset_gumb();
	reset_placeholder();
	inc_gumb();
	inc_placeholder_L();
	inc_placeholder_R();
	demo_gumb_0_1();
	demo_gumb_2_3();

	demo_placeholder_0();
	demo_placeholder_1();
	demo_placeholder_2();
	demo_placeholder_3();

	display_cell_numb();
}
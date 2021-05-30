#include "Kocke.h"

Kvadrat::Kvadrat(sf::Color boja, int x, int y, bool ziv, bool granicni)
{
	//velicina
	float value = 15.f;

	kocka = sf::RectangleShape(sf::Vector2f(value, value));

	kocka.setOutlineColor(sf::Color(120, 120, 120));
	kocka.setOutlineThickness(1);
	kocka.setFillColor(boja);
	kocka.setPosition(value * x, value * y);

	this->x = x;
	this->y = y;
	this->kocka = kocka;
	this->ziv = ziv;
	this->granicni = granicni;
}

Kvadrat::Kvadrat()
{
	this->x = x;
	this->y = y;
	this->kocka = kocka;
}

void Kvadrat::set_color()
{
	if (ziv == true)
	{
		kocka.setFillColor(sf::Color(255, 255, 50));
	}
	if (ziv == false)
	{
		kocka.setFillColor(sf::Color(165, 165, 165, 240));
	}
}

sf::Color Kvadrat::get_color()
{
	return boja;
}

void Kvadrat::set_ziv(bool ziv)
{
	this->ziv = ziv;
}

void Kvadrat::set_xy(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Kvadrat::provjera()
{
	int broj;

	if (ziv == true)
	{
		broj = 1;
	}
	else
	{
		broj = 0;
	}

	return broj;
}

bool Kvadrat::check_ziv()
{
	return ziv;
}
#pragma once

std::vector<std::vector<Kvadrat>> world_pushback()
{
	std::vector<std::vector<Kvadrat>> world;

	bool ziv;
	bool granicni;

	srand(time(nullptr));
	for (int i = 0; i < 50; i++)
	{
		std::vector<Kvadrat>v;

		for (int j = 0; j < 50; j++)
		{
			if (i == 0 || i == 49 || j == 0 || j == 49)
			{
				granicni = true;
			}
			else
			{
				granicni = false;
			}

			int broj = rand() % 4 + 1;

			int r = 0;
			int g = 0;
			int b = 0;
			int a = 240;

			//	std::cout << broj << std::endl;
			if (broj == 1 && granicni == false)
			{
				r = 255;
				g = 255;
				b = 50;
				a = 255;
				ziv = true;
			}
			else
			{
				r = 165;
				g = 165;
				b = 165;
				ziv = false;
			}

			Kvadrat kvad(sf::Color(r, g, b, a), i, j, ziv, granicni);

			v.push_back(kvad);
		}
		world.push_back(v);
	}

	return world;
}

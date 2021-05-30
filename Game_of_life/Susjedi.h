#pragma once

int susjedi_funk(std::vector<std::vector<Kvadrat>>& world, unsigned __int64  m, unsigned __int64  n)
{
	//neki bug sa visualom ako ne stavim unsigned __int64 ...

	unsigned __int64 i = m;
	unsigned __int64 j = n;

	int sused = 0;

	if (world.at(i).at(j).check_ziv() == world.at(i - 1).at(j).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (1)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i - 1).at(j - 1).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (2)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i - 1).at(j + 1).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (3)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i).at(j - 1).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (4)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i + 1).at(j).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (5)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i + 1).at(j - 1).check_ziv())
	{
		sused++;

		//	std::cout << sused << " (6)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i + 1).at(j + 1).check_ziv())
	{
		sused++;

		//std::cout << sused << " (7)";
	}
	if (world.at(i).at(j).check_ziv() == world.at(i).at(j + 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " (8)";
	}

	//std::cout << std::endl; std::cout << std::endl;
	return sused;
}
int susjedi_funk_ded(std::vector<std::vector<Kvadrat>>& world, unsigned __int64  m, unsigned __int64  n)
{
	//neki bug sa visualom ako ne stavim unsigned __int64 ...
	unsigned __int64 i = m;
	unsigned __int64 j = n;
	int sused = 0;
	if (world.at(i).at(j).check_ziv() != world.at(i - 1).at(j).check_ziv())
	{
		sused++;

		//std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i - 1).at(j - 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i - 1).at(j + 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i).at(j - 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i + 1).at(j).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i + 1).at(j - 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i + 1).at(j + 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}
	if (world.at(i).at(j).check_ziv() != world.at(i).at(j + 1).check_ziv())
	{
		sused++;
		//	std::cout << sused << " ";
	}

	//std::cout << std::endl;
	return sused;
}

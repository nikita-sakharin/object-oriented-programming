#include <iostream>
#include "hexagon.h"

Hexagon::Hexagon()
{
	for (std::size_t i = 0u; i < Hexagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = 0.0l;
		}
	}
}

Hexagon::Hexagon(const FPType (*coor)[COOR_COUNT])
{
	for (std::size_t i = 0u; i < Hexagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Hexagon::Hexagon(const Hexagon& origin)
{
	for (std::size_t i = 0u; i < Hexagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Hexagon::Hexagon(std::istream &is)
{
	for (std::size_t i = 0u; i < Hexagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			is >> vertex[i][j];
		}
	}
}

FPType Hexagon::Square()
{
	return area(vertex, Hexagon::VERTEX_COUNT);
}

void Hexagon::Print()
{
	for (std::size_t i = 0u; i < Hexagon::VERTEX_COUNT; i++)
	{
		std::cout << '(' << vertex[i][0u] << ", "<< vertex[i][1u] << ")\n";
	}
	std::cout << std::endl;
}

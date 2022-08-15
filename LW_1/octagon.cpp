#include <iostream>
#include "octagon.h"

Octagon::Octagon()
{
	for (std::size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = 0.0l;
		}
	}
}

Octagon::Octagon(const FPType (*coor)[COOR_COUNT])
{
	for (std::size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Octagon::Octagon(const Octagon& origin)
{
	for (std::size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Octagon::Octagon(std::istream &is)
{
	for (std::size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			is >> vertex[i][j];
		}
	}
}

FPType Octagon::Square()
{
	return area(vertex, Octagon::VERTEX_COUNT);
}

void Octagon::Print()
{
	for (std::size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		std::cout << '(' << vertex[i][0u] << ", "<< vertex[i][1u] << ")\n";
	}
	std::cout << std::endl;
}

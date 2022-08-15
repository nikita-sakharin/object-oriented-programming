#include <iostream>
#include "pentagon.h"

Pentagon::Pentagon()
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = 0.0l;
		}
	}
}

Pentagon::Pentagon(const FPType (*coor)[COOR_COUNT])
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Pentagon::Pentagon(const Pentagon& origin)
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Pentagon::Pentagon(std::istream &is)
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			is >> vertex[i][j];
		}
	}
}

FPType Pentagon::Square()
{
	return area(vertex, Pentagon::VERTEX_COUNT);
}

void Pentagon::Print()
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		std::cout << '(' << vertex[i][0u] << ", "<< vertex[i][1u] << ")\n";
	}
	std::cout << std::endl;
}

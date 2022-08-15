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

std::ostream& operator<<(std::ostream& os, const Pentagon& obj)
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		os << '(' << obj.vertex[i][0u] << ", "<< obj.vertex[i][1u] << ")\n";
	}
	std::cout << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Pentagon& obj)
{
	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			is >> obj.vertex[i][j];
		}
	}

	return is;
}

bool Pentagon::operator==(const Pentagon& right)
{

	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			if (vertex[i][j] != right.vertex[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

Pentagon& Pentagon::operator=(const Pentagon& right)
{
	if (this == &right)
	{
		return *this;
	}

	for (std::size_t i = 0u; i < Pentagon::VERTEX_COUNT; i++)
	{
		for (std::size_t j = 0u; j < COOR_COUNT; j++)
		{
			vertex[i][j] = right.vertex[i][j];
		}
	}

	return *this;
}

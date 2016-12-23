#include <iostream>
#include "pentagon.h"

Pentagon::Pentagon()
{
	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = Real(0.0);
		}
	}
}

Pentagon::Pentagon(const Real (*coor)[2u])
{
	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Pentagon::Pentagon(const Pentagon& origin)
{
	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Polygon Pentagon::Type()
{
	return PENTAGON;
}

Real Pentagon::Square()
{
	return area(vertex, PENTAGON_VERTEX_CNT);
}

void Pentagon::Print(std::ostream& os)
{
	os << *this;
}

void Pentagon::Scan(std::istream& is)
{
	is >> *this;
}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj)
{
	os << "{\n";
	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		os << "\t{ " << obj.vertex[i][0u] << ", "<< obj.vertex[i][1u] << " }\n";
	}
	os << "}\n";

	return os;
}

std::istream& operator>>(std::istream& is, Pentagon& obj)
{
	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			is >> obj.vertex[i][j];
		}
	}

	return is;
}

bool Pentagon::operator==(const Pentagon& right)
{

	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
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

	for (std::size_t i = 0u; i < PENTAGON_VERTEX_CNT; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = right.vertex[i][j];
		}
	}

	return *this;
}

Pentagon::~Pentagon()
{
}
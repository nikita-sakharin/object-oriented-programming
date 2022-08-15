#include <iostream>
#include "hexagon.h"

Hexagon::Hexagon()
{
	for (std::size_t i = 0u; i < 6u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = Real(0.0);
		}
	}
}

Hexagon::Hexagon(const Real (*coor)[2u])
{
	for (std::size_t i = 0u; i < 6u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Hexagon::Hexagon(const Hexagon& origin)
{
	for (std::size_t i = 0u; i < 6u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Real Hexagon::Square()
{
	return area(vertex, 6u);
}

void Hexagon::Print()
{
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj)
{
	os << "{\n";
	for (std::size_t i = 0u; i < 6u; i++)
	{
		os << "\t{ " << obj.vertex[i][0u] << ", "<< obj.vertex[i][1u] << " }\n";
	}
	os << "}\n";

	return os;
}

std::istream& operator>>(std::istream& is, Hexagon& obj)
{
	for (std::size_t i = 0u; i < 6u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			is >> obj.vertex[i][j];
		}
	}

	return is;
}

bool Hexagon::operator==(const Hexagon& right)
{

	for (std::size_t i = 0u; i < 6u; i++)
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

Hexagon& Hexagon::operator=(const Hexagon& right)
{
	if (this == &right)
	{
		return *this;
	}

	for (std::size_t i = 0u; i < 6u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = right.vertex[i][j];
		}
	}

	return *this;
}

Hexagon::~Hexagon()
{
}
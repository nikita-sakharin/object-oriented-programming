#include <iostream>
#include "octagon.h"

Octagon::Octagon()
{
	for (std::size_t i = 0u; i < 8u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = Real(0.0);
		}
	}
}

Octagon::Octagon(const Real (*coor)[2u])
{
	for (std::size_t i = 0u; i < 8u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = coor[i][j];
		}
	}
}

Octagon::Octagon(const Octagon& origin)
{
	for (std::size_t i = 0u; i < 8u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = origin.vertex[i][j];
		}
	}
}

Real Octagon::Square()
{
	return area(vertex, 8u);
}

void Octagon::Print()
{
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj)
{
	os << "{\n";
	for (std::size_t i = 0u; i < 8u; i++)
	{
		os << "\t{ " << obj.vertex[i][0u] << ", "<< obj.vertex[i][1u] << " }\n";
	}
	os << "}\n";

	return os;
}

std::istream& operator>>(std::istream& is, Octagon& obj)
{
	for (std::size_t i = 0u; i < 8u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			is >> obj.vertex[i][j];
		}
	}

	return is;
}

bool Octagon::operator==(const Octagon& right)
{

	for (std::size_t i = 0u; i < 8u; i++)
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

Octagon& Octagon::operator=(const Octagon& right)
{
	if (this == &right)
	{
		return *this;
	}

	for (std::size_t i = 0u; i < 8u; i++)
	{
		for (std::size_t j = 0u; j < 2u; j++)
		{
			vertex[i][j] = right.vertex[i][j];
		}
	}

	return *this;
}

Octagon::~Octagon()
{
}
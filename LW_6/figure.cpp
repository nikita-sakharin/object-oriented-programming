#include <cmath>
#include <cstddef>
#include "figure.h"

Polygon Figure::Type()
{
	return FIGURE;
}

bool Figure::operator<(Figure& obj)
{
	return this->Square() < obj.Square();
}

bool Figure::operator>(Figure& obj)
{
	return this->Square() > obj.Square();
}

bool Figure::operator==(Figure& obj)
{
	return this->Square() == obj.Square();
}

Real dot_product(Real vec_1[], Real vec_2[])
{
	return vec_1[0u] * vec_2[0u] + vec_1[1u] * vec_2[1u];
}

Real cross_product(Real coor_1[], Real coor_2[])
{
	Real norm_1 = std::sqrt(dot_product(coor_1, coor_1)),
	     norm_2 = std::sqrt(dot_product(coor_2, coor_2));
	Real a = std::acos(dot_product(coor_1, coor_2) / norm_1 / norm_2);
	return norm_1 * norm_2 * std::sin(a);
}

Real area(Real (*coor)[2u], std::size_t ver_count)
{
	Real result = 0.0l;
	for (std::size_t i = 1u, j = 2u; j < ver_count; i++, j++)
	{
		Real v1[2] = { coor[i][0u] - coor[0u][0u], coor[i][1u] - coor[0u][1u] },
		     v2[2] = { coor[j][0u] - coor[0u][0u], coor[j][1u] - coor[0u][1u] };
		result += cross_product(v1, v2);
	}

	return result / 2.0l;
}
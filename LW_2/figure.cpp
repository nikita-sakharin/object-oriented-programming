#include <cmath>
#include <cstddef>
#include "figure.h"

FPType dot_product(FPType vec_1[], FPType vec_2[])
{
	return vec_1[0u] * vec_2[0u] + vec_1[1u] * vec_2[1u];
}

FPType abs_cross_product(FPType coor_1[], FPType coor_2[])
{
	FPType norm_1 = std::sqrt(dot_product(coor_1, coor_1)),
	            norm_2 = std::sqrt(dot_product(coor_2, coor_2));
	FPType a = std::acos(dot_product(coor_1, coor_2) / norm_1 / norm_2);
	return norm_1 * norm_2 * std::sin(a);
}

FPType area(FPType (*coor)[COOR_COUNT], std::size_t ver_count)
{
	FPType result = 0.0l;
	for (register std::size_t i = 1u, j = 2u; j < ver_count; i++, j++)
	{
		FPType v1[COOR_COUNT] = { [0u] = coor[i][0u] - coor[0u][0u], [1u] = coor[i][1u] - coor[0u][1u] },
		       v2[COOR_COUNT] = { [0u] = coor[j][0u] - coor[0u][0u], [1u] = coor[j][1u] - coor[0u][1u] };
		result += abs_cross_product(v1, v2);
	}

	return result / 2.0l;
}

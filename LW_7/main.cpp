#include <iostream>
#include <memory>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "queue.h"

int main()
{
	Queue<Figure> queue;
	Real matrix[HEXAGON_VERTEX_CNT][2u];

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(i * PENTAGON_VERTEX_CNT + j);
		}
	}
	queue.Push(std::shared_ptr<Pentagon>(new Pentagon(matrix)));

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(5);
		}
	}
	queue.Push(std::shared_ptr<Pentagon>(new Pentagon(matrix)));

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(3);
		}
	}
	queue.Push(std::shared_ptr<Pentagon>(new Pentagon(matrix)));

	for (auto x = queue.begin(); x != queue.end(); ++x)
	{
		std::cout << **x << "\n";
	}
	queue.Pop();

	std::cout << "curr_size = " << queue.Size() << "\n";

	return 0;
}
/*
	Real matrix[HEXAGON_VERTEX_CNT][2u] =
	{
		{ 1.0, 0.0 },
		{ 5.0, 0.0 },
		{ 7.0, 2.0 },
		{ 5.0, 6.0 },
		{ 0.0, 4.0 },
		{ -80.0, 2.0 },
	};
*/
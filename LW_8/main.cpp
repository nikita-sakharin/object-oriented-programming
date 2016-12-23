#include <iostream>
#include <memory>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "queue.h"

int main()
{
	Queue<Figure> queue;
	Real matrix[HEXAGON_VERTEX_CNT][2u] =
	{
		{ 1.0, 0.0 },
		{ 5.0, 0.0 },
		{ 7.0, 2.0 },
		{ 5.0, 6.0 },
		{ 0.0, 4.0 },
		{ 0.0, 2.0 },
	};
	queue.Push(std::shared_ptr<Figure>(new Hexagon(matrix)));

	matrix[5u][0u] = -80.0;
	queue.Push(std::shared_ptr<Figure>(new Hexagon(matrix)));

	matrix[3u][0u] = 80.0;
	queue.Push(std::shared_ptr<Figure>(new Pentagon(matrix)));
	std::cout << queue << "\n";

	std::cout << "Sorting...\n";

//	queue.sort();
	queue.sort_parallel();

	std::cout << queue << "\n";

	return 0;
}
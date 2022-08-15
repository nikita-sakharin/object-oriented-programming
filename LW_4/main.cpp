#include <iostream>
#include <memory>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "queue.h"

int main()
{
	Real matrix[8u][2u];
	Queue<Pentagon, Hexagon, Octagon> queue;

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(i * 5u + j);
		}
	}
	queue.PushBack(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(5);
		}
	}
	queue.PushBack(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(3);
		}
	}
	queue.PushBack(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	std::cout << queue;
	std::cout << "curr_size = " << queue.size() << "\n";
	queue.Pop();

	std::cout << queue;
	std::cout << "curr_size = " << queue.size() << "\n";
	queue.Pop();

	std::cout << queue;
	std::cout << "curr_size = " << queue.size() << "\n";
	queue.Pop();

	std::cout << queue.empty();

	return 0;
}
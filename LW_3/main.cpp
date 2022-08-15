#include <iostream>
#include <memory>
#include "queue.h"

int main()
{
	Real matrix[8u][2u];
	Queue queue;

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(i * 5u + j);
		}
	}
	queue.push_back(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(5);
		}
	}
	queue.push_back(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	for (size_t i = 0u; i < 8u; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(3);
		}
	}
	queue.push_back(std::shared_ptr<Pentagon>(new Pentagon(matrix)), std::shared_ptr<Hexagon>(new Hexagon(matrix)), std::shared_ptr<Octagon>(new Octagon(matrix)));

	std::cout << queue;
	std::cout << queue.size() << "\n";
	queue.pop();

	std::cout << queue;
	std::cout << queue.size() << "\n";
	queue.pop();

	std::cout << queue;
	std::cout << queue.size() << "\n";
	queue.pop();

	std::cout << queue.empty();

	return 0;
}
#include <iostream>
#include <memory>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "container.h"

typedef Figure *PTR;

bool func(Figure * const &x)
{
	std::cout << "Delete ";
	x->Print(std::cout);
	std::cout << "?\n";
	bool result;
	std::cin >> result;
	return result;
}

int main()
{
	Container<Figure *> container;
	Real matrix[HEXAGON_VERTEX_CNT][2u];
	Figure *ptr;

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(i * PENTAGON_VERTEX_CNT + j);
		}
	}
	ptr = new Pentagon(matrix);
	container.Push(ptr);

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(5);
		}
	}
	ptr = new Pentagon(matrix);
	container.Push(ptr);

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(3);
		}
	}
	ptr = new Pentagon(matrix);
	container.Push(ptr);

	std::cout << container;
	container.Delete(func);

	std::cout << "curr_size = " << container.Size() << "\n";

	return 0;
}
/*
	Stack<Figure *> stack;
	Real matrix[HEXAGON_VERTEX_CNT][2u];
	Figure *ptr;

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(i * PENTAGON_VERTEX_CNT + j);
		}
	}
	ptr = new Pentagon(matrix);
	stack.Push(ptr);

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(5);
		}
	}
	ptr = new Pentagon(matrix);
	stack.Push(ptr);

	for (size_t i = 0u; i < PENTAGON_VERTEX_CNT; ++i)
	{
		for (size_t j = 0u; j < 2u; ++j)
		{
			matrix[i][j] = Real(3);
		}
	}
	ptr = new Pentagon(matrix);
	stack.Push(ptr);

	std::cout << stack;
	stack.Pop(func);

	std::cout << "curr_size = " << stack.Size() << "\n";
*/





/*
	Queue<Figure> queue;
	Real matrix[HEXAGON_VERTEX_CNT][2u];
	Real matrix[HEXAGON_VERTEX_CNT][2u] =
	{
		{ 1.0, 0.0 },
		{ 5.0, 0.0 },
		{ 7.0, 2.0 },
		{ 5.0, 6.0 },
		{ 0.0, 4.0 },
		{ -80.0, 2.0 },
	};

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
*/
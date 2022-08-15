#include <iostream>
#include "pentagon.h"
#include "queue.h"

int main()
{
	using namespace std;

	Queue *queue = new Queue();

	size_t k;
	cin >> k;
	for (size_t counter = 0u; counter < k; counter++)
	{
		long double matrix[5u][2u];
		for (size_t i = 0u; i < 5u; i++)
		{
			for (size_t j = 0u; j < 2u; j++)
			{
				cin >> matrix[i][j];
			}
		}
		queue->push_back(new Pentagon(matrix));
		queue->top()->Print();
		cout << "All queue:\n" << *queue << endl;
	}

	delete queue;

	return 0;
}

#include <iostream>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

int main()
{
	using namespace std;

	FPType matrix[Octagon::VERTEX_COUNT][COOR_COUNT];
	for (size_t i = 0u; i < Octagon::VERTEX_COUNT; i++)
	{
		for (size_t j = 0u; j < COOR_COUNT; j++)
		{
			cin >> matrix[i][j];
		}
	}

	Figure *ptr = new Octagon(matrix);
	ptr->Print();
	cout << ptr->Square() << endl;
	delete ptr;

	return 0;
}

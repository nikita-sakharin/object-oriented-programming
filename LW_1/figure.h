#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>

typedef long double FPType;
static const std::size_t COOR_COUNT = 2u;

FPType area(FPType (*)[COOR_COUNT], std::size_t);

class Figure
{
public:
	virtual FPType Square() = 0;
	virtual void Print() = 0;
	virtual ~Figure() {};
};

#endif

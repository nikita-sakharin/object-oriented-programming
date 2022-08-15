#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <cstddef>

typedef long double Real;

Real area(Real (*)[2u], std::size_t);

class Figure
{
public:
	virtual Real Square() = 0;
	virtual void Print() = 0;
	virtual ~Figure() {};
};

#endif
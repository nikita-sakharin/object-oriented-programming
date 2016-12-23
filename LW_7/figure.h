#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <cstddef>
#include <iostream>

typedef long double Real;

enum Polygon
{
	FIGURE,
	PENTAGON = 5,
	HEXAGON = 6,
	OCTAGON = 8
};

Real area(Real (*)[2u], std::size_t);

class Figure
{
public:
	virtual Polygon Type();
	virtual Real Square() = 0;
	bool operator<(Figure& obj);
	bool operator>(Figure& obj);
	bool operator==(Figure& obj);
	virtual void Print(std::ostream& os) = 0;
	virtual void Scan(std::istream& is) = 0;
	virtual ~Figure() {};
};

#endif
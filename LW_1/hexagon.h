#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include <iostream>
#include "figure.h"

class Hexagon : public Figure
{
	static const std::size_t VERTEX_COUNT = 6u;
	FPType vertex[VERTEX_COUNT][COOR_COUNT];

public:
	Hexagon();
	Hexagon(const FPType (*coor)[COOR_COUNT]);
	Hexagon(const Hexagon& orig);
	Hexagon(std::istream &is);

	FPType Square() override;
	void Print() override;

	virtual ~Hexagon() {};
};

#endif

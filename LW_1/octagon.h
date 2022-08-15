#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include <iostream>
#include "figure.h"

class Octagon : public Figure
{
	static const std::size_t VERTEX_COUNT = 8u;
	FPType vertex[VERTEX_COUNT][COOR_COUNT];

public:
	Octagon();
	Octagon(const FPType (*coor)[COOR_COUNT]);
	Octagon(const Octagon& orig);
	Octagon(std::istream &is);

	FPType Square() override;
	void Print() override;

	virtual ~Octagon() {};
};

#endif

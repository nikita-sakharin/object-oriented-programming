#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include <iostream>
#include "Figure.h"

class Hexagon : public Figure
{
	Real vertex[6u][2u];
public:
	Hexagon();
	Hexagon(const Real (*coor)[2u]);
	Hexagon(const Hexagon& orig);

	Real Square() override;
	virtual void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
	friend std::istream& operator>>(std::istream& is, Hexagon& obj);

	Hexagon& operator=(const Hexagon& right);

	bool operator==(const Hexagon& right);

	virtual ~Hexagon();
};

#endif
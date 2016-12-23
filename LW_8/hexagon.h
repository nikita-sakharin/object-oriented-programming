#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include <iostream>
#include "figure.h"

const static std::size_t HEXAGON_VERTEX_CNT = 6u;

class Hexagon : public Figure
{
	Real vertex[HEXAGON_VERTEX_CNT][2u];
public:
	Hexagon();
	Hexagon(const Real (*coor)[2u]);
	Hexagon(const Hexagon& orig);

	Polygon Type() override;
	Real Square() override;
	virtual void Print(std::ostream& os) override;
	virtual void Scan(std::istream& is) override;

	friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
	friend std::istream& operator>>(std::istream& is, Hexagon& obj);

	Hexagon& operator=(const Hexagon& right);

	bool operator==(const Hexagon& right);

	virtual ~Hexagon();
};

#endif
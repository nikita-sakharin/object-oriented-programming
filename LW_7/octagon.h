#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include <iostream>
#include "figure.h"

const static std::size_t OCTAGON_VERTEX_CNT = 8u;

class Octagon : public Figure
{
	Real vertex[OCTAGON_VERTEX_CNT][2u];
public:
	Octagon();
	Octagon(const Real (*coor)[2u]);
	Octagon(const Octagon& orig);

	Polygon Type() override;
	Real Square() override;
	virtual void Print(std::ostream& os) override;
	virtual void Scan(std::istream& is) override;

	friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
	friend std::istream& operator>>(std::istream& is, Octagon& obj);

	Octagon& operator=(const Octagon& right);

	bool operator==(const Octagon& right);

	virtual ~Octagon();
};

#endif
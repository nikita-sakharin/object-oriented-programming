#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include <iostream>
#include "Figure.h"

class Octagon : public Figure
{
	Real vertex[8u][2u];
public:
	Octagon();
	Octagon(const Real (*coor)[2u]);
	Octagon(const Octagon& orig);

	Real Square() override;
	virtual void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
	friend std::istream& operator>>(std::istream& is, Octagon& obj);

	Octagon& operator=(const Octagon& right);

	bool operator==(const Octagon& right);

	virtual ~Octagon();
};

#endif
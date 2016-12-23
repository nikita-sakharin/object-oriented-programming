#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include <iostream>
#include "figure.h"

const static std::size_t PENTAGON_VERTEX_CNT = 5u;

class Pentagon : public Figure
{
	Real vertex[PENTAGON_VERTEX_CNT][2u];
public:
	Pentagon();
	Pentagon(const Real (*coor)[2u]);
	Pentagon(const Pentagon& orig);

	Polygon Type() override;
	Real Square() override;
	virtual void Print(std::ostream& os) override;
	virtual void Scan(std::istream& is) override;

	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator>>(std::istream& is, Pentagon& obj);

	Pentagon& operator=(const Pentagon& right);

	bool operator==(const Pentagon& right);

	virtual ~Pentagon();
};

#endif
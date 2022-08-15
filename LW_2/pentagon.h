#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include <iostream>
#include "figure.h"

class Pentagon : public Figure
{
	static const std::size_t VERTEX_COUNT = 5u;
	FPType vertex[VERTEX_COUNT][COOR_COUNT];

public:
	Pentagon();
	Pentagon(const FPType (*coor)[COOR_COUNT]);
	Pentagon(const Pentagon& orig);

	FPType Square() override;
	void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator>>(std::istream& is, Pentagon& obj);

	Pentagon& operator=(const Pentagon& right);

	bool operator==(const Pentagon& right);

	virtual ~Pentagon() {};
};

#endif

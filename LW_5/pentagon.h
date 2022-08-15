#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include <iostream>
#include "figure.h"

class Pentagon : public Figure
{
	Real vertex[5u][2u];
public:
	Pentagon();
	Pentagon(const Real (*coor)[2u]);
	Pentagon(const Pentagon& orig);

	Real Square() override;
	virtual void Print() override;

	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	friend std::istream& operator>>(std::istream& is, Pentagon& obj);

	Pentagon& operator=(const Pentagon& right);

	bool operator==(const Pentagon& right);

	virtual ~Pentagon();
};

#endif
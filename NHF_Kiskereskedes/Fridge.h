#ifndef FRIDGE_H
#define FRIDGE_H

#include "Device.h"
class Fridge : public Device
{
	int urtartalom;
public:
	Fridge( string gy, double efogy, string eoszt, int az, int urt );
	~Fridge();
	void show( std::ostream& os );
	void show( std::fstream& fs );
};

#endif
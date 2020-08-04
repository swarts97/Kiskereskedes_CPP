#ifndef MICRO_H
#define MICRO_H

#include "Device.h"
class Micro : public Device
{
	int talcasugar;
public:
	Micro( string gy, double efogy, string eoszt, int az, int sugar);
	~Micro();
	void show( std::ostream& os );
	void show( std::fstream& fs );
};

#endif
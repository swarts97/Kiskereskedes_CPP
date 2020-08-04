#ifndef WASHING_H
#define WASHING_H

#include "Device.h"
class Washing : public Device
{
	int maxhofok;
public:
	Washing( string gy, double efogy, string eoszt, int az, int hofok);
	~Washing();
	void show( std::ostream& os );
	void show( std::fstream& fs );
};

#endif
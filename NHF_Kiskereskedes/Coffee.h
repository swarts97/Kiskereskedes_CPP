#ifndef COFFEE_H
#define COFFEE_H

#include "Device.h"
class Coffee : public Device
{
	bool cappuccino;
public:
	Coffee( string gy, double efogy, string eoszt, int az, bool capp );
	~Coffee();
	void show( std::ostream& os );
	void show( std::fstream& fs );
};

#endif
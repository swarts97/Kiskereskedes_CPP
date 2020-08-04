#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

using std::string;

class Device
{
	string gyarto;
	double efogyaszt;
	string eosztaly;
	int azonosito;
public:
	Device( string gy, double efogy, string eoszt, int az );
	int getAzon();
	virtual ~Device();
	virtual void show( std::ostream& os ) = 0;
	virtual void show( std::fstream& fs ) = 0;
};

#endif
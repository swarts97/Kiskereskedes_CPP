#include "Washing.h"

Washing::Washing( string gy, double efogy, string eoszt, int az, int hofok )
	: Device( gy, efogy, eoszt, az )
	, maxhofok( hofok )
{}


Washing::~Washing()
{}

void Washing::show( std::ostream& os )
{
	Device::show( os );
	os  << "\tMaxhofok: \t\t\t" << maxhofok
		<< " Celsius"
		<< endl
		<< "\tTipus: \t\t\t\tMosogatogep" << endl << endl;
}

void Washing::show( std::fstream& fs )
{
	Device::show( fs );
	fs << maxhofok << endl;
}
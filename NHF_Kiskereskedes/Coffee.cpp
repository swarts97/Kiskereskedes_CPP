#include "Coffee.h"

Coffee::Coffee( string gy, double efogy, string eoszt, int az, bool capp )
	: Device( gy, efogy, eoszt, az )
	, cappuccino( capp )
{}


Coffee::~Coffee()
{}


void Coffee::show( std::ostream& os )
{
	Device::show( os );
	os << "\tCappuccinot tud fozni: \t\t";
	if ( cappuccino )
		os << "Igen" << endl;
	else
		os << "Nem" << endl;
	os << "\tTipus: \t\t\t\tKavefozogep" << endl << endl;
}

void Coffee::show( std::fstream& fs )
{
	Device::show( fs );
	if ( cappuccino )
		fs << "Igen" << endl;
	else
		fs << "Nem" << endl;
}
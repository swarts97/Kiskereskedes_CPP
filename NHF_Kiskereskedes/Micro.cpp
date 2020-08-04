#include "Micro.h"

Micro::Micro( string gy, double efogy, string eoszt, int az, int sugar )
	: Device( gy, efogy, eoszt, az )
	, talcasugar(sugar)
{}


Micro::~Micro()
{}

void Micro::show( std::ostream& os )
{
	Device::show( os );
	os  << "\tTalca sugara: \t\t\t" << talcasugar
		<< " cm"
		<< endl
		<< "\tTipus: \t\t\t\tMikrohullamu suto" << endl << endl;
}

void Micro::show( std::fstream& fs )
{
	Device::show( fs );
	fs << talcasugar << endl;
}
#include "Fridge.h"

Fridge::Fridge( string gy, double efogy, string eoszt, int az, int urt )
	: Device( gy, efogy, eoszt, az)
	, urtartalom( urt )
{}


Fridge::~Fridge()
{}

void Fridge::show( std::ostream& os )
{
	Device::show( os );
	os   << "\tUrtartalom: \t\t\t" << urtartalom 
		 << " liter"
		 << endl
		 << "\tTipus: \t\t\t\tHutoszekreny" << endl << endl;
}

void Fridge::show( std::fstream& fs )
{
	Device::show( fs );
	fs << urtartalom << endl;
}
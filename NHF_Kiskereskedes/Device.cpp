#include "Device.h"

Device::Device( string gy, double efogy, string eoszt, int az )
	: gyarto( gy )
	, efogyaszt( efogy )
	, eosztaly( eoszt )
	, azonosito( az ) 
{}


int Device::getAzon()
{
	return azonosito;
}


Device::~Device()
{}


void Device::show( std::ostream& os )
{
	os << "\tGyarto:\t\t\t\t" << gyarto << endl <<
		"\tAtlagos energiafogyasztas:\t" << efogyaszt << " kWh" << endl <<
		"\tEnergiaosztaly:\t\t\t" << eosztaly << endl <<
		"\tAzonosito:\t\t\t" << azonosito << endl;
}

void Device::show( std::fstream& fs )
{
	fs  <<	gyarto		<< endl 
		<<  efogyaszt	<< endl
		<<	eosztaly	<< endl
		<<	azonosito	<< endl;
}
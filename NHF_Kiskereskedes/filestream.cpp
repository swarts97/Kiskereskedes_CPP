#include "filestream.h"

void read( std::fstream &fs, Container *tarolo )
{
	string gyarto;
	double efogyaszt;
	string eosztaly;
	int azonosito;

	int talcasugar;
	int urtartalom;
	int maxhofok;
	bool cappuccino;

	int szamlalo = 0;

	enum Tipus
	{
		mikro,
		huto,
		mosogato,
		kave
	};

	Tipus fajta;						// Mikro / Huto / Mosogato / Kave
	string line;						// Utoljára beolvasott sor

	while ( getline( fs, line ) )
	{
		switch ( szamlalo )
		{

		case 0:
			gyarto = line;
			szamlalo = (szamlalo + 1) % 5;
			break;

		case 1:
			efogyaszt = stod( line );
			szamlalo = (szamlalo + 1) % 5;
			break;

		case 2:
			eosztaly = line;
			szamlalo = (szamlalo + 1) % 5;
			break;

		case 3:
			azonosito = stoi( line );

			switch ( line.c_str()[0] - '0' )	// Beolvasott sor 1. karaktere (int)
			{

			case 1:
				fajta = mikro;
				break;
			case 2:
				fajta = huto;
				break;
			case 3:
				fajta = mosogato;
				break;
			case 4:
				fajta = kave;
				break;

			}

			szamlalo = (szamlalo + 1) % 5;
			break;
		case 4:

			switch ( fajta )
			{
				case mikro:
				{
					talcasugar = stoi( line );
					Micro *mikro = new Micro( gyarto, efogyaszt, eosztaly, azonosito, talcasugar );
					tarolo->add( mikro );
					break;
				}
				case huto:
				{
					urtartalom = stoi( line );
					Fridge *huto = new Fridge( gyarto, efogyaszt, eosztaly, azonosito, urtartalom );
					tarolo->add( huto );
					break;
				}
				case mosogato:
				{
					maxhofok = stoi( line );
					Washing *mosogato = new Washing( gyarto, efogyaszt, eosztaly, azonosito, maxhofok );
					tarolo->add( mosogato );
					break;
				}				
				case kave:
				{
					cappuccino = (strcmp( line.c_str(), "Igen" ) == 0) ? true : false;
					Coffee *kave = new Coffee( gyarto, efogyaszt, eosztaly, azonosito, cappuccino );
					tarolo->add( kave );
					break;
				}
			}

			szamlalo = (szamlalo + 1) % 5;
			break;
		}
	}
}

void write( std::fstream &fs, Container *tarolo )
{
	tarolo->show( fs );
}
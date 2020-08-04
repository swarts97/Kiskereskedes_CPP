#include "main.h"

int main()
{
	bool quit = false;
	Container *lista = new Container;
	
	fstream myfile;
	myfile.open( "Text.txt", ios::in );
	if ( myfile.is_open() )
	{
		read( myfile, lista );
		myfile.close();
	}
	else
		cout << "Nem sikerult megnyitni a fajlt.";


	while ( quit == false )
	{
		try
		{
			menu( lista, &quit );
		}
		catch ( const char* hibauzenet )
		{
			hiba();
			cout << hibauzenet << endl << endl;
		}
	}
	myfile.open( "Text.txt", ios::out | ios::trunc );
	write( myfile, lista );
	myfile.close(); 

	return 0;
}
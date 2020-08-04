#include "menu.h"

int fomenu()
{
	cout << "Kerem valasszon az alabbi lehetosegek kozul:" << endl << endl;
	cout << "\t1 - uj eszkoz felvetele" << endl;
	cout << "\t2 - meglevo eszkoz torlese" << endl;
	cout << "\t3 - eszkozok kilistazasa" << endl;
	cout << "\t4 - raktaron levo eszkozok szama" << endl;
	cout << "\t5 - kilepes" << endl << endl;

	cout << "Kerem valasszon az alabbi menupontok kozul a megfelelo szam beirasaval: ";
	int gomb1;
	cin >> gomb1;
	cout << endl;
	if ( !(gomb1 == 1 || gomb1 == 2 || gomb1 == 3 || gomb1 == 4 || gomb1 == 5) )
	{
		throw "Hibas valaszopcio!";
	}
	return gomb1;
}

int menu1Type()
{
	cout << "\t1 - Mikrohullamu suto\t\t ________________________________"  << endl;
	cout <<		 "\t2 - Hutoszekreny\t\t| Az eszkoz tipusszama lesz az   |" << endl;
	cout <<		"\t3 - Mosogatogep\t\t\t| azonositojanak elso szamjegye! |" << endl;
	cout <<		"\t4 - Kavefozogep\t\t\t|________________________________|" << endl << endl;
	cout <<	"Kerem valassza ki az uj eszkoz tipusat: ";
	int gomb2;
	cin >> gomb2;
	cout << endl;
	if ( !(gomb2 == 1 || gomb2 == 2 || gomb2 == 3 || gomb2 == 4) )
	{
		throw "Hibas valaszopcio!";
	}
	return gomb2;
}

void menu1( Container *tarolo )
{
	int gomb2 = menu1Type();

	string gyarto;
	double efogyaszt;
	string eosztaly;
	int azonosito;

	cout << "Kerem adja meg az eszkoz gyartojanak nevet: ";
	cin >> gyarto;
	cout << endl;

	cout << "Kerem adja meg az eszkoz atlagos energiafogyasztasat (kWh): ";
	cin >> efogyaszt;
	cout << endl;

	cout << "Kerem adja meg az eszkoz energiaosztalyat: ";
	cin >> eosztaly;
	cout << endl;

	cout << "Kerem adja meg az eszkoz azonositojat (maximum ertek: 999): ";
	cin >> azonosito;
	if ( azonosito < 1000 && azonosito >= 0 )
	{
		azonosito = gomb2 * 1000 + azonosito;
		cout << endl;
	}
	else
		throw "A megadott szamnak 0 es 999 koze kell esnie!";

	switch ( gomb2 )
	{
	case 1:
		{
			int sugar;
			cout << "Kerem adja meg a talca sugarat: ";
			cin >> sugar;
			cout << endl;

			Micro *dev1 = new Micro( gyarto, efogyaszt, eosztaly, azonosito, sugar );
			tarolo->add( dev1 );
			break;
		}

	case 2:
		{
			int urtart;
			cout << "Kerem adja meg a huto urtartalmat: ";
			cin >> urtart;
			cout << endl;

			Fridge *dev2 = new Fridge( gyarto, efogyaszt, eosztaly, azonosito, urtart );
			tarolo->add( dev2 );
			break;
		}

	case 3:
		{
			int hofok;
			cout << "Kerem adja meg a maximalis hofokot: ";
			cin >> hofok;
			cout << endl;

			Washing *dev3 = new Washing( gyarto, efogyaszt, eosztaly, azonosito, hofok );
			tarolo->add( dev3 );
			break;
		}

	case 4:
		{
			bool capp;
			int lehete_capp;
			cout << "1 - Igen" << endl
				 << "2 - Nem" << endl;
			cout << "Kerem adja meg, hogy lehet-e cappuccinot fozni: ";
			cin >> lehete_capp;
			cout << endl;

			if		( lehete_capp == 1 )
				capp = true;
			else if ( lehete_capp == 2 )
				capp = false;
			else
				throw "Hibas valasz!";

			Coffee *dev4 = new Coffee( gyarto, efogyaszt, eosztaly, azonosito, capp );
			tarolo->add( dev4 );
			break;
		}
	}
}

void menu2( Container *tarolo )
{
	int azon;
	cout << "Kerem adja meg az eltavolitando eszkoz azonositojat: ";
	cin >> azon;
	Device* dev = tarolo->search( tarolo, azon );
	tarolo->remove( dev );
}

void menu3( Container *tarolo )
{
	tarolo->show( cout );
}

void menu4( Container *tarolo )
{
	cout << "\t _________________________________________________"						 << endl;
	cout << "\t|\tA raktaron jelenleg " << tarolo->db << " db eszkoz van.\t  |"  << endl;
	cout << "\t|_________________________________________________|"					 << endl << endl;
}

void menu5( bool *quit )
{
	*quit = true;
}

void menu( Container *tarolo, bool *quit )
{
	int gomb1 = fomenu();
	switch ( gomb1 )
	{
	case 1:
		menu1( tarolo );
		break;
	case 2:
		menu2( tarolo );
		break;
	case 3:
		menu3( tarolo );
		break;
	case 4:
		menu4( tarolo );
		break;
	case 5:
		menu5( quit );
		break;
	}
}

void hiba()
{
	cout << endl;
	cout << "\t ____________________________"  << endl;
	cout << "\t| A program futasa soran a   |" << endl;
	cout << "\t| kovetkezo hiba lepett fel: |" << endl;
	cout << "\t|____________________________|" << endl << endl;
}

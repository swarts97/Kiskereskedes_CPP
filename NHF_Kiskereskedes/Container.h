#ifndef CONTAINER_H
#define CONTAINER_H

#include "Device.h"

class ListElem
{
public:
	ListElem *kov;
	Device *eszkoz;
};

class Container
{
public:
	int db;
	ListElem *eleje;

	Container();
	~Container();

	void add( Device *dev );
	void remove( Device *dev );
	void show( std::ostream &os );
	void show( std::fstream &fs );
	Device* search(Container *tarolo, int azon);
};

#endif
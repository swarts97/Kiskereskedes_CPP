#include "Container.h"


Container::Container()
	: db( 0 )
	, eleje( NULL )
{}


Container::~Container()
{
	ListElem *mozgo, *next;
	mozgo = eleje;
	while ( mozgo != NULL )
	{
		next = mozgo->kov;
		delete mozgo;
		mozgo = next;
	}
}


void Container::add( Device *dev )
{
	ListElem *elem = new ListElem;
	elem->eszkoz = dev;
	elem->kov = eleje;
	eleje = elem;
	db++;
}


void Container::remove( Device *dev )
{
	ListElem *lemarado, *mozgo;
	lemarado = NULL;
	mozgo = eleje;
	while ( mozgo != NULL && mozgo->eszkoz != dev )
	{
		lemarado = mozgo;
		mozgo = mozgo->kov;
	}

	if ( mozgo == eleje )
	{
		ListElem *ujeleje = eleje->kov;
		delete eleje;
		db--;
		eleje = ujeleje;
	}
	else if ( mozgo == NULL )
	{
		// nincs ilyen elem
	}
	else
	{
		lemarado->kov = mozgo->kov;
		delete mozgo;
		db--;
	}
}


void Container::show( std::ostream& os )
{
	ListElem *mozgo;
	mozgo = eleje;
	while ( mozgo != NULL )
	{
		mozgo->eszkoz->show( os );
		mozgo = mozgo->kov;
	}
}

void Container::show( std::fstream& fs )
{
	ListElem *mozgo;
	mozgo = eleje;
	while ( mozgo != NULL )
	{
		mozgo->eszkoz->show( fs );
		mozgo = mozgo->kov;
	}
}

Device* Container::search( Container *tarolo, int azon )
{
	ListElem *mozgo = eleje;
	while ( mozgo != NULL && azon != mozgo->eszkoz->getAzon() )
	{
		mozgo = mozgo->kov;
	}
	if ( mozgo != NULL )
		return mozgo->eszkoz;
	else
		throw "Nincs ilyen azonositoju eszkoz a rendszerben.";
}

#ifndef MENU_H
#define MENU_H

#include "Container.h"
#include "Coffee.h"
#include "Fridge.h"
#include "Micro.h"
#include "Washing.h"

int fomenu();
int menu1Type();
void menu1( Container *tarolo );
void menu2( Container *tarolo );
void menu3( Container *tarolo );
void menu4( Container *tarolo );
void menu5( bool *quit );
void menu( Container *tarolo, bool *quit );
void hiba();

#endif
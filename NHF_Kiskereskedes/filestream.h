#include <fstream>
#include <cstring>
#include "Device.h"
#include "Coffee.h"
#include "Fridge.h"
#include "Micro.h"
#include "Washing.h"
#include "Container.h"

void read( std::fstream & fs, Container *tarolo );
void write( std::fstream & fs, Container *tarolo );
#include <iostream>
#include <vector>
#include <map>
#include "../../include/exportar.h"
#include "../../include/Animal.h"
int main(int argc, char const *argv[])
{   
    std::vector<exportar::Filter> filters = exportar::buildFilters(argc, argv);
    std::multimap<std::string, Animal*>  animals = exportar::getAnimalByFilters(&filters);
    exportar::saveAnimals(animals, argv[argc-1]);
    return 0;
}

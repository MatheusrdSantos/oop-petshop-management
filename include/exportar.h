#ifndef _EXPORTARLIB_H_
#define _EXPORTARLIB_H_
#include <map>
#include <vector>
#include "Animal.h"
namespace exportar
{
    class Filter{
        public:
            std::string m_key;
            std::string m_value;
        Filter();
        Filter(std::string key, std::string value);
        ~Filter(){};
    };

    std::vector<Filter> buildFilters(int argc, char const *argv[]);

    std::multimap<std::string, Animal*> getAnimalByFilters(std::vector<Filter> *filters = NULL);

    bool matchFilter(std::vector<Filter> *filters, Animal *Animal);

    void saveAnimals(std::multimap<std::string, Animal*> animals, std::string filename);
} // namespace exportar


#endif
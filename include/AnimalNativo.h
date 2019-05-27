#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <iostream>
#include <string>
#include "AnimalSilvestre.h"

class AnimalNativo : public AnimalSilvestre{
    private:

    protected:
        std::string m_uf_origem;
        
    public:
        AnimalNativo();
        ~AnimalNativo(){};
};

#endif
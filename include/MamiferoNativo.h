#ifndef _MAMIFERO_NATIVO_H_
#define _MAMIFERO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Reptil.h"

class MamiferoNativo : public Mamifero, public AnimalNativo{
    private:

    protected:
        
    public:
        MamiferoNativo();
        ~MamiferoNativo(){};
};

#endif
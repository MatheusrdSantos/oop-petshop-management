#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Mamifero.h"

class MamiferoExotico : public Mamifero, public AnimalExotico{
    private:

    protected:
        
    public:
        MamiferoExotico();
        ~MamiferoExotico(){};
};

#endif
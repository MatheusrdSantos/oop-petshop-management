#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Anfibio.h"

class AnfibioExotico : public Anfibio, public AnimalExotico{
    private:

    protected:
        
    public:
        AnfibioExotico();
        ~AnfibioExotico(){};
};

#endif
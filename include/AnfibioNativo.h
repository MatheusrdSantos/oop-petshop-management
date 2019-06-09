#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Anfibio.h"

class AnfibioNativo : public Anfibio, public AnimalNativo{
    private:

    protected:
        
    public:
        AnfibioNativo();
        ~AnfibioNativo(){};

        std::string printInFile(int id);
};

#endif
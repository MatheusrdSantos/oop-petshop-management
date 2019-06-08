#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Reptil.h"

class ReptilNativo : public Reptil, public AnimalNativo{
    private:

    protected:
        
    public:
        ReptilNativo();
        ~ReptilNativo(){};


        std::string printInFile(int id);
};

#endif
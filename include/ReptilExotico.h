#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Reptil.h"

class ReptilExotico : public Reptil, public AnimalExotico{
    private:

    protected:
        
    public:
        ReptilExotico();
        ~ReptilExotico(){};

        std::string printInFile(int id);
};

#endif
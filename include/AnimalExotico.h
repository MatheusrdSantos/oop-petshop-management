#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <iostream>
#include <string>
#include "AnimalSilvestre.h"

class AnimalExotico : public AnimalSilvestre{
    private:

    protected:
        std::string m_pais_origem;
        std::string m_cidade_origem;
        
    public:
        AnimalExotico();
        ~AnimalExotico(){};

        std::string getPaisOrigem();
        void setPaisOrigem(std::string pais_origem);

        std::string getCidadeOrigem();
        void setCidadeOrigem(std::string cidade_origem);

};

#endif
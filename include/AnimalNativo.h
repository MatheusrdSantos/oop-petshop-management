#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <iostream>
#include <string>
#include "AnimalSilvestre.h"

class AnimalNativo : public AnimalSilvestre{
    private:

    protected:
        std::string m_uf_origem;
        std::string m_cidade_origem;
        
    public:

        std::string getUfOrigem();
        void setUfOrigem(std::string uf_origem);

        std::string getCidadeOrigem();
        void setCidadeOrigem(std::string cidade_origem);
};

#endif
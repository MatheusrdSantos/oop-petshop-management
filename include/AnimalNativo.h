#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <iostream>
#include <string>

class AnimalNativo{
    private:

    protected:
        std::string m_uf_origem;
        std::string m_autorizacao;
        
    public:
        AnimalNativo();
        ~AnimalNativo(){};
};

#endif
#ifndef _AVE_H
#define _AVE_H

#include <iostream>
#include <string>
#include "Animal.h"

class Ave : public Animal{
    private:

    protected:
        double m_tamanho_do_bico_cm;
        double m_envergadura_das_asas;
    public:
        Ave();
        ~Ave(){};
        virtual std::string printInFile(int id) = 0;

        

};

#endif
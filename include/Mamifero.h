#ifndef _MAMIFERO_H
#define _MAMIFERO_H

#include <iostream>
#include <string>
#include "Animal.h"

class Mamifero : public Animal{
    private:

    protected:
        std::string m_cor_do_pelo;
    public:
        Mamifero();
        ~Mamifero(){};

        std::string getCorDoPelo();
        void setCorDoPelo(std::string cor_do_pelo);
};

#endif
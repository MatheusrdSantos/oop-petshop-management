#ifndef _ANFIBIO_H
#define _ANFIBIO_H
#include "Date.h"
#include "Animal.h"

#include <iostream>
#include <string>
#include "Animal.h"

class Anfibio : public Animal{
    private:

    protected:
        int m_total_de_mudas;
        Date* m_ultima_muda;
    public:
        Anfibio();
        ~Anfibio(){};
    
        virtual std::string printInFile(int id) = 0;
};

#endif
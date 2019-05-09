#ifndef _ANFIBIO_H
#define _ANFIBIO_H
#include "Data.h"

#include <iostream>
#include <string>

class Anfibio{
    private:

    protected:
        int m_total_de_mudas;
        Data m_classe;
    public:
        Anfibio();
        ~Anfibio(){};
};

#endif
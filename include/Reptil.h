#ifndef _REPTIL_H
#define _REPTIL_H

#include <iostream>
#include <string>

class Reptil{
    private:

    protected:
        bool m_venenoso;
        std::string m_tipo_veneno;
    public:
        Reptil();
        ~Reptil(){};
};

#endif
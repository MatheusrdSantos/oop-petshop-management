#ifndef _ANIMAL_H
#define _ANIMAL_H
#include "Veterinario.h"
#include "Tratador.h"

#include <iostream>
#include <string>

class Animal{
    private:

    protected:
        int m_id;
        std::string m_classe;
        std::string m_nome_cientifico;
        char m_sexo;
        double m_tamanho;
        std::string m_dieta;
        //Veterinario m_veterinario;
        //Tratador m_tratador;
        std::string m_nome_batismo;
    public:
        Animal();
        //Animal(...);
        ~Animal(){};
};

#endif
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

        Ave(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas);

        Ave(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas);

        ~Ave(){};
        virtual std::string printInFile(int id) = 0;

};

#endif
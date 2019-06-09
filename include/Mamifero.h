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

        Mamifero(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);

        Mamifero(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);

        Mamifero(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);

        std::string getCorDoPelo();
        void setCorDoPelo(std::string cor_do_pelo);

        virtual std::string printInFile(int id) = 0;
};

#endif
#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Reptil.h"

class ReptilNativo : public Reptil, public AnimalNativo{
    private:

    protected:
        
    public:
        ReptilNativo();

        ReptilNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        ReptilNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        ReptilNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        ~ReptilNativo(){};


        std::string printInFile(int id);
};

#endif
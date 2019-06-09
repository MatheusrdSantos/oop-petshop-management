#ifndef _MAMIFERO_NATIVO_H_
#define _MAMIFERO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Mamifero.h"

class MamiferoNativo : public Mamifero, public AnimalNativo{
    private:

    protected:
        
    public:
        MamiferoNativo();
        ~MamiferoNativo(){};

        MamiferoNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        MamiferoNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        MamiferoNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        std::string printInFile(int id);
};

#endif
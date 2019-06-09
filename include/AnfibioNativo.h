#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Anfibio.h"

class AnfibioNativo : public Anfibio, public AnimalNativo{
    private:

    protected:
        
    public:
        AnfibioNativo();

        AnfibioNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas, Date* ultima_muda, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        AnfibioNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas, Date* ultima_muda, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        ~AnfibioNativo(){};

        std::string printInFile(int id);
};

#endif
#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Mamifero.h"

class MamiferoExotico : public Mamifero, public AnimalExotico{
    private:

    protected:
        
    public:
        MamiferoExotico();
        ~MamiferoExotico(){};
        
        MamiferoExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        MamiferoExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        MamiferoExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);

        std::string printInFile(int id);
};

#endif
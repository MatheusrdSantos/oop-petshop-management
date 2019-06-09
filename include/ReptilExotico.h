#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Reptil.h"

class ReptilExotico : public Reptil, public AnimalExotico{
    private:

    protected:
        
    public:
        ReptilExotico();
        ~ReptilExotico(){};

        ReptilExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        ReptilExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        ReptilExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);

        std::string printInFile(int id);
};

#endif
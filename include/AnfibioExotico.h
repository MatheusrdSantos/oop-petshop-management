#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <iostream>
#include <string>
#include "AnimalExotico.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "Anfibio.h"

class AnfibioExotico : public Anfibio, public AnimalExotico{
    private:

    protected:
        
    public:
        AnfibioExotico();
        AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo);
        
        ~AnfibioExotico(){};

        std::string printInFile(int id);
};

#endif
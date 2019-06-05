#ifndef _AVE_EXOTICO_H_
#define _AVE_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"

class AveExotico : public Ave, public AnimalExotico{
    private:

    protected:
        
    public:
        AveExotico();
        ~AveExotico(){};


        AveExotico(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, const Veterinario &veterinario, const Tratador &tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, pais_origem, cidade_origem);
};

#endif
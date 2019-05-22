/* 
Class: Veterinario
Author: Arnaldo Barbosa    
*/
#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include "Funcionario.h"
#include<string>
#include <fstream>

class Veterinario : public Funcionario{

    private:
        std::string m_crmv;
    
    public:
        Veterinario();
        Veterinario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string crmv);
        ~Veterinario(){};
        void setCrmv(std::string m_crmv);
        std::string getCrmv();
        bool save();
};
    
#endif
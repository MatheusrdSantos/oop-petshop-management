/* 
Class: Veterinario
Author: Arnaldo Barbosa    
*/
#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include "Funcionario.h"
#include <iostream>
#include <string>
#include <fstream>

class Veterinario : public Funcionario{

    private:
        std::string m_cnmv;
    
    public:
        Veterinario();
        Veterinario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv);
        Veterinario(std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv);
        ~Veterinario(){};
        void setCnmv(std::string cnmv);
        std::string getCnmv();
        bool save();
};
    
#endif
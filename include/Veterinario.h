/* 
Class: Veterinario
Author: Arnaldo Barbosa    
*/
#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include"Funcionario.h"
#include<string>

class Veterinario : public Funcionario{

    private:
        std::string m_crmv;
    
    public:
        Veterinario();
        ~Veterinario();
        void setCrmv(std::string m_crmv);
};
    
#endif
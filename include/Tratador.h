/* 
Class: Tratador
Author: Arnaldo Barbosa    
*/
#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include"Funcionario.h"
#include<string>

class Tratador : public Funcionario{

    private:
        int m_nivel_de_seguranca;
    
    public:
        Tratador();
        ~Tratador();
        void setNivelDeSeguranca(std::string nivel_de_seguranca);
};
    
#endif
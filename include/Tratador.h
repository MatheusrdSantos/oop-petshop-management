/* 
Class: Tratador
Author: Arnaldo Barbosa    
*/
#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include"Funcionario.h"
#include<string>
#include<iostream>
#include<fstream>

class Tratador : public Funcionario{

    private:
        int m_nivel_de_seguranca;
    
    public:
        Tratador();
        ~Tratador();
        void setNivelDeSeguranca(int nivel_de_seguranca);
        int getNivelDeSeguranca();
        bool save();
};
    
#endif
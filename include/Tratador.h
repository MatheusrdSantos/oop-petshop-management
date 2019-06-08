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
        Tratador(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, int nivel_de_seguranca);
        Tratador(std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, int nivel_de_seguranca);
        ~Tratador(){};
        
        //DAO
        std::string printInFile(int id);
        
        //getters
        int getNivelDeSeguranca();
        
        //setters
        void setNivelDeSeguranca(int nivel_de_seguranca);
};
    
#endif
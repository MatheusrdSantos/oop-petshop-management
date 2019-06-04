/* 
Class: Funcionario
Author: Arnaldo Barbosa    
*/
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include<iostream>
#include<string>
#include <map>
#include "ModelDAO.h"

class Funcionario : public ModelDAO<Funcionario>{
    private:
        static Funcionario* buildFuncionarioFromFile(csv::Row* file);
    protected:
        int m_id;
        std::string m_nome;
        std::string m_cpf;
        short m_idade;
        short m_tipo_sanguineo;
        char m_fator_rh;
        std::string m_especialidade;
    
    public:
        Funcionario(){};
        Funcionario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade);
        ~Funcionario(){};
        static std::string filePath;
        static std::string tableName;
        static std::multimap<std::string,Funcionario*> all();
        static Funcionario* find(int id);
        std::string getNome();
};
    
#endif
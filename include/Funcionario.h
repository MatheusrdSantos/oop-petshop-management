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
        // esse método deve ser movido para uma classe utils
        // também deve ser sobrescrito para diferentes tipos de parametros
        static bool compare(std::string* value1, std::string* value2, std::string* symbol);
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

        //DAO
        static std::multimap<std::string,Funcionario*> all();
        static Funcionario* find(int id);
        // esse método será sobrescrito para diferentes tipos de valores
        // int - string - double - char
        static std::multimap<std::string, Funcionario*> where(std::string* column, std::string* separator, std::string* value);
        
        // getters
        int getId();
        std::string getNome();
        std::string getCpf();
        short getIdade();
        short getTipoSanguineo();
        char getFatorRh();
        std::string getEspecialidade();

        //setters

        void setId(int id);
        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setIdade(short idade);
        void setTipoSanguineo(short tipo);
        void setFatorRh(char fator);
        void setEspecialidade(std::string especialidade);

        bool save();

        virtual std::string printInFile(int id) = 0;
};
    
#endif
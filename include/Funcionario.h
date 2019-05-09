/* 
Class: Funcionario
Author: Arnaldo Barbosa    
*/
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include<string>

class Funcionario{

    protected:
        int m_id;
        std::string _nome;
        std::string _cpf;
        short m_idade;
        short m_tipo_sanguineo;
        char m_fator_rh;
        std::string m_especialidade;
    
    public:
        Funcionario();
        ~Funcionario();
};
    
#endif
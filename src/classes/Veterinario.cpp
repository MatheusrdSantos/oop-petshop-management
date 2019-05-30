#include "Veterinario.h"

Veterinario::Veterinario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv){
    m_id = id;
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
    m_cnmv = cnmv;
}
Veterinario::Veterinario(std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv){
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
    m_cnmv = cnmv;
}

void Veterinario::setCnmv(std::string cnmv){
    m_cnmv = cnmv;
}

std::string Veterinario::getCnmv(){
    return m_cnmv;
}

bool Veterinario::save(){
    int id = getTableIncrementId(Funcionario::tableName);
    if(id<0){
        return false;
    }
    std::ofstream file;
    file.open(Funcionario::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<id<<';'<<"Veterinario"<<';'<<m_nome<<';'<<m_cpf<<';'<<m_idade<<';'<<m_tipo_sanguineo<<';'<<m_fator_rh<<';'<<m_especialidade<<";"<<m_cnmv<<";"<<std::endl;
        m_id = id;
        updateAutoIncrement(Funcionario::tableName);
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
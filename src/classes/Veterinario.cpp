#include "../../include/Veterinario.h"

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

// DAO

std::string Veterinario::printInFile(int id){
    std::stringstream ss;
    ss<<id<<';'<<"Veterinario"<<';'<<m_nome<<';'<<m_cpf<<';'<<m_idade<<';'<<m_tipo_sanguineo<<';'<<m_fator_rh<<';'<<m_especialidade<<";"<<m_cnmv<<";"<<std::endl;
    std::string s = ss.str();
    return s;

}

//getters
std::string Veterinario::getCnmv(){
    return m_cnmv;
}

// setters
void Veterinario::setCnmv(std::string cnmv){
    m_cnmv = cnmv;
}

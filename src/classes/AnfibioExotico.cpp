#include "../../include/AnfibioExotico.h"
#include<string>

AnfibioExotico::AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo){
    m_classe = "Amphibia" ;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo ;
    m_tamanho = tamanho ;
    m_dieta = dieta ;
    m_veterinario = veterinario ;
    m_tratador = tratador ;
    m_nome_batismo = nome_batismo;
}

std::string AnfibioExotico::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
    }
    std::string s = ss.str();
    return s;
}

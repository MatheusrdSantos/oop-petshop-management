#include "../../include/Animal.h"
#include "../../include/Ave.h"
#include "../../include/AveExotico.h"

AveExotico::AveExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_id=id;
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;

    m_tamanho_do_bico_cm=tamanho_do_bico_cm;
    m_envergadura_das_asas=envergadura_das_asas;
    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;

}


std::string AveExotico::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
    }
    std::string s = ss.str();
    return s;
}

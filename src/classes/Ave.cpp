#include "../../include/Ave.h"

Ave::Ave(){
    m_classe="Aves";
}

Ave::Ave(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas){
    m_id=id;
    m_classe="Aves";
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
}

Ave::Ave(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas){
    m_classe="Aves";
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
}

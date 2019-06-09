#include "../../include/ReptilExotico.h"
#include <string>

ReptilExotico::ReptilExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
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
    
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;

    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}
        
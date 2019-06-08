#include "../../include/AnfibioExotico.h"
#include<string>

std::string AnfibioExotico::printInFile(int id){
    std::stringstream ss;
    ss<<id<<";Amphibia;"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario.getId()<<";"<<m_veterinario.getId()<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda<<";"<<";"<<";"<<";"<<";"<<std::endl;
    std::string s = ss.str();
    return s;
}

#include "../../include/AnimalExotico.h"

AnimalExotico::AnimalExotico(std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama): AnimalSilvestre(autorizacao_ibama){
    m_pais_origem = pais_origem;
    m_cidade_origem = cidade_origem;
}
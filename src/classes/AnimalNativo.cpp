#include "../../include/AnimalNativo.h"

AnimalNativo::AnimalNativo(){
    m_uf_origem = "";
    m_cidade_origem="";
}
AnimalNativo::AnimalNativo(std::string uf_origem, std::string cidade_origem){
    m_uf_origem =uf_origem;
    m_cidade_origem=cidade_origem;
}
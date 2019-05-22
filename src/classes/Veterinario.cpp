#include "Veterinario.h"

void Veterinario::setCrmv(std::string crmv){
    m_crmv = crmv;
}

std::string Veterinario::getCrmv(){
    return m_crmv;
}

bool Veterinario::save(){
    std::ofstream file;
    file.open(Funcionario::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<m_id<<';'<<"Veterinario"<<';'<<m_nome<<';'<<m_cpf<<';'<<m_idade<<';'<<m_tipo_sanguineo<<';'<<m_fator_rh<<';'<<m_especialidade<<';'<<m_crmv<<';'<<std::endl;
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
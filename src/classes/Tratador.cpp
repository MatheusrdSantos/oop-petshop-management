#include "Tratador.h"

void Tratador::setNivelDeSeguranca(int nivel_de_seguranca){
    m_nivel_de_seguranca = nivel_de_seguranca;
}

int Tratador::getNivelDeSeguranca(){
    return m_nivel_de_seguranca;
}

bool Tratador::save(){
    std::ofstream file;
    file.open(Funcionario::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<m_id<<';'<<"Tratador"<<';'<<m_nome<<';'<<m_cpf<<';'<<m_idade<<';'<<m_tipo_sanguineo<<';'<<m_fator_rh<<';'<<m_especialidade<<';'<<';'<<m_nivel_de_seguranca<<std::endl;
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
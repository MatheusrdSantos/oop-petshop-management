#include "../../include/Animal.h"
#include "../../include/Ave.h"
#include "../../include/AveExotico.h"

bool AveExotico::save(){
    int id = getTableIncrementId(Animal::tableName);
    if(id<0){
        return false;
    }
    std::ofstream file;
    file.open(Animal::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<id<<';'<<m_classe<<';'<<m_nome<<';'<<m_nome_batismo<<';'<<m_sexo<<';'<<m_tamanho<<';'<<m_dieta<<';'<<m_veterinario.getId()<<';'<<m_tratador.getId()<<';'<<m_nome_batismo<<";;"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";;"<<";;"<<";;"<<";;"<<";;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        m_id = id;
        updateAutoIncrement(Animal::tableName);
    }else{
        std::cerr<<"Couldn't save the file!"<<std::endl;
    }
    file.close();

    return true;
}
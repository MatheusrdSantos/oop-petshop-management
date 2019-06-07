#include "Animal.h"
#include "Ave.h"
#include "Ave.h"
#include "AveExotico.h"

bool AveExotico::save(){
    int id = getTableIncrementId(Animal::tableName);
    if(id<0){
        return false;
    }
    std::ofstream file;
    file.open(Animal::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<id<<';'<<"Tratador"<<';'<<m_nome<<';'<<m_cpf<<';'<<m_idade<<';'<<m_tipo_sanguineo<<';'<<m_fator_rh<<';'<<m_especialidade<<';'<<';'<<m_nivel_de_seguranca<<std::endl;
        m_id = id;
        updateAutoIncrement(Animal::tableName);
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
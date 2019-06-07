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
        file<<id<<';'<<m_classe<<';'<<m_nome_batismo<<';'<<m_nome_batismo<<';'<<m_sexo<<';'<<m_tamanho<<';'<<m_dieta<<';'<<std::endl;
        m_id = id;
        updateAutoIncrement(Animal::tableName);
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
#include "../../include/Animal.h"
#include "../../include/Tratador.h"
#include "../../include/Veterinario.h"
#include "../../include/CSVparser.hpp"

std::string Animal::filePath = "./storage/animais.csv";
std::string Animal::tableName = "animais";

/*
Animal::Animal(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, const Veterinario &veterinario, const Tratador &tratador, std::string nome_batismo){
    m_id = id;
    m_classe = classe ;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo ;
    m_tamanho = tamanho ;
    m_dieta = dieta ;
    m_veterinario = veterinario ;
    m_tratador = tratador ;
    m_nome_batismo = nome_batismo;
}
*/
/*
std::multimap<std::string,Animal*> Animal::all(){

    csv::Parser file = ModelDAO<Animal>::readTable();
    std::multimap<std::string,Animal*> Animals;
    int n_rows = file.rowCount();
    std::cout<<"N_rows: "<<n_rows<<std::endl;
    int n_columns = file.columnCount();
    std::cout<<"N_columns: "<<n_columns<<std::endl;


    for(int i = 0; i<n_rows; i++){

    }

    return Animals;
}
*/
std::string Animal::getNomeBatismo(){
    return m_nome_batismo;
}

bool Animal::save(){
    int id = getTableIncrementId(Animal::tableName);
    if(id<0){
        return false;
    }
    std::ofstream file;
    file.open(Animal::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        file<<printInFile(id);
        m_id = id;
        updateAutoIncrement(Animal::tableName);
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
        return false;
    }

    file.close();
    return true;
}
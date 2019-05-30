#include "Animal.h"
#include "CSVparser.hpp"

#include "Animal.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "CSVparser.hpp"

std::string Animal::filePath = "./storage/animals.csv";
Animal::Animal(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade){
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

std::string Animal::getNome(){
    return m_nome;
}
#include "Animal.h"
#include "CSVparser.hpp"

#include "Animal.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "CSVparser.hpp"

std::string Animal::filePath = "./storage/Animals.csv";
Animal::Animal(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade){
    m_id = id;
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
}

std::multimap<std::string,Animal*> Animal::all(){
    csv::Parser file = ModelDAO<Animal>::readTable();
    std::multimap<std::string,Animal*> Animals;
    int n_rows = file.rowCount();
    std::cout<<"N_rows: "<<n_rows<<std::endl;
    int n_columns = file.columnCount();
    std::cout<<"N_columns: "<<n_columns<<std::endl;


    for(int i = 0; i<n_rows; i++){
        
        /* Recupera os campos do arquivo csv*/
        int id = std::stoi(file[i][0]);
        std::string nome = file[i][2];
        std::string cpf = file[i][3];
        short idade = std::stoi(file[i][4]);
        short tipo_sanguineo = std::stoi(file[i][5]);
        char fator_rh = file[i][6][0];
        std::string especialidade = file[i][7];
        /* Estancia dinamicamente um novo Animal */
        
        
        /* faz o downcasting para tratador ou veterinario */
        if(file[i][1] == "Tratador"){

            //Método construtor de tratador + upcasting para funcionário
            Animal* Animal;
            Tratador* tratador = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, stoi(file[i][9]));
            Animal = tratador;

            Animals.insert(std::pair<std::string, Animal*>("tratador", Animal));

        }else if(file[i][1] == "Veterinario"){
            // Oitava coluna representa o código cnmv
            std::string cnmv = file[i][8];


            //Método construtor de veterinário + upcasting para funcionário
            Animal* Animal;
            Veterinario* veterinario = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, file[i][8]);
            Animal = veterinario;

            Animals.insert(std::pair<std::string, Animal*>("veterinario", Animal));
        }     

    }

    return Animals;
}

std::string Animal::getNome(){
    return m_nome;
}
#include "Funcionario.h"

std::string Funcionario::filePath = "../../storage/funcionarios.csv";
Funcionario::Funcionario(int id, std::string nome, std::string cpf, short idade, short 

tipo_sanguineo, char fator_rh, std::string especialidade){
    m_id = id;
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
}

std::multimap<std::string,Funcionario*> Funcionario::all(){
    csv::Parser file = ModelDAO::readTable(Funcionario::filePath);
    std::multimap<std::string,Funcionario*> funcionarios;
    int n_rows = file.rowCount();
    int n_columns = file.columnCount();

    for(int i = 0; i<n_rows; i++){
        
        /* Recupera os campos do arquivo csv*/
        int id = std::stoi(file[i][0]);
        std::string nome = file[i][1];
        std::string cpf = file[i][2];
        short idade = std::stoi(file[i][3]);
        short tipo_sanguineo = std::stoi(file[i][4]);
        char fator_rh = file[i][5][0];
        std::string especialidade = file[i][6];
        
        /* Estancia dinamicamente um novo funcionario */
        Funcionario* funcionario = new Funcionario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);
        
        /* faz o downcasting para tratador ou veterinario */
        
        if(file[i][8] != ""){
            // so funciona se funcionario tiver um metodo virtual
            //Tratador* tratador = dynamic_cast<Tratador*>(func);

            Tratador* tratador = (Tratador*) funcionario; 
            tratador->setNivelDeSeguranca(file[i][8]);
            
            // faz o upcasting de volta para funcionario
            funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", (Funcionario*)tratador));
        }else{
            // so funciona se funcionario tiver um metodo virtual
            //Veterinario* veterinario = dynamic_cast<Veterinario*>(func);

            Veterinario* veterinario = (Veterinario*) funcionario;
            veterinario->setCrmv(file[i][7]);

            // faz o upcasting de volta para funcionario
            funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", (Funcionario*)veterinario));
        }     

    }

    return funcionarios;
}
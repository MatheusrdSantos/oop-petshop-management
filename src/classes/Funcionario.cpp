#include "../../include/Funcionario.h"
#include "../../include/Tratador.h"
#include "../../include/Veterinario.h"
#include "../../include/Animal.h"
#include "../../include/CSVparser.hpp"

std::string Funcionario::filePath = "./storage/funcionarios.csv";
std::string Funcionario::tableName = "funcionarios";
Funcionario::Funcionario(int id, std::string nome, std::string cpf, short idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade){
    m_id = id;
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
}
Funcionario::Funcionario(std::string nome, std::string cpf, short idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade){
    m_nome = nome;
    m_cpf = cpf;
    m_idade = idade;
    m_tipo_sanguineo = tipo_sanguineo;
    m_fator_rh = fator_rh;
    m_especialidade = especialidade;
}

// DAO
std::multimap<std::string,Funcionario*> Funcionario::all(){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    std::multimap<std::string,Funcionario*> funcionarios;
    int n_rows = file.rowCount();

    for(int i = 0; i<n_rows; i++){
        /* Estancia dinamicamente um novo funcionario */
        Funcionario* funcionario;
        funcionario = buildFuncionarioFromFile(&file[i]);

        /* faz o downcasting para tratador ou veterinario */
        if(file[i][1] == "Tratador"){
            funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", funcionario));

        }else if(file[i][1] == "Veterinario"){
            funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", funcionario));
        }     

    }

    return funcionarios;
}

Funcionario* Funcionario::buildFuncionarioFromFile(csv::Row* file){
    int id = std::stoi((*file)["id"]);
    std::string nome = (*file)["nome"];
    std::string cpf = (*file)["cpf"];
    short idade = std::stoi((*file)["idade"]);
    std::string tipo_sanguineo = (*file)["tipo_sangue"];
    char fator_rh = (*file)["fator_rh"][0];
    std::string especialidade = (*file)["especialidade"];
    /* Estancia dinamicamente um novo funcionario */

    /* faz o downcasting para tratador ou veterinario */
    if((*file)[1] == "Tratador"){

        //Método construtor de tratador + upcasting para funcionário
        Funcionario* funcionario;
        Tratador* tratador = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, stoi((*file)["nivel_seguranca"]));
        funcionario = tratador;
        return funcionario;

    }else if((*file)[1] == "Veterinario"){
        // Oitava coluna representa o código cnmv
        //std::string cnmv = (*file)[8];


        //Método construtor de veterinário + upcasting para funcionário
        Funcionario* funcionario;
        Veterinario* veterinario = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, (*file)["codigo_cnmv"]);
        funcionario = veterinario;

        return funcionario;
    }
    Funcionario* f = NULL;
    return f;
}

// procura por id
Funcionario* Funcionario::find(int id){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    int n_rows = file.rowCount();
    for (int i = 0; i < n_rows; i++)
    {
        if(id == std::stoi(file[i]["id"])){
            /* Recupera os campos do arquivo csv*/
            return buildFuncionarioFromFile(&file[i]);
        }
    }
    Funcionario* f = NULL;
    return f;
}

std::multimap<std::string, Funcionario*> Funcionario::where(std::string* column, std::string* symbol, std::string* value){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    std::multimap<std::string,Funcionario*> funcionarios;
    int n_rows = file.rowCount();
    for (int i = 0; i < n_rows; i++)
    {
        std::string val = file[i][(*column)];
        if(compare(&val, value, symbol)){
            Funcionario* funcionario = Funcionario::buildFuncionarioFromFile(&file[i]);
            /* faz o downcasting para tratador ou veterinario */
            if(file[i]["funcao"] == "Tratador"){
                funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", funcionario));

            }else if(file[i]["funcao"] == "Veterinario"){
                funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", funcionario));
            }  
        }
    }
    return funcionarios;
}

std::multimap<std::string, Funcionario*> Funcionario::where(std::string* column, std::string* symbol, int value){
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    std::multimap<std::string,Funcionario*> funcionarios;
    int n_rows = file.rowCount();
    std::vector<std::string> header = file.getHeader();
    for (int i = 0; i < n_rows; i++)
    {
        int val = std::stoi(file[i][(*column)]);
        if(compare(val, value, symbol)){
            Funcionario* funcionario = Funcionario::buildFuncionarioFromFile(&file[i]);
            /* faz o downcasting para tratador ou veterinario */
            if(file[i]["funcao"] == "Tratador"){
                funcionarios.insert(std::pair<std::string, Funcionario*>("tratador", funcionario));

            }else if(file[i]["funcao"] == "Veterinario"){
                funcionarios.insert(std::pair<std::string, Funcionario*>("veterinario", funcionario));
            }  
        }
    }
    return funcionarios;
}


// getters
int Funcionario::getId(){
    return m_id;
}

std::string Funcionario::getNome(){
    return m_nome;
}

std::string Funcionario::getCpf(){
    return m_cpf;
}

short Funcionario::getIdade(){
    return m_idade;
}

std::string Funcionario::getTipoSanguineo(){
    return m_tipo_sanguineo;
}

char Funcionario::getFatorRh(){
    return m_fator_rh;
}

std::string Funcionario::getEspecialidade(){
    return m_especialidade;
}

//setters

void Funcionario::setId(int id){
    m_id = id;
}

void Funcionario::setNome(std::string nome){
    m_nome = nome;
}

void Funcionario::setCpf(std::string cpf){
    m_cpf = cpf;
}

void Funcionario::setIdade(short idade){
    m_idade = idade;
}

void Funcionario::setTipoSanguineo(short tipo){
    m_tipo_sanguineo = tipo;
}

void Funcionario::setFatorRh(char fator){
    m_fator_rh = fator;
}

void Funcionario::setEspecialidade(std::string especialidade){
    m_especialidade = especialidade;
}

bool Funcionario::save(){
    int id = getTableIncrementId(Funcionario::tableName);
    if(id<0){
        return false;
    }
    std::ofstream file;
    file.open(Funcionario::filePath, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        file<<printInFile(id);
        m_id = id;
        updateAutoIncrement(Funcionario::tableName);
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
        return false;
    }

    file.close();
    return true;
}

bool Funcionario::update(){
    // recupera os dados do csv
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    unsigned n_rows = file.rowCount();
    
    // cria um stream de escrita no arquivo
    std::ofstream write_file;
    write_file.open(Funcionario::filePath, std::ios::out); //app significa Append, ou seja, escrita no fim do arquivo

    if(write_file.is_open()){
        // escreve o header no arquivo a partir de um vector contendo o nome das colunas
        std::vector<std::string> header = file.getHeader(); 
        write_file<<buildHeaderString(&header);

        // reescreve os dados na tabela
        for(unsigned i = 0; i<n_rows; i++){
            if(std::stoi(file[i]["id"]) == m_id){
                // reescreve o objeto moduficado com as atualizações
                write_file<<printInFile(m_id);
            }else{
                write_file<<buildRowString(&(file[i]));
            }
        }
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
        return false;
    }

    write_file.close();
    return true;
}

bool Funcionario::remove(){

    // remove a chave estrangeira em animal
    std::multimap<std::string, Animal*> animais = Animal::all();
    for (auto it=animais.begin(); it!=animais.end(); ++it){
        if(it->second->getTratador()!=NULL && it->second->getTratador()->getId() == m_id){
            Tratador *tratador = NULL;
            it->second->setTratador(tratador);
            it->second->update();
        }else if(it->second->getVeterinario()!=NULL && it->second->getVeterinario()->getId() == m_id){
            Veterinario *veterinario = NULL;
            it->second->setVeterinario(veterinario);
            it->second->update();
        }
        delete it->second;
    }

    // recupera os dados do csv
    csv::Parser file = ModelDAO<Funcionario>::readTable();
    unsigned n_rows = file.rowCount();
    
    // cria um stream de escrita no arquivo
    std::ofstream write_file;
    write_file.open(Funcionario::filePath, std::ios::out); //app significa Append, ou seja, escrita no fim do arquivo

    if(write_file.is_open()){
        // escreve o header no arquivo a partir de um vector contendo o nome das colunas
        std::vector<std::string> header = file.getHeader(); 
        write_file<<buildHeaderString(&header);

        // reescreve os dados na tabela
        for(unsigned i = 0; i<n_rows; i++){
            if(std::stoi(file[i]["id"]) != m_id){
                write_file<<buildRowString(&(file[i]));
            }
        }
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
        return false;
    }

    write_file.close();
    return true;
}



std::ostream& operator << (std::ostream& os, const Funcionario& f){
    return f.print(os);
}

void Funcionario::requestAge(std::istream& is){
    try
    {
        std::string idade_std;
        std::cout << "Idade: ";
        is>>idade_std;
        int idade = std::stoi(idade_std);

        m_idade = idade;
    }catch(std::invalid_argument& e)
    {
        std::cerr <<"Valor digitador não é inteiro!"<<std::endl;
        requestAge(is);
    }
}

std::istream & operator >> (std::istream &is, Funcionario& f)
{
    std::cout << "Nome: "<<std::endl;
    is.ignore();
    std::getline (is, f.m_nome);
    
    std::cout << "CPF: ";
    is.ignore();
    std::getline (is, f.m_cpf, '\n');

    f.requestAge(is);

    std::cout << "Tipo Sanguínio: ";
    is >> f.m_tipo_sanguineo;

    std::cout << "Fator RH: ";
    is >> f.m_fator_rh;

    std::cout << "Especialidade: ";
    is.ignore();
    std::getline (is, f.m_especialidade);

    return f.read(is);
}
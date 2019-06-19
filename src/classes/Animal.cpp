#include "../../include/Animal.h"
#include "../../include/Tratador.h"
#include "../../include/Veterinario.h"
#include "../../include/CSVparser.hpp"
#include "../../include/AnfibioExotico.h"
#include "../../include/AnfibioNativo.h"
#include "../../include/MamiferoExotico.h"
#include "../../include/MamiferoNativo.h"
#include "../../include/ReptilExotico.h"
#include "../../include/ReptilNativo.h"
#include "../../include/AveExotico.h"
#include "../../include/AveNativo.h"

std::string Animal::filePath = "./storage/animais.csv";
std::string Animal::tableName = "animais";

Animal::Animal(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo){
    m_id = id;
    m_classe = classe;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo;
    m_tamanho = tamanho;
    m_dieta = dieta;
    m_veterinario = veterinario;
    m_tratador = tratador;
    m_nome_batismo = nome_batismo;
}

Animal::~Animal(){
    if(m_tratador!=NULL){
        delete m_tratador;
    }else if(m_veterinario!=NULL){
        delete  m_veterinario;
    }
}

std::string Animal::getNomeBatismo(){
    return m_nome_batismo;
}

std::string Animal::getNomeCientifico(){
    return m_nome_cientifico;
}

char Animal::getSexo(){
    return m_sexo;
}

double Animal::getTamanho(){
    return m_tamanho;
}

std::string Animal::getDieta(){
    return m_dieta;
}

Veterinario* Animal::getVeterinario(){
    return m_veterinario;
}

Tratador* Animal::getTratador(){
    return m_tratador;
}

void Animal::setNomeBatismo(std::string nome_batismo){
    m_nome_batismo = nome_batismo;
}

int Animal::getId(){
    return m_id;
}

void Animal::setId(int id){
    m_id = id;
}

std::string Animal::getClasse(){
    return m_classe;
}

void Animal::setClasse(std::string classe){
    m_classe = classe;
}

std::multimap<std::string, Animal*> Animal::all(){

    csv::Parser file = ModelDAO<Animal>::readTable();
    std::multimap<std::string,Animal*> animals;
    int n_rows = file.rowCount();
    //std::cout<<"N_rows: "<<n_rows<<std::endl;
    //int n_columns = file.columnCount();
    //std::cout<<"N_columns: "<<n_columns<<std::endl;


    for(int i = 0; i<n_rows; i++){
        /* Estancia dinamicamente um novo funcionario */
        Animal* animal;
        animal = buildAnimalFromFile(&file[i]);

        /* faz o downcasting para tratador ou veterinario */
        animals.insert(std::pair<std::string, Animal*>(animal->m_classe, animal));  
    }

    return animals;
}

Animal* Animal::buildAnimalFromFile(csv::Row* file){
    Animal* animal = NULL;
    int id = std::stoi((*file)["id"]);
    std::string classe = (*file)["classe"];
    std::string nome = (*file)["nome"];
    std::string nome_cientifico = (*file)["nome_cientifico"];
    char sexo = (*file)["sexo"][0];
    double tamanho = std::stod((*file)["tamanho"]);
    std::string dieta = (*file)["dieta"];
    std::string nome_batismo = (*file)["nome_batismo"];
    Veterinario* veterinario = NULL;
    Tratador* tratador = NULL;
    std::string autorizacao_ibama = (*file)["autorizacao_ibama"];
    std::string uf_origem = (*file)["uf_origem"];
    std::string cidade_origem = (*file)["cidade_origem"];
    std::string pais_origem = (*file)["pais_origem"];

    if(!(*file)["veterinario_id"].empty()){
        int veterinario_id = std::stoi((*file)["veterinario_id"]);
        veterinario = (Veterinario*) Funcionario::find(veterinario_id);
    }

    if(!(*file)["tratador_id"].empty()){
        int tratador_id = std::stoi((*file)["tratador_id"]);
        tratador = (Tratador*) Funcionario::find(tratador_id);
    }
    
    /* Estancia dinamicamente um novo funcionario */

    /* faz o downcasting para tratador ou veterinario */
    
    if(classe == "Amphibia"){
        Date* ultima_muda = new Date((*file)["ultima_muda"], "/"); 
        int total_de_mudas = std::stoi((*file)["total_de_mudas"]);
        
        if(uf_origem.empty()){
            AnfibioExotico* anfibioExotico = new AnfibioExotico(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_de_mudas, ultima_muda, autorizacao_ibama, pais_origem, cidade_origem);
            anfibioExotico->setId(id);
            animal = anfibioExotico;
            return animal;
        }else{
            AnfibioNativo* anfibioNativo = new AnfibioNativo(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_de_mudas, ultima_muda, uf_origem, cidade_origem, autorizacao_ibama);
            anfibioNativo->setId(id);
            animal = anfibioNativo;
            return animal;
        }
    }else if(classe == "Mammalia"){
        std::string cor_do_pelo = (*file)["cor_do_pelo"];
        if(uf_origem.empty()){
            MamiferoExotico* mamiferoExotico = new MamiferoExotico(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor_do_pelo, pais_origem, cidade_origem, autorizacao_ibama);
            mamiferoExotico->setId(id);
            animal = mamiferoExotico;
            return animal;
        }else{
            MamiferoNativo* mamiferoNativo = new MamiferoNativo(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor_do_pelo, uf_origem, cidade_origem, autorizacao_ibama);
            mamiferoNativo->setId(id);
            animal = mamiferoNativo;
            return animal;
        }
    }else if(classe == "Reptilia"){
        bool venenoso = std::stoi((*file)["venenoso"]);
        std::string tipo_veneno = (*file)["tipo_veneno"];
        if(uf_origem.empty()){
            ReptilExotico* reptilExotico = new ReptilExotico(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, pais_origem, cidade_origem, autorizacao_ibama);
            reptilExotico->setId(id);
            animal = reptilExotico;
            return animal;
        }else{
            ReptilNativo* reptilNativo = new ReptilNativo(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, uf_origem, cidade_origem, autorizacao_ibama);
            reptilNativo->setId(id);
            animal = reptilNativo;
            return animal;
        }
    }else if(classe == "Aves"){
        double tamanho_do_bico_cm = std::stod((*file)["tamanho_do_bico_cm"]);
        double envergadura_das_asas = std::stod((*file)["envergadura_das_asas"]);
        if(uf_origem.empty()){
            AveExotico* aveExotico = new AveExotico(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_do_bico_cm, envergadura_das_asas, pais_origem, cidade_origem, autorizacao_ibama);
            aveExotico->setId(id);
            animal = aveExotico;
            return animal;
        }else{
            AveNativo* aveNativo = new AveNativo(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_do_bico_cm, envergadura_das_asas, uf_origem, cidade_origem, autorizacao_ibama);
            aveNativo->setId(id);
            animal = aveNativo;
            return animal;
        } 
    }
    return animal;
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

Animal* Animal::find(int id){
    csv::Parser file = ModelDAO<Animal>::readTable();
    int n_rows = file.rowCount();
    for (int i = 0; i < n_rows; i++)
    {
        if(id == std::stoi(file[i]["id"])){
            /* Recupera os campos do arquivo csv*/
            return buildAnimalFromFile(&file[i]);
        }
    }
    Animal* a = NULL;
    return a;
}

bool Animal::update(){
    // recupera os dados do csv
    csv::Parser file = ModelDAO<Animal>::readTable();
    unsigned n_rows = file.rowCount();
    
    // cria um stream de escrita no arquivo
    std::ofstream write_file;
    write_file.open(Animal::filePath, std::ios::out); //app significa Append, ou seja, escrita no fim do arquivo

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

bool Animal::remove(){
    // recupera os dados do csv
    csv::Parser file = ModelDAO<Animal>::readTable();
    unsigned n_rows = file.rowCount();
    
    // cria um stream de escrita no arquivo
    std::ofstream write_file;
    write_file.open(Animal::filePath, std::ios::out); //app significa Append, ou seja, escrita no fim do arquivo

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

std::multimap<std::string, Animal*> Animal::where(std::string* column, std::string* symbol, std::string* value){
    csv::Parser file = ModelDAO<Animal>::readTable();
    std::multimap<std::string,Animal*> animais;
    int n_rows = file.rowCount();
    for (int i = 0; i < n_rows; i++)
    {
        std::string val = file[i][(*column)];
        if(compare(&val, value, symbol)){
            Animal* animal = Animal::buildAnimalFromFile(&file[i]);
            /* faz o downcasting para tratador ou veterinario */
            animais.insert(std::pair<std::string, Animal*>(animal->getClasse(), animal));
        }
    }
    return animais;
}

std::multimap<std::string, Animal*> Animal::where(std::string* column, std::string* symbol, int value){
    csv::Parser file = ModelDAO<Animal>::readTable();
    std::multimap<std::string,Animal*> animais;
    int n_rows = file.rowCount();
    std::vector<std::string> header = file.getHeader();
    for (int i = 0; i < n_rows; i++)
    {
        int val = std::stoi(file[i][(*column)]);
        if(compare(val, value, symbol)){
            Animal* animal = Animal::buildAnimalFromFile(&file[i]);
            /* faz o downcasting para tratador ou veterinario */
            animais.insert(std::pair<std::string, Animal*>(animal->getClasse(), animal)); 
        }
    }
    return animais;
}

std::ostream& operator << (std::ostream& os, const Animal& a){
    return a.print(os);
}

std::istream & operator >> (std::istream &is, Animal& a)
{
    std::cout<<"Digite o nome coloquial do Animal: "<<std::endl;
    is.ignore();
    std::getline(is, a.m_nome, '\n');
    std::cout<<"Digite o nome cientifico do Animal: "<<std::endl;
    is.ignore();
    std::getline(is, a.m_nome_cientifico, '\n');
    std::cout<<"Digite o sexo do Animal: "<<std::endl;
    is>>a.m_sexo;
    std::cout<<"Digite o tamanho do Animal: "<<std::endl;
    is>>a.m_tamanho;
    std::cout<<"Digite a dieta do Animal: "<<std::endl;
    is.ignore();
    std::getline(is, a.m_dieta, '\n');
    std::cout<<"Digite o nome de batismo do Animal: "<<std::endl;
    is.ignore();
    std::getline(is, a.m_nome_batismo, '\n');
    return a.read(is);
}
#include "../../include/AnfibioExotico.h"
#include<string>

AnfibioExotico::AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo){
    m_classe = "Amphibia" ;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo ;
    m_tamanho = tamanho ;
    m_dieta = dieta ;
    m_veterinario = veterinario ;
    m_tratador = tratador ;
    m_nome_batismo = nome_batismo;
}

AnfibioExotico::AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas = 0, Date* ultima_muda = new Date(0,0,0), std::string autorizacao_ibama = NULL, std::string pais_origem = NULL, std::string cidade_origem = NULL): Anfibio(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_de_mudas, ultima_muda), AnimalExotico(pais_origem, cidade_origem, autorizacao_ibama){
    m_classe="Amphibia";
}

AnfibioExotico::AnfibioExotico(){
    m_classe="Amphibia";
}

std::string AnfibioExotico::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<";"<<";"<<";"<<";"<<std::endl;
    }
    std::string s = ss.str();
    return s;
}


std::ostream& AnfibioExotico::print(std::ostream& os) const{
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            return os<<std::endl
                     <<"============== Anfibio Exotico =============="<<std::endl
                     <<"ID                    | "<<m_id<<std::endl
                     <<"Classe                | "<<m_classe<<std::endl
                     <<"Nome                  | "<<m_nome<<std::endl
                     <<"Nome Cientifico       | "<<m_nome_cientifico<<std::endl
                     <<"Sexo                  | "<<m_sexo<<std::endl
                     <<"Tamanho               | "<<m_tamanho<<std::endl
                     <<"Dieta                 | "<<m_dieta<<std::endl
                     <<"Veterinario           | "<<""<<std::endl
                     <<"Tratador              | "<<""<<std::endl
                     <<"Nome de Batismo       | "<<m_nome_batismo<<std::endl
                     <<"Cidade de Origem      | "<<m_cidade_origem<<std::endl
                     <<"Pais de Origem        | "<<m_pais_origem<<std::endl
                     <<"Autorizacao Ibama     | "<<m_autorizacao_ibama<<std::endl
                     <<"Total de Mudas        | "<<m_total_de_mudas<<std::endl
                     <<"Última Muda           | "<<(*m_ultima_muda)<<std::endl;
        }else{
            return os<<std::endl
                     <<"============== Anfibio Exotico =============="<<std::endl
                     <<"ID                    | "<<m_id<<std::endl
                     <<"Classe                | "<<m_classe<<std::endl
                     <<"Nome                  | "<<m_nome<<std::endl
                     <<"Nome Cientifico       | "<<m_nome_cientifico<<std::endl
                     <<"Sexo                  | "<<m_sexo<<std::endl
                     <<"Tamanho               | "<<m_tamanho<<std::endl
                     <<"Dieta                 | "<<m_dieta<<std::endl
                     <<"Veterinario           | "<<m_veterinario->getNome()<<" [ "<<m_veterinario->getId()<<" ]"<<std::endl
                     <<"Tratador              | "<<""<<std::endl
                     <<"Nome de Batismo       | "<<m_nome_batismo<<std::endl
                     <<"Cidade de Origem      | "<<m_cidade_origem<<std::endl
                     <<"Pais de Origem        | "<<m_pais_origem<<std::endl
                     <<"Autorizacao Ibama     | "<<m_autorizacao_ibama<<std::endl
                     <<"Total de Mudas        | "<<m_total_de_mudas<<std::endl
                     <<"Última Muda           | "<<(*m_ultima_muda)<<std::endl;
        }
    }else if(m_veterinario == NULL){
        return os<<std::endl
                 <<"============== Anfibio Exotico =============="<<std::endl
                 <<"ID                    | "<<m_id<<std::endl
                 <<"Classe                | "<<m_classe<<std::endl
                 <<"Nome                  | "<<m_nome<<std::endl
                 <<"Nome Cientifico       | "<<m_nome_cientifico<<std::endl
                 <<"Sexo                  | "<<m_sexo<<std::endl
                 <<"Tamanho               | "<<m_tamanho<<std::endl
                 <<"Dieta                 | "<<m_dieta<<std::endl
                 <<"Veterinario           | "<<""<<std::endl
                 <<"Tratador              | "<<m_tratador->getNome()<<" [ "<<m_tratador->getId()<<" ]"<<std::endl
                 <<"Nome de Batismo       | "<<m_nome_batismo<<std::endl
                 <<"Cidade de Origem      | "<<m_cidade_origem<<std::endl
                 <<"Pais de Origem        | "<<m_pais_origem<<std::endl
                 <<"Autorizacao Ibama     | "<<m_autorizacao_ibama<<std::endl
                 <<"Total de Mudas        | "<<m_total_de_mudas<<std::endl
                 <<"Última Muda           | "<<(*m_ultima_muda)<<std::endl;
    }else{
        return os<<std::endl
                 <<"============== Anfibio Exotico =============="<<std::endl
                 <<"ID                    | "<<m_id<<std::endl
                 <<"Classe                | "<<m_classe<<std::endl
                 <<"Nome                  | "<<m_nome<<std::endl
                 <<"Nome Cientifico       | "<<m_nome_cientifico<<std::endl
                 <<"Sexo                  | "<<m_sexo<<std::endl
                 <<"Tamanho               | "<<m_tamanho<<std::endl
                 <<"Dieta                 | "<<m_dieta<<std::endl
                 <<"Veterinario           | "<<m_veterinario->getNome()<<" [ "<<m_veterinario->getId()<<" ]"<<std::endl
                 <<"Tratador              | "<<m_tratador->getNome()<<" [ "<<m_tratador->getId()<<" ]"<<std::endl
                 <<"Nome de Batismo       | "<<m_nome_batismo<<std::endl
                 <<"Cidade de Origem      | "<<m_cidade_origem<<std::endl
                 <<"Pais de Origem        | "<<m_pais_origem<<std::endl
                 <<"Autorizacao Ibama     | "<<m_autorizacao_ibama<<std::endl
                 <<"Total de Mudas        | "<<m_total_de_mudas<<std::endl
                 <<"Última Muda           | "<<(*m_ultima_muda)<<std::endl;
    }
}

std::istream& AnfibioExotico::read(std::istream& is){

    std::cout<<"Digite o total de mudas: "<<std::endl;
    is>>m_total_de_mudas;

    std::cout<<"Digite a data da ultima muda(dd/mm/yyyy): "<<std::endl;
    std::string date_stg;
    is>>date_stg;
    m_ultima_muda = new Date(date_stg, "/");

    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    is>>m_autorizacao_ibama;

    std::cout<<"Digite o pais de origem:"<<std::endl;
    is>>m_pais_origem;

    std::cout<<"Digite a cidade de origem:"<<std::endl;
    is>>m_cidade_origem;
    
    return is;
}

void AnfibioExotico::printDerivatedOption(){
    std::cout<<"10 - Total de mudas;"<<std::endl;
    std::cout<<"11 - Data da ultima muda;"<<std::endl;
    std::cout<<"12 - Autorização IBAMA;"<<std::endl;
    std::cout<<"13 - País origem;"<<std::endl;
    std::cout<<"14 - Cidade origem;"<<std::endl;
}

void AnfibioExotico::processDerivatedOption(int option){
    if(option == 10){
        std::cout<<"Digite o total de mudas: "<<std::endl;
        std::cin>>m_total_de_mudas;
    }else if(option == 11){
        std::cout<<"Digite a data da ultima muda(dd/mm/yyyy): "<<std::endl;
        std::string date_stg;
        std::cin>>date_stg;
        m_ultima_muda = new Date(date_stg, "/");
    }else if(option == 12){
        std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
        std::cin>>m_autorizacao_ibama;
    }else if(option == 13){
        std::cout<<"Digite o pais de origem:"<<std::endl;
        std::cin>>m_pais_origem;
    }else if(option == 14){
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>m_cidade_origem;
    }else{
        std::cout<<"Opção inválida"<<std::endl;
    }
}
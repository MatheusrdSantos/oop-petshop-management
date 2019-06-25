#include "../../include/Animal.h"
#include "../../include/Ave.h"
#include "../../include/AveExotico.h"

AveExotico::AveExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_id=id;
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;

    m_tamanho_do_bico_cm=tamanho_do_bico_cm;
    m_envergadura_das_asas=envergadura_das_asas;
    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;

}

AveExotico::AveExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama){
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;

    m_tamanho_do_bico_cm=tamanho_do_bico_cm;
    m_envergadura_das_asas=envergadura_das_asas;
    
    m_pais_origem=pais_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;

}

AveExotico::AveExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama): Ave(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tamanho_do_bico_cm, envergadura_das_asas), AnimalExotico(pais_origem, cidade_origem, autorizacao_ibama){
    m_classe="Aves";
}

AveExotico::AveExotico(){
    m_classe="Aves";
}


std::string AveExotico::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<";"<<";;;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<";"<<";;;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<";"<<";;;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<";"<<";;;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<";"<<";;;"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;
    }
    std::string s = ss.str();
    return s;
}

std::ostream& AveExotico::print(std::ostream& os) const{
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            return os<<std::endl
                    <<"================ Ave Exotica ================"<<std::endl
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
                    <<"Tamanho do Bico (cm)  | "<<m_tamanho_do_bico_cm<<std::endl
                    <<"Envergadura das Asas  | "<<m_envergadura_das_asas<<std::endl;
        }else{
            return os<<std::endl
                    <<"================ Ave Exotica ================"<<std::endl
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
                    <<"Tamanho do Bico (cm)  | "<<m_tamanho_do_bico_cm<<std::endl
                    <<"Envergadura das Asas  | "<<m_envergadura_das_asas<<std::endl;
        }
    }else if(m_veterinario == NULL){
        return os<<std::endl
                 <<"================ Ave Exotica ================"<<std::endl
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
                 <<"Tamanho do Bico (cm)  | "<<m_tamanho_do_bico_cm<<std::endl
                 <<"Envergadura das Asas  | "<<m_envergadura_das_asas<<std::endl;
    }else{
        return os<<std::endl
                 <<"================ Ave Exotica ================"<<std::endl
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
                 <<"Tamanho do Bico (cm)  | "<<m_tamanho_do_bico_cm<<std::endl
                 <<"Envergadura das Asas  | "<<m_envergadura_das_asas<<std::endl;
    }
}

std::istream& AveExotico::read(std::istream& is){

    std::cout<<"Digite o tamanho do bico da ave (em cm): "<<std::endl;
    is>>m_tamanho_do_bico_cm;

    std::cout<<"Digite a envergadura das asas: "<<std::endl;
    is>>m_envergadura_das_asas;

    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    is>>m_autorizacao_ibama;

    std::cout<<"Digite o pais de origem:"<<std::endl;
    is>>m_pais_origem;

    std::cout<<"Digite a cidade de origem:"<<std::endl;
    is>>m_cidade_origem;
    
    return is;
}

void AveExotico::printDerivatedOption(){
    std::cout<<"9 - Tamanho do bico da ave (cm);"<<std::endl;
    std::cout<<"10 - Envergadura das asas;"<<std::endl;
    std::cout<<"11 - Autorização IBAMA;"<<std::endl;
    std::cout<<"12 - País origem;"<<std::endl;
    std::cout<<"13 - Cidade origem;"<<std::endl;
}
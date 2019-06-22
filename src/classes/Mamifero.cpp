#include "../../include/Mamifero.h"
#include<string>

Mamifero::Mamifero(){
    m_classe="Mammalia";
    m_cor_do_pelo="";
}

Mamifero::Mamifero(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo){
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
    m_cor_do_pelo=cor_do_pelo;
}

Mamifero::Mamifero(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo){
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;
    m_cor_do_pelo=cor_do_pelo;
}

Mamifero::Mamifero(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo): Animal(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo){
    m_cor_do_pelo=cor_do_pelo;
}

std::string Mamifero::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;

    }
    std::string s = ss.str();
    return s;
}

std::ostream& Mamifero::print(std::ostream& os) const{
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            return os<<std::endl
                 <<"============== Mamifero Nativo =============="<<std::endl
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
                 <<"Cor do Pelo           | "<<m_cor_do_pelo<<std::endl;
        }else{
            return os<<std::endl
                 <<"============== Mamifero Nativo =============="<<std::endl
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
                 <<"Cor do Pelo           | "<<m_cor_do_pelo<<std::endl;
        }
    }else if(m_veterinario == NULL){
            return os<<std::endl
                 <<"============== Mamifero Nativo =============="<<std::endl
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
                 <<"Cor do Pelo           | "<<m_cor_do_pelo<<std::endl;
    }else{
        return os<<std::endl
                 <<"============== Mamifero Nativo =============="<<std::endl
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
                 <<"Cor do Pelo           | "<<m_cor_do_pelo<<std::endl;
    }        
}

std::istream& Mamifero::read(std::istream& is){

    std::cout<<"Digite a cor do pelo: "<<std::endl;
    is>>m_cor_do_pelo;
    
    return is;
}
#include "../../include/Reptil.h"
#include <string>

Reptil::Reptil(){
    m_classe="Reptilia";
}

Reptil::Reptil(int id,std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno){
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
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;
}

Reptil::Reptil(std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno){
    m_classe=classe;
    m_nome=nome;
    m_nome_cientifico=nome_cientifico;
    m_sexo=sexo;
    m_tamanho=tamanho;
    m_dieta=dieta;
    m_veterinario=veterinario;
    m_tratador=tratador;
    m_nome_batismo=nome_batismo;
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;
}

Reptil::Reptil(std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno): Animal(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo){
    m_classe="Reptilia";
    m_venenoso=venenoso;
    m_tipo_veneno=tipo_veneno;
}

std::string Reptil::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<""<<";"<<";"<<";"<<";"<<""<<";"<<""<<";"<<""<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<""<<";"<<""<<std::endl;
    }
    std::string s = ss.str();
    return s;
}

std::ostream& Reptil::print(std::ostream& os) const{
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            return os<<std::endl
                     <<"============== Reptil Doméstico ==========="<<std::endl
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
                     <<"Venenoso              | "<<m_venenoso<<std::endl
                     <<"Tipo de veneno        | "<<m_tipo_veneno<<std::endl;
        }else{
            return os<<std::endl
                     <<"============== Reptil Doméstico ==========="<<std::endl
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
                     <<"Venenoso              | "<<m_venenoso<<std::endl
                     <<"Tipo de veneno        | "<<m_tipo_veneno<<std::endl;
        }
    }else if(m_veterinario == NULL){
        return os<<std::endl
                 <<"============== Reptil Doméstico ==========="<<std::endl
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
                 <<"Venenoso              | "<<m_venenoso<<std::endl
                 <<"Tipo de veneno        | "<<m_tipo_veneno<<std::endl;
    }else{
        return os<<std::endl
                 <<"============== Reptil Doméstico ==========="<<std::endl
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
                 <<"Venenoso              | "<<m_venenoso<<std::endl
                 <<"Tipo de veneno        | "<<m_tipo_veneno<<std::endl;
    }
}

std::istream& Reptil::read(std::istream& is){

    std::cout<<"Digite se o animal é venenoso (0/1): "<<std::endl;
    is>>m_venenoso;
    std::cout<<"Digite o tipo do veneno: "<<std::endl;
    is>>m_tipo_veneno;
    
    return is;
}

void Reptil::printDerivatedOption(){
    std::cout<<"9 - Venenoso?;"<<std::endl;
    std::cout<<"10 - Tipo do veneno;"<<std::endl;
}
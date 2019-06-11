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

AnfibioExotico::AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas = 0, Date* ultima_muda = new Date(0,0,0), std::string autorizacao_ibama = NULL, std::string pais_origem = NULL, std::string cidade_origem = NULL){
    m_classe = "Amphibia" ;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo ;
    m_tamanho = tamanho ;
    m_dieta = dieta ;
    m_veterinario = veterinario ;
    m_tratador = tratador ;
    m_nome_batismo = nome_batismo;
    m_total_de_mudas = total_de_mudas;
    m_ultima_muda = ultima_muda;
    m_autorizacao_ibama = autorizacao_ibama;
    m_pais_origem = pais_origem;
    m_cidade_origem = cidade_origem;
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
            return os<<
            "id =>"<<m_id<<std::endl<< 
            "Classe =>"<<m_classe<<std::endl<<
            "Nome =>"<<m_nome<<std::endl<<
            "Nome cientifico =>"<<m_nome_cientifico<<std::endl<<
            "Sexo =>"<<m_sexo<<std::endl<<
            "Tamanho =>"<<m_tamanho<<std::endl<<
            "Dieta =>"<<m_dieta<<std::endl<<
            "Veterinario =>"<<""<<std::endl<<
            "Tratador =>"<<""<<std::endl<<
            "Nome de batismo =>"<<m_nome_batismo<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            std::endl;
        }else{
            return os<<
            "id =>"<<m_id<<std::endl<< 
            "Classe =>"<<m_classe<<std::endl<<
            "Nome =>"<<m_nome<<std::endl<<
            "Nome cientifico =>"<<m_nome_cientifico<<std::endl<<
            "Sexo =>"<<m_sexo<<std::endl<<
            "Tamanho =>"<<m_tamanho<<std::endl<<
            "Dieta =>"<<m_dieta<<std::endl<<
            "Veterinario =>"<<m_veterinario->getNome()<<" / "<<m_veterinario->getId()<<std::endl<<
            "Tratador =>"<<""<<std::endl<<
            "Nome de batismo =>"<<m_nome_batismo<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            return os<<
            "id =>"<<m_id<<std::endl<< 
            "Classe =>"<<m_classe<<std::endl<<
            "Nome =>"<<m_nome<<std::endl<<
            "Nome cientifico =>"<<m_nome_cientifico<<std::endl<<
            "Sexo =>"<<m_sexo<<std::endl<<
            "Tamanho =>"<<m_tamanho<<std::endl<<
            "Dieta =>"<<m_dieta<<std::endl<<
            "Veterinario =>"<<""<<std::endl<<
            "Tratador =>"<<""<<std::endl<<
            "Nome de batismo =>"<<m_nome_batismo<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            std::endl;
        }else{
            return os<<
            "id =>"<<m_id<<std::endl<< 
            "Classe =>"<<m_classe<<std::endl<<
            "Nome =>"<<m_nome<<std::endl<<
            "Nome cientifico =>"<<m_nome_cientifico<<std::endl<<
            "Sexo =>"<<m_sexo<<std::endl<<
            "Tamanho =>"<<m_tamanho<<std::endl<<
            "Dieta =>"<<m_dieta<<std::endl<<
            "Veterinario =>"<<""<<std::endl<<
            "Tratador =>"<<m_tratador->getNome()<<" / "<<m_tratador->getId()<<std::endl<<
            "Nome de batismo =>"<<m_nome_batismo<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            std::endl;
        }
    }else{
        return os<<
            "id =>"<<m_id<<std::endl<< 
            "Classe =>"<<m_classe<<std::endl<<
            "Nome =>"<<m_nome<<std::endl<<
            "Nome cientifico =>"<<m_nome_cientifico<<std::endl<<
            "Sexo =>"<<m_sexo<<std::endl<<
            "Tamanho =>"<<m_tamanho<<std::endl<<
            "Dieta =>"<<m_dieta<<std::endl<<
            "Veterinario =>"<<m_veterinario->getNome()<<" / "<<m_veterinario->getId()<<std::endl<<
            "Tratador =>"<<m_tratador->getNome()<<" / "<<m_tratador->getId()<<std::endl<<
            "Nome de batismo =>"<<m_nome_batismo<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            std::endl;
    }        
}
/*
generic print:
ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<m_pais_origem<<";"<<m_autorizacao_ibama<<";"<<m_total_de_mudas<<";"<<m_ultima_muda->day()<<"/"<<m_ultima_muda->month()<<"/"<<m_ultima_muda->year()<<";"<<m_cor_do_pelo<<";"<<m_venenoso<<";"<<m_tipo_veneno<<";"<<m_tamanho_do_bico_cm<<";"<<m_envergadura_das_asas<<std::endl;


*/

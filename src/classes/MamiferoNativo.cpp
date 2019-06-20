#include "../../include/MamiferoNativo.h"

MamiferoNativo::MamiferoNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama){
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
    

    m_uf_origem=uf_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}

MamiferoNativo::MamiferoNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama){
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
    

    m_uf_origem=uf_origem;
    m_cidade_origem=cidade_origem;
    m_autorizacao_ibama=autorizacao_ibama;
}

MamiferoNativo::MamiferoNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama): Mamifero(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor_do_pelo), AnimalNativo(uf_origem, cidade_origem, autorizacao_ibama){
    m_classe="Mammalia";
}

MamiferoNativo::MamiferoNativo(){

}

std::string MamiferoNativo::printInFile(int id){
    std::stringstream ss;
    if(m_tratador == NULL){
        if(m_veterinario==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<""<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<""<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<""<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }
    }else if(m_veterinario == NULL){
        if(m_tratador==NULL){
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<""<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<""<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }else{
            ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<""<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<""<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;
        }
    }else{
        ss<<id<<";"<<m_classe<<";"<<m_nome<<";"<<m_nome_cientifico<<";"<<m_sexo<<";"<<m_tamanho<<";"<<m_dieta<<";"<<m_veterinario->getId()<<";"<<m_tratador->getId()<<";"<<m_nome_batismo<<";"<<m_uf_origem<<";"<<m_cidade_origem<<";"<<""<<";"<<m_autorizacao_ibama<<";"<<""<<";"<<""<<";"<<m_cor_do_pelo<<";"<<""<<";"<<""<<";"<<""<<";"<<""<<std::endl;


    }
    std::string s = ss.str();
    return s;
}

std::ostream& MamiferoNativo::print(std::ostream& os) const{
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
            std::endl;
    }        
}

std::istream& MamiferoNativo::read(std::istream& is){

    std::cout<<"Digite a cor do pelo: "<<std::endl;
    std::cin>>m_cor_do_pelo;
    
    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    is>>m_autorizacao_ibama;
    
    std::cout<<"Digite a uf de origem:"<<std::endl;
    is>>m_uf_origem;
    
    std::cout<<"Digite a cidade de origem:"<<std::endl;
    is>>m_cidade_origem;
    
    return is;
}

/*
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
            "Uf Origem =>"<<m_uf_origem<<std::endl<<
            "Cidade de origem =>"<<m_cidade_origem<<std::endl<<
            "Pais origem =>"<<m_pais_origem<<std::endl<<
            "Autorizacao Ibama =>"<<m_autorizacao_ibama<<std::endl<<
            "Total de mudas =>"<<m_total_de_mudas<<std::endl<<
            "Última muda =>"<<m_ultima_muda<<std::endl<<
            "Cor do pelo =>"<<m_cor_do_pelo<<std::endl<<
            "Venenoso =>"<<m_venenoso<<std::endl<<
            "Tipo de veneno =>"<<m_tipo_veneno<<std::endl<<
            "Tamanho do bico em cm =>"<<m_tamanho_do_bico_cm<<std::endl<<
            "Envergadura das Asas =>"<<m_envergadura_das_asas<<
            std::endl;

*/
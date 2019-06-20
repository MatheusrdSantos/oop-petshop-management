#include "../../include/Anfibio.h"

Anfibio::Anfibio(){
    m_total_de_mudas = 0;
    m_ultima_muda = new Date(0, 0, 0);
}

Anfibio::Anfibio(int total_de_mudas, Date *ultima_muda){
    m_total_de_mudas = total_de_mudas;
    m_ultima_muda = ultima_muda;
}

Anfibio::Anfibio(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo,int total_de_mudas, Date* ultima_muda):Animal(nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo){
    m_nome = nome;
    m_nome_cientifico = nome_cientifico;
    m_sexo = sexo;
    m_tamanho = tamanho;
    m_dieta = dieta;
    m_veterinario = veterinario;
    m_tratador = tratador;
    m_nome_batismo = nome_batismo;
    m_total_de_mudas = total_de_mudas;
    m_ultima_muda = ultima_muda;
}
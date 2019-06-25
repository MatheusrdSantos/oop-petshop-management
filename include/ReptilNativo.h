#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Reptil.h"

class ReptilNativo : public Reptil, public AnimalNativo{
    private:
        std::ostream& print(std::ostream&) const;
        std::istream& read(std::istream&);
    protected:
        /**
         * @brief Define a forma como o texto do Réptil Exótico será armazenado no banco.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */ 
        std::string printInFile(int id);
    public:
        void printDerivatedOption();
        /**
         * @brief Constrói um novo Réptil Nativo
         * 
         */
        ReptilNativo();

        /**
         * @brief Constrói um novo Réptil Nativo
         * 
         * @param id 
         * @param classe 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param venenoso 
         * @param tipo_veneno 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        ReptilNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo Réptil Nativo
         * 
         * @param classe 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param venenoso 
         * @param tipo_veneno 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        ReptilNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo Réptil Nativo
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param venenoso 
         * @param tipo_veneno 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        ReptilNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, bool venenoso, std::string tipo_veneno, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Destrói o Reptil Nativo
         * 
         */
        ~ReptilNativo(){};


};

#endif
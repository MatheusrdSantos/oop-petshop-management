#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Anfibio.h"

class AnfibioNativo : public Anfibio, public AnimalNativo{
    private:
    
        std::ostream& print(std::ostream& os) const;
        std::istream& read(std::istream&);
    protected:
        /**
         * @brief Define a forma como o texto do Anfíbio Nativo será armazenado no banco.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);


    public:
        void printDerivatedOption(); 
        /**
         * @brief Constrói um novo objeto do tipo Anfíbio Nativo.
         * 
         */
        AnfibioNativo();

        /**
         * @brief Constrói um novo objeto do tipo Anfíbio Nativo.
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
         * @param total_de_mudas 
         * @param ultima_muda 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AnfibioNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas, Date* ultima_muda, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Constrói um novo objeto do tipo Anfíbio Nativo.
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
         * @param total_de_mudas 
         * @param ultima_muda 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AnfibioNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas, Date* ultima_muda, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Construct a new Anfibio Nativo object
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param total_de_mudas 
         * @param ultima_muda 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AnfibioNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, int total_de_mudas, Date* ultima_muda, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Destroy the Anfibio Nativo object
         * 
         */
        ~AnfibioNativo(){};

};

#endif
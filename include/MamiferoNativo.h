#ifndef _MAMIFERO_NATIVO_H_
#define _MAMIFERO_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Mamifero.h"

class MamiferoNativo : public Mamifero, public AnimalNativo{
    private:
        std::ostream& print(std::ostream& os) const;
        std::istream& read(std::istream&);
    protected:
    
        /**
         * @brief Define a forma como o texto do Mamifero Nativo será armazenado no banco. 
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);
    public:
        /**
         * @brief Constrói um novo objeto do tipo Mamífero Nativo
         * 
         */
        MamiferoNativo();

        /**
         * @brief Destroi um objeto do tipo Animal Nativo.
         * 
         */
        ~MamiferoNativo(){};

        /**
         * @brief Constrói um novo objeto do tipo Mamífero Nativo
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
         * @param cor_do_pelo 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo objeto do tipo Mamífero Nativo
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
         * @param cor_do_pelo 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo objeto do tipo Mamífero Nativo
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param cor_do_pelo 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

};

#endif
#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <iostream>
#include "AnimalExotico.h"
#include "Mamifero.h"

class MamiferoExotico : public Mamifero, public AnimalExotico{
    private:
        std::ostream& print(std::ostream& os) const;
        std::istream& read(std::istream&);
    protected:

        /**
         * @brief Define a forma como o texto do Mamifero Exotico será armazenado no banco. 
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);
    public:
        void printDerivatedOption();
        void processDerivatedOption(int option);
        /**
         * @brief Constrói um novo objeto do tipo Mamífero Exotico
         * 
         */
        MamiferoExotico();

        /**
         * @brief Destroi um objeto do tipo Animal Exotico.
         * 
         */
        ~MamiferoExotico(){};
        
        /**
         * @brief Constrói um novo objeto do tipo Mamífero Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Constrói um novo objeto do tipo Mamífero Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Constrói um novo objeto do tipo Mamífero Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        MamiferoExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);

};

#endif
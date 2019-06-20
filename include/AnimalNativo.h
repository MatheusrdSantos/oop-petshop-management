#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <iostream>
#include <string>
#include "AnimalSilvestre.h"

class AnimalNativo : public AnimalSilvestre{
    private:
        
    protected:
        std::string m_uf_origem; /**< União Federativa da qual o animal foi coletado. */
        std::string m_cidade_origem; /**< Cidade da qual o animal foi coletado. */
        
    public:
        /**
         * @brief Constrói um novo objeto do tipo Animal Nativo 
         * 
         */
        AnimalNativo();

        /**
         * @brief Constrói um novo objeto do tipo Animal Nativo 
         * 
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama
         */
        AnimalNativo(std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Destrói o Animal Nativo 
         * 
         */
        ~AnimalNativo(){};

        /**
         * @brief Retorna a Uf de Origem 
         * 
         * @return std::string 
         */
        std::string getUfOrigem();

        /**
         * @brief Define a Uf de Origem 
         * 
         * @param uf_origem 
         */
        void setUfOrigem(std::string uf_origem);

        /**
         * @brief Retorna a Cidade de Origem 
         * 
         * @return std::string 
         */
        std::string getCidadeOrigem();

        /**
         * @brief Define a Cidade de Origem 
         * 
         * @param cidade_origem 
         */
        void setCidadeOrigem(std::string cidade_origem);
};

#endif
#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <iostream>
#include <string>
#include "AnimalSilvestre.h"

class AnimalExotico : public AnimalSilvestre{
    private:

    protected:
        std::string m_pais_origem; /**< Define o país de origem do Animal Exótico. */
        std::string m_cidade_origem; /**< Define a cidade do país de origem do Animal Exótico da qual ele foi originado. */
        
    public:

        /**
         * @brief Constrói um novo Animal Exótico.
         * 
         */
        AnimalExotico(){};

        /**
         * @brief Destrói um Animal Exótico.
         * 
         */
        ~AnimalExotico(){};

        /**
         * @brief Retorna o Pais de Origem do Animal Exótico.
         * 
         * @return std::string 
         */
        std::string getPaisOrigem();

        /**
         * @brief Define o Pais de Origem do Animal Exótico.
         * 
         * @param pais_origem 
         */
        void setPaisOrigem(std::string pais_origem);

        /**
         * @brief Retorna a Cidade de Origem do Animal Exótico.
         * 
         * @return std::string 
         */
        std::string getCidadeOrigem();

        /**
         * @brief Define a Cidade de Origem do Animal Exótico.
         * 
         * @param cidade_origem 
         */
        void setCidadeOrigem(std::string cidade_origem);

};

#endif
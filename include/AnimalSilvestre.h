#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <iostream>
#include <string>

class AnimalSilvestre{
    private:

    protected:
        std::string m_autorizacao_ibama; /**< Define a autorização do IBAMA para o porte do Animal Silvestre. Ex: 578812184 */
        
    public:

        /**
         * @brief Constrói um novo objeto do tipo Animal Silvestre
         * 
         */
        AnimalSilvestre(){};

        /**
         * @brief Destrói um objeto do tipo Animal Silvestre.
         * 
         */
        ~AnimalSilvestre(){};

        /**
         * @brief Retorna a Autorizacao do Ibama
         * 
         * @return std::string 
         */
        std::string getAutorizacaoIbama();

        /**
         * @brief Define uma nova Autorizacao do Ibama para o Animal Silvestre.
         * 
         * @param autorizacao_ibama 
         */
        void setAutorizacaoIbama(std::string autorizacao_ibama);

};

#endif
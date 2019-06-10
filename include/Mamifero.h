#ifndef _MAMIFERO_H
#define _MAMIFERO_H

#include <iostream>
#include <string>
#include "Animal.h"

class Mamifero : public Animal{
    private:

    protected:
        std::string m_cor_do_pelo; /*< Define a cor do pelo de um mamifero*/


        /**
         * @brief Define a forma como o texto do Mamifero será armazenado no banco. Será implementado pelas classes derivadas.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        virtual std::string printInFile(int id) = 0;
    public:
        /**     
         * @brief Constrói um novo objeto do tipo Mamífero
         * 
         */
        Mamifero();

        /**
         * @brief Destrói o Mamífero
         * 
         */
        ~Mamifero(){};

        /**
         * @brief Constrói um novo objeto do tipo Mamífero
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
         */
        Mamifero(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);
        
        /**
         * @brief Constrói um novo objeto do tipo Mamífero
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
         */
        Mamifero(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);

        /**
         * @brief Constrói um novo objeto do tipo Mamífero
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
         */
        Mamifero(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, std::string cor_do_pelo);

        /**
         * @brief Retorna a Cor Do Pelo do Mamifero
         * 
         * @return std::string 
         */
        std::string getCorDoPelo();

        /**
         * @brief Set the Cor Do Pelo do Mamifero
         * 
         * @param cor_do_pelo 
         */
        void setCorDoPelo(std::string cor_do_pelo);

    
};

#endif
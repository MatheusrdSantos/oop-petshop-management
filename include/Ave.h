#ifndef _AVE_H
#define _AVE_H

#include <iostream>
#include <string>
#include "Animal.h"

class Ave : public Animal{
    private:

    protected:
        double m_tamanho_do_bico_cm; /*< Define o tamanho do bico em cm da Ave. */
        double m_envergadura_das_asas; /*< Define a envergadura das asas da Ave. */

        /**
         * @brief Define a forma como o texto da Ave será armazenado no banco.
         * 
         * @param id 
         * @return std::string 
         */
        virtual std::string printInFile(int id) = 0;
    public:
        /**
         * @brief Constrói um novo objeto do tipo Ave
         * 
         */
        Ave();

        /**
         * @brief Constrói um novo objeto do tipo Ave
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
         * @param tamanho_do_bico_cm 
         * @param envergadura_das_asas 
         */
        Ave(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas);

        /**
         * @brief Constrói um novo objeto do tipo Ave
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
         * @param tamanho_do_bico_cm 
         * @param envergadura_das_asas 
         */
        Ave(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas);

        /**
         * @brief Constrói um novo objeto do tipo Ave
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param tamanho_do_bico_cm 
         * @param envergadura_das_asas 
         */
        Ave(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas);

        /**
         * @brief Destrói o objeto do tipo Ave
         * 
         */
        ~Ave(){};

};

#endif
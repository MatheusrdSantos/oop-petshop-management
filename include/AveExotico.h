#ifndef _AVE_EXOTICO_H_
#define _AVE_EXOTICO_H_

#include <iostream>
#include "Animal.h"
#include "AnimalExotico.h"
#include "Ave.h"

class AveExotico : public Ave, public AnimalExotico{
    private:
        std::ostream& print(std::ostream&) const;
        std::istream& read(std::istream&);
    protected:
        /**
         * @brief Define a forma como o texto da Ave Exótica será armazenado no banco.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);
        
    public:
        void printDerivatedOption();
        void processDerivatedOption(int option); 
        /**
         * @brief Constrói um novo objeto do tipo Ave Exotico
         * 
         */
        AveExotico();

        /**
         * @brief Constrói um novo objeto do tipo Ave Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveExotico(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo objeto do tipo Ave Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveExotico(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);

        /**
         * @brief Constrói um novo objeto do tipo Ave Exotico
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
         * @param pais_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string pais_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Destrói a Ave Exotico
         * 
         */
        ~AveExotico(){};


};

#endif
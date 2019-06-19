#ifndef _AVE_NATIVO_H_
#define _AVE_NATIVO_H_

#include <iostream>
#include "AnimalNativo.h"
#include "Ave.h"

class AveNativo : public Ave, public AnimalNativo{
    private:
        std::ostream& print(std::ostream&) const;
        std::istream& read(std::istream&);
    protected:
        /**
         * @brief Define a forma como o texto da Ave Nativa será armazenado no banco.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);
    public:

        /**
         * @brief Constrói um novo objeto do tipo Ave Nativo 
         * 
         */
        AveNativo();

        /**
         * @brief Destrói a Ave Nativa 
         * 
         */
        ~AveNativo(){};

        /**
         * @brief Constrói um novo objeto do tipo Ave Nativo 
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
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveNativo(int id, std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Constrói um novo objeto do tipo Ave Nativo 
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
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveNativo(std::string classe, std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);
        
        /**
         * @brief Constrói um novo objeto do tipo Ave Nativo 
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
         * @param uf_origem 
         * @param cidade_origem 
         * @param autorizacao_ibama 
         */
        AveNativo(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo, double tamanho_do_bico_cm, double envergadura_das_asas, std::string uf_origem, std::string cidade_origem, std::string autorizacao_ibama);

};

#endif
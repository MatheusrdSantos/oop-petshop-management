#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <iostream>
#include <string>
#include "AnimalExotico.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "Anfibio.h"

class AnfibioExotico : public Anfibio, public AnimalExotico{
    private:
        std::ostream& print(std::ostream& os) const;
        std::istream& read(std::istream&);
    protected:
        /**
         * @brief Define a forma como o texto do Anfíbio Exótico será armazenado no banco.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        std::string printInFile(int id);
        
    public:
        void printDerivatedOption(); 
        /**
         * @brief Constrói um novo Anfíbio Exótico.
         * 
         */
        AnfibioExotico();
        
        /**
         * @brief Constrói um novo Anfíbio Exótico.
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         */
        AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo);
        
        /**
         * @brief Constrói um novo Anfíbio Exótico.
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
         * @param autorizacao_ibama 
         * @param pais_origem 
         * @param cidade_origem 
         */
        AnfibioExotico(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo,int total_de_mudas, Date* ultima_muda, std::string autorizacao_ibama, std::string pais_origem, std::string cidade_origem);

        
        /**
         * @brief Destrói o objeto do tipo Anfíbio exotico.
         * 
         */
        ~AnfibioExotico(){};
        
};

#endif
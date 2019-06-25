#ifndef _REPTIL_H
#define _REPTIL_H

#include <iostream>
#include <string>
#include "Animal.h"

class Reptil : public Animal{
    private:
        virtual std::ostream& print(std::ostream&) const;
        virtual std::istream& read(std::istream&);
    protected:
        bool m_venenoso; /*< Define se um Réptil é ou não venenoso. True para sim False para não.*/
        std::string m_tipo_veneno; /*< Define o tipo de veneno para cada Réptil.*/

        /**
         * @brief Define a forma como o texto do Réptil será armazenado no banco. Será implementado pelas classes derivadas.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        virtual std::string printInFile(int id);
    public:
        void printDerivatedOption(); 
        /**
         * @brief Constrói um novo objeto do tipo Réptil
         * 
         */
        Reptil();
        
        /**
         * @brief Constrói um novo objeto do tipo Réptil
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
         * @param venenoso 
         * @param tipo_veneno 
         */
        Reptil(int id,std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        /**
         * @brief Constrói um novo objeto do tipo Réptil
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
         * @param venenoso 
         * @param tipo_veneno 
         */
        Reptil(std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        /**
         * @brief Constrói um novo objeto do tipo Réptil
         * 
         * @param nome 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         * @param venenoso 
         * @param tipo_veneno 
         */
        Reptil(std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        /**
         * @brief Destrói o Réptil
         * 
         */
        ~Reptil(){};

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isVenenoso();

        /**
         * @brief Define se o réptil é ou não venenoso
         * 
         * @param venenoso 
         */
        void setVenenoso(bool venenoso);

        /**
         * @brief Retorna o Tipo de Veneno do réptil
         * 
         * @return std::string 
         */
        std::string getTipoVeneno();

        /**
         * @brief Define o tipo de veneno do réptil.
         * 
         * @param tipo_veneno 
         */
        void setTipoVeneno(std::string tipo_veneno);

};

#endif
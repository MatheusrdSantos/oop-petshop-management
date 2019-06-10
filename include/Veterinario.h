/* 
Class: Veterinario
Author: Arnaldo Barbosa    
*/
#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include "Funcionario.h"
#include <iostream>
#include <string>
#include <fstream>

class Veterinario : public Funcionario{
    protected:
        /**
         * @brief Define a forma como o texto do Veterinário será armazenado no banco.
         * 
         * @param id 
         * @return std::string 
         */
        std::string printInFile(int id);
    private:
        std::string m_cnmv; /*< Define o CNMV do veterinario.*/
    
    public:
        /**
         * @brief Constrói um novo objeto do tipo Veterinário.
         * 
         */
        Veterinario();

        /**
         * @brief Constrói um novo objeto do tipo Veterinário.
         * 
         * @param id 
         * @param nome 
         * @param cpf 
         * @param idade 
         * @param tipo_sanguineo 
         * @param fator_rh 
         * @param especialidade 
         * @param cnmv 
         */
        Veterinario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv);
        
        /**
         * @brief Constrói um novo objeto do tipo Veterinário.
         * 
         * @param nome 
         * @param cpf 
         * @param idade 
         * @param tipo_sanguineo 
         * @param fator_rh 
         * @param especialidade 
         * @param cnmv 
         */
        Veterinario(std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade, std::string cnmv);
        
        /**
         * @brief Destrói o Veterinário.
         * 
         */
        ~Veterinario(){};
        
        /**
         * @brief Retorna o código Cnmv do veterinário.
         * 
         * @return std::string 
         */
        std::string getCnmv();
        
        /**
         * @brief Define o código Cnmv do veterinário.
         * 
         * @param cnmv 
         */
        void setCnmv(std::string cnmv);

};
    
#endif
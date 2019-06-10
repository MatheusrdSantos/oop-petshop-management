/* 
Class: Funcionario
Author: Arnaldo Barbosa    
*/
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include<iostream>
#include<string>
#include <map>
#include "ModelDAO.h"
#include "utils.h"
#include "CSVparser.hpp"

class Funcionario : public ModelDAO<Funcionario>{
    private:

        /**
         * @brief Constrói um funcionário passada uma linha do CSV por parametro.
         * 
         * @param file 
         * @return Funcionario* 
         */
        static Funcionario* buildFuncionarioFromFile(csv::Row* file);
    protected:
        int m_id; /*< id do Funcionário. O id é único. */
        std::string m_nome; /*< Nome do Funcionário. */
        std::string m_cpf; /*< CPF do Funcionário.*/
        short m_idade; /*< Idade do Funcionário. */
        short m_tipo_sanguineo; /*< Tipo sanguíneo do Funcionário.*/
        char m_fator_rh; /*< Fato RH do sangue do Funcionário.*/
        std::string m_especialidade; /*< Especialidade do Funcionário.*/

        /**
         * @brief Define a forma como o texto do funcionário será armazenada no banco, se altera dependendo da classe derivada.
         * 
         * @param id 
         * @return std::string 
         */
        virtual std::string printInFile(int id) = 0;
    public:

        /**
         * @brief Constrói um novo objeto do tipo Funcionario
         * 
         */
        Funcionario(){};

        /**
         * @brief Constrói um novo objeto do tipo Funcionario
         * 
         * @param id 
         * @param nome 
         * @param cpf 
         * @param idade 
         * @param tipo_sanguineo 
         * @param fator_rh 
         * @param especialidade 
         */
        Funcionario(int id, std::string nome, std::string cpf, short idade, short tipo_sanguineo, char fator_rh, std::string especialidade);
        
        /**
         * @brief Destrói o Funcionario
         * 
         */
        ~Funcionario(){};


        static std::string filePath; /**< Define o caminho para a tabela que armazenará os Animais. */
        static std::string tableName; /**< Define o nome para a tabela que armazenará os Animais, tal valor é utilizado para os ids de autoincremento. */


        /**
         * @brief Retorna todos os funcionários armazenados no banco.
         * 
         * @return std::multimap<std::string,Funcionario*> 
         */
        static std::multimap<std::string,Funcionario*> all();

        /**
         * @brief Retorna o funcionário do id passsado por parametro.
         * 
         * @param id 
         * @return Funcionario* 
         */
        static Funcionario* find(int id);

        /**
         * @brief Faz uma query para a seleção de um ou mais funcionários passado uma coluna, um método de comparação e um valor. Ex: idade == 34. Retorna um multimap cuja key é Tratador ou Veterinário e o valor o Funcionário.
         * 
         * @param column 
         * @param separator 
         * @param value 
         * @return std::multimap<std::string, Funcionario*> 
         */
        static std::multimap<std::string, Funcionario*> where(std::string* column, std::string* separator, std::string* value);

        /**
         * @brief Faz uma query para a seleção de um ou mais funcionários passado uma coluna, um método de comparação e um valor inteiro. Ex: idade == 34. Retorna um multimap cuja key é Tratador ou Veterinário e o valor o Funcionário.
         * 
         * @param column 
         * @param separator 
         * @param value 
         * @return std::multimap<std::string, Funcionario*> 
         */
        static std::multimap<std::string, Funcionario*> where(std::string* column, std::string* separator, int value);
        
        /**
         * @brief Retorna o Id do Funcionário
         * 
         * @return int 
         */
        int getId();

        /**
         * @brief Retorna o Nome do Funcionário
         * 
         * @return std::string 
         */
        std::string getNome();

        /**
         * @brief Retorna o Cpf do Funcionário
         * 
         * @return std::string 
         */
        std::string getCpf();

        /**
         * @brief Retorna a Idade do Funcionário
         * 
         * @return short 
         */
        short getIdade();

        /**
         * @brief Retorna o Tipo Sanguineo do Funcionário
         * 
         * @return short 
         */
        short getTipoSanguineo();

        /**
         * @brief Retorna o Fator Rh do Funcionário 
         * 
         * @return char 
         */
        char getFatorRh();

        /**
         * @brief Retorna a Especialidade do Funcionário
         * 
         * @return std::string 
         */
        std::string getEspecialidade();

        /**
         * @brief Define o membro Id
         * 
         * @param id 
         */
        void setId(int id);

        /**
         * @brief Define o membro Nome
         * 
         * @param nome 
         */
        void setNome(std::string nome);

        /**
         * @brief Define o membro Cpf
         * 
         * @param cpf 
         */
        void setCpf(std::string cpf);

        /**
         * @brief Define o membro Idade
         * 
         * @param idade 
         */
        void setIdade(short idade);

        /**
         * @brief Define o membro Tipo Sanguineo
         * 
         * @param tipo 
         */
        void setTipoSanguineo(short tipo);

        /**
         * @brief Define o membro Fator Rh
         * 
         * @param fator 
         */
        void setFatorRh(char fator);

        /**
         * @brief Define o membro Especialidade
         * 
         * @param especialidade 
         */
        void setEspecialidade(std::string especialidade);

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool save();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool update();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool remove();
};
    
#endif
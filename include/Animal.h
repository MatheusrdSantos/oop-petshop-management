#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Veterinario.h"
#include "Tratador.h"

#include <iostream>
#include <string>

class Animal : public ModelDAO<Animal>{
    private:

    protected:
        int m_id; /**< Define o id de cada Animal. Um id é único. */
        std::string m_classe; /**< Define o nome da classe de cada Animal. Podem ser Amphibia, Aves, Mammalia e Reptilia.*/
        std::string m_nome; /**< Define o nome coloquial de cada Animal. Ex: Leão.*/
        std::string m_nome_cientifico; /**< Define o nome científico de cada Animal. Ex: Panthera leo.*/
        char m_sexo; /**< Define o sexo de cada Animal. Pode ser M, para masculino, ou F, para feminino.*/
        double m_tamanho; /**< Define o tamanho de cada Animal.*/
        std::string m_dieta; /**< Define a dieta de cada Animal. Ex: Herbívoro*/
        Veterinario* m_veterinario; /**< Define que veterinário é responsável por cada Animal.*/
        Tratador* m_tratador; /**< Define que tratador é responsável por cada Animal.*/
        std::string m_nome_batismo; /**< Define o nome de batismo de cada Animal. Ex: Simba.*/
    public:
        /**
         * @brief Constrói um novo objeto do tipo Animal
         * 
         */
        Animal(){};
        /**
         * @brief Constrói um novo objeto do tipo Animal
         * 
         * @param id 
         * @param classe 
         * @param nome_cientifico 
         * @param sexo 
         * @param tamanho 
         * @param dieta 
         * @param veterinario 
         * @param tratador 
         * @param nome_batismo 
         */
        Animal(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, Veterinario* veterinario, Tratador* tratador, std::string nome_batismo);
        ~Animal(){};



        static std::string filePath; /**< Define o caminho para a tabela que armazenará os Animais. */
        static std::string tableName; /**< Define o nome para a tabela que armazenará os Animais, tal valor é utilizado para os ids de autoincremento. */

        /**
         * @brief Retorna todos os animais do banco.
         * 
         * @return std::multimap<std::string, Animal*> 
         */
        static std::multimap<std::string, Animal*> all();

        /**
         * @brief Constrói um único animal de uma linha do arquivo.
         * 
         * @param file 
         * @return Animal* 
         */
        static Animal* buildAnimalFromFile(csv::Row* file);
        
        /**
         * @brief Retorna um funcionário passado o id por parâmetro.
         * 
         * @param id 
         * @return Funcionario* 
         */
        static Funcionario* find(int id);

        /**
         * @brief Get the Id object
         * 
         * @return int 
         */
        int getId();

        /**
         * @brief Set the Id object
         * 
         * @param id 
         */
        void setId(int id);

        /**
         * @brief Get the Dieta object
         * 
         * @return std::string 
         */
        std::string getDieta();
        /**
         * @brief Set the Dieta object
         * 
         * @param dieta 
         */
        void setDieta(std::string dieta);
        
        /**
         * @brief Get the Nome Batismo object
         * 
         * @return std::string 
         */
        std::string getNomeBatismo();

        /**
         * @brief Set the Nome Batismo object
         * 
         * @param nome_batismo 
         */
        void setNomeBatismo(std::string nome_batismo);
        /**
         * @brief Get the Classe object
         * 
         * @return std::string 
         */
        std::string getClasse();
        /**
         * @brief Set the Classe object
         * 
         * @param classe 
         */
        void setClasse(std::string classe);

        /**
         * @brief Get the Nome Cientifico object
         * 
         * @return std::string 
         */
        std::string getNomeCientifico();

        /**
         * @brief Set the Nome Cientifico object
         * 
         * @param nome_cientifico 
         */
        void setNomeCientifico(std::string nome_cientifico);

        /**
         * @brief Get the Sexo object
         * 
         * @return char 
         */
        char getSexo();

        /**
         * @brief Set the Sexo object
         * 
         * @param sexo 
         */
        void setSexo(char sexo);

        /**
         * @brief Get the Tamanho object
         * 
         * @return double 
         */
        double getTamanho();

        /**
         * @brief Set the Tamanho object
         * 
         * @param tamanho 
         */
        void setTamanho(double tamanho);

        /**
         * @brief Get the Veterinario object
         * 
         * @return Veterinario* 
         */
        Veterinario* getVeterinario();

        /**
         * @brief Set the Veterinario object
         * 
         * @param veterinario 
         */
        void setVeterinario(Veterinario* veterinario);

        /**
         * @brief Get the Tratador object
         * 
         * @return Tratador* 
         */
        Tratador* getTratador();

        /**
         * @brief Set the Tratador object
         * 
         * @param tratador 
         */
        void setTratador(Tratador* tratador);

        /**
         * @brief Salva os dados do animal no banco.
         * 
         * @return true 
         * @return false 
         */
        bool save();

        /**
         * @brief Atualiza o animal no banco.
         * 
         * @return true 
         * @return false 
         */
        bool update();

        /**
         * @brief Remove o animal do banco.
         * 
         * @return true 
         * @return false 
         */
        bool remove();
        
        /**
         * @brief Define a forma como o texto do animal será armazenada no banco, se altera dependendo da classe derivada.
         * 
         * @param id 
         * @return std::string 
         */
        virtual std::string printInFile(int id) = 0;
};

#endif
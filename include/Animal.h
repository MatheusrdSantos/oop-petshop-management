#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Veterinario.h"
#include "Tratador.h"

#include <iostream>
#include <string>

class Animal : public ModelDAO<Animal>{
    private:

        virtual std::ostream& print(std::ostream&) const = 0;

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

       
        /**
         * @brief Define a forma como o texto do animal será armazenada no banco, se altera dependendo da classe derivada.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        virtual std::string printInFile(int id) = 0;

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

        /**
         * @brief Destrói o objeto do tipo Animal.
         * 
         */
        virtual ~Animal();

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
         * @brief Retorna um animal passado o id por parâmetro.
         * 
         * @param id 
         * @return Animal* 
         */
        static Animal* find(int id);

        /**
         * @brief Retorna Id do Animal
         * 
         * @return int 
         */
        int getId();

        /**
         * @brief Define um(a) novo(a) Id para o Animal
         * 
         * @param id 
         */
        void setId(int id);

        /**
         * @brief Retorna Dieta do Animal
         * 
         * @return std::string 
         */
        std::string getDieta();
        /**
         * @brief Define um(a) novo(a) Dieta para o Animal
         * 
         * @param dieta 
         */
        void setDieta(std::string dieta);
        
        /**
         * @brief Retorna Nome Batismo do Animal
         * 
         * @return std::string 
         */
        std::string getNomeBatismo();

        /**
         * @brief Define um(a) novo(a) Nome para atismo do Animal
         * 
         * @param nome_batismo 
         */
        void setNomeBatismo(std::string nome_batismo);
        /**
         * @brief Retorna Classe do Animal
         * 
         * @return std::string 
         */
        std::string getClasse();
        /**
         * @brief Define um(a) novo(a) Classe para o Animal
         * 
         * @param classe 
         */
        void setClasse(std::string classe);

        /**
         * @brief Retorna Nome Cientifico do Animal
         * 
         * @return std::string 
         */
        std::string getNomeCientifico();

        /**
         * @brief Define um(a) novo(a) Nome científico para o Animal
         * 
         * @param nome_cientifico 
         */
        void setNomeCientifico(std::string nome_cientifico);

        /**
         * @brief Retorna Sexo do Animal
         * 
         * @return char 
         */
        char getSexo();

        /**
         * @brief Define um(a) novo(a) Sexo para o Animal
         * 
         * @param sexo 
         */
        void setSexo(char sexo);

        /**
         * @brief Retorna o Tamanho do Animal
         * 
         * @return double 
         */
        double getTamanho();

        /**
         * @brief Define um(a) novo(a) Tamanho para o Animal
         * 
         * @param tamanho 
         */
        void setTamanho(double tamanho);

        /**
         * @brief Retorna o Veterinario do Animal
         * 
         * @return Veterinario* 
         */
        Veterinario* getVeterinario();

        /**
         * @brief Define um(a) novo(a) Veterinario para o Animal
         * 
         * @param veterinario 
         */
        void setVeterinario(Veterinario* veterinario);

        /**
         * @brief Retorna o Tratador do Animal
         * 
         * @return Tratador* 
         */
        Tratador* getTratador();

        /**
         * @brief Define um(a) novo(a) Tratador para o Animal
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
         * @brief Seleciona os animais com base em um filtro especificado
         * 
         * @param column
         * @param symbol
         * @param value
         * 
         * @return std::multimap<std::string, Animal*>  
         */
        static std::multimap<std::string, Animal*> where(std::string* column, std::string* symbol, std::string* value);
        
        /**
         * @brief Seleciona os animais com base em um filtro especificado
         * 
         * @param column
         * @param symbol
         * @param value
         * 
         * @return std::multimap<std::string, Animal*>  
         */
        static std::multimap<std::string, Animal*> where(std::string* column, std::string* symbol, int value);
        
        /**
         * @brief Saída para print de um Animal.
         * 
         * @param os 
         * @param a 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& os, const Animal& a);

        /**
         * @brief Leitura das informações de um Animal a partir do terminal.
         * 
         * @param in
         * @param a
         * @return std::istream&
         */
        friend std::istream& operator >> (std::istream &in, Animal *a);
};

#endif
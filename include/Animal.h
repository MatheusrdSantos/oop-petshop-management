#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Veterinario.h"
#include "Tratador.h"

#include <iostream>
#include <string>
/**
 * @brief Classe Animal é a classe base de todos os animais.
 * 
 */
class Animal : public ModelDAO<Animal>{
    private:

    protected:
        
        int m_id;
        std::string m_classe;
        std::string m_nome;
        std::string m_nome_cientifico;
        char m_sexo;
        double m_tamanho;
        std::string m_dieta;
        Veterinario* m_veterinario;
        Tratador* m_tratador;
        std::string m_nome_batismo;
    public:
        Animal(){};
        /**
         * @brief Constroi um novo Animal
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
        Animal(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, const Veterinario* veterinario, const Tratador* &tratador, std::string nome_batismo);
        ~Animal(){};



        static std::string filePath;
        static std::string tableName;

        static std::multimap<std::string, Animal*> all();
        static Animal* buildAnimalFromFile(csv::Row* file);

        static Funcionario* find(int id);

        int getId();
        void setId(int id);

        std::string getDieta();
        void setDieta(std::string dieta);
        
        std::string getNomeBatismo();
        void setNomeBatismo(std::string nome_batismo);

        std::string getClasse();
        void setClasse(std::string classe);

        std::string getNomeCientifico();
        void setNomeCientifico(std::string nome_cientifico);

        char getSexo();
        void setSexo(char sexo);

        double getTamanho();
        void setTamanho(double tamanho);

        Veterinario* getVeterinario();
        void setVeterinario(Veterinario* veterinario);

        Tratador* getTratador();
        void setTratador(Tratador* tratador);


        bool save();
        bool update();
        bool remove();
        
        virtual std::string printInFile(int id) = 0;
};

#endif
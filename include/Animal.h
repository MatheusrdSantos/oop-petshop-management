#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Veterinario.h"
#include "Tratador.h"

#include <iostream>
#include <string>

class Animal : public ModelDAO<Animal>{
    private:

    protected:
        int m_id;
        std::string m_classe;
        std::string m_nome_cientifico;
        char m_sexo;
        double m_tamanho;
        std::string m_dieta;
        Veterinario m_veterinario;
        Tratador m_tratador;
        std::string m_nome_batismo;
    public:
        Animal();
        Animal(int id, std::string classe, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, const Veterinario &veterinario, const Tratador &tratador, std::string nome_batismo, );
        ~Animal(){};



        static std::string filePath;
        static std::string tableName;

        static std::multimap<std::string,Animal*> all();
        
        static Funcionario* find(int id);

        std::string getNomeBatismo();
};

#endif
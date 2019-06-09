#ifndef _REPTIL_H
#define _REPTIL_H

#include <iostream>
#include <string>
#include "Animal.h"

class Reptil : public Animal{
    private:

    protected:
        bool m_venenoso;
        std::string m_tipo_veneno;
    public:
        Reptil();
        
        Reptil(int id,std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        Reptil(std::string classe,std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        Reptil(std::string nome,std::string nome_cientifico,char sexo,double tamanho,std::string dieta,Veterinario* veterinario,Tratador* tratador,std::string nome_batismo,bool venenoso,std::string tipo_veneno);

        ~Reptil(){};

        bool isVenenoso();
        void setVenenoso(bool venenoso);

        std::string getTipoVeneno();
        void setTipoVeneno(std::string tipo_veneno);

        virtual std::string printInFile(int id) = 0;

};

#endif
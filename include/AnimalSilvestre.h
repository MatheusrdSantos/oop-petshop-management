#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <iostream>
#include <string>

class AnimalSilvestre{
    private:

    protected:
        std::string m_autorizacao_ibama;
        
    public:
        AnimalSilvestre();
        ~AnimalSilvestre(){};

        std::string getAutorizacaoIbama();
        void getAutorizacaoIbama(std::string autorizacao_ibama);

};

#endif
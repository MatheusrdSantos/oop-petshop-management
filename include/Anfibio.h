#ifndef _ANFIBIO_H
#define _ANFIBIO_H
#include "Date.h"

#include <iostream>
#include <string>
#include "Animal.h"

class Anfibio : public Animal{
    private:

        virtual std::ostream& print(std::ostream&) const = 0;
    protected:
        int m_total_de_mudas; /**< Define o total de mudas de cada Anfíbio. O id é único. */
        Date* m_ultima_muda; /**< Define quando o Anfíbio teve sua última muda. new Date(0,0,0) para nunca (default).*/
        
        /**
         * @brief Define a forma como o texto do Anfíbio será armazenada no banco, se altera dependendo da classe derivada.
         * 
         * @param id Id do objeto (utilizará o do auto incremento no momento de sua chamada).
         * @return std::string String formatada de como o objeto será armazenado no banco.. 
         */
        virtual std::string printInFile(int id) = 0;

    public:

        /**
         * @brief Constrói um novo objeto do tipo Anfíbio.
         * 
         */
        Anfibio();

        /**
         * @brief Destrói o objeto do tipo Animal.
         * 
         */
        ~Anfibio(){};

};

#endif
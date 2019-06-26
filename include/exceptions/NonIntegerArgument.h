#ifndef _NON_INTEGER_ARGUMENT_H
#define _NON_INTEGER_ARGUMENT_H

#include <stdexcept>
using std::invalid_argument;
class NonIntegerArgument : public invalid_argument {
    private:
        std::string m_default_message = "Argumento inválido: o valor do argumento deve ser inteiro.\n Valor fornecido: ";
    public:
    NonIntegerArgument(std::string value);
};

#endif
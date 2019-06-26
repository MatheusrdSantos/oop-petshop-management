#ifndef _INVALID_SECURITY_LEVEL_H
#define _INVALID_SECURITY_LEVEL_H
#include <stdexcept>
using std::invalid_argument;
class InvalidSecurityLevel : public  invalid_argument{
    private:
        std::string m_default_message = "Argumento inválido: o nível de segurança varia de 0 até 2.\n Valor fornecido: ";
    public:
    InvalidSecurityLevel(std::string value);
};
#endif
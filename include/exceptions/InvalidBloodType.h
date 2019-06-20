#include <stdexcept>
using std::invalid_argument;
class InvalidBloodType : public invalid_argument {
    private:
        std::string m_default_message = "Argumento inválido: os valores válidos são:\nA\nB\nAB\nO\n Valor fornecido: ";
    public:
    InvalidBloodType(std::string value);
};
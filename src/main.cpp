#include "Funcionario.h"
#include "Tratador.h"
#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    /* Tratador t1(2, "Jose", "7033", 32, 2, 'H', "limpar", 1);
    t1.save();
    Tratador t2(3, "Matheus", "7012", 19, 2, 'O', "cuidar", 2);
    t2.save();
    Tratador t3(4, "Maria", "70111", 22, 2, 'H', "comida", 0);
    t3.save(); */
    std::multimap<std::string,Funcionario*> funcionarios = Funcionario::all();

    // showing contents:
    std::cout << "mymultimap contains:\n";
    for (auto it=funcionarios.begin(); it!=funcionarios.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNome() << '\n';
    }
    return 0;
}

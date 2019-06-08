#include "Funcionario.h"
#include "Tratador.h"
#include "Veterinario.h"
#include <iostream>
#include <map>


int main(int argc, char const *argv[])
{
    Tratador t1("Jose", "7033", 32, 2, 'H', "limpar", 1);
    t1.save();
    Tratador t2("Matheus", "7012", 19, 2, 'O', "cuidar", 2);
    t2.save();
    Tratador t3("Maria", "70111", 22, 2, 'H', "comida", 0);
    t3.save();
    Veterinario v1("Arnaldo", "7013411", 21, 2, 'H', "cura", "aa");
    v1.setCnmv("zz");
    v1.save();
    Veterinario v2("Davis", "7011111", 19, 2, 'H', "cura", "bb");
    v2.save();
    std::multimap<std::string,Funcionario*> funcionarios = Funcionario::all();

    // showing contents:
    std::cout << "mymultimap contains:\n";
    for (auto it=funcionarios.begin(); it!=funcionarios.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNome() << '\n';
    }

    Funcionario* func =  Funcionario::find(3);
    std::cout<<"id -> 3;"<<std::endl<<func->getNome()<<std::endl;

    std::string columnName = "nome";
    std::string symbol = "==";
    std::string value = "Matheus";

    /* std::string columnName = "funcao";
    std::string symbol = "==";
    std::string value = "Tratador"; */

    std::multimap<std::string,Funcionario*> funcionarios_where = Funcionario::where(&columnName, &symbol, &value);
    
    std::cout << "select where contains:\n";
    for (auto it=funcionarios_where.begin(); it!=funcionarios_where.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNome() << '\n';
    }
    func =  Funcionario::find(3);
    func->setNome("Ronaldo");
    func->setIdade(30);
    func->update();
    return 0;
}

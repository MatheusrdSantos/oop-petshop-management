#include "../include/Interacao.h"
#include "../include/Animal.h"
#include "../include/AnfibioExotico.h"
#include "../include/AnfibioNativo.h"
#include "../include/MamiferoExotico.h"
#include "../include/MamiferoNativo.h"
#include "../include/ReptilExotico.h"
#include "../include/ReptilNativo.h"
#include "../include/AveExotico.h"
#include "../include/AveNativo.h"
#include <string>
#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    run();
    return 0;
}

    /*Tratador t1(1, "Jose", "7033", 32, 2, 'H', "limpar", 1);
    t1.save();
    Tratador t2("Matheus", "7012", 19, 2, 'O', "cuidar", 2);
    t2.save();
    Tratador t3("Maria", "70111", 30, 2, 'H', "comida", 0);
    t3.save();
    Veterinario v1(4, "Arnaldo", "7013411", 21, 2, 'H', "cura", "aa");
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

    std::string columnName = "funcao";
    std::string symbol = "==";
    std::string value = "Tratador";

    std::multimap<std::string,Funcionario*> funcionarios_where = Funcionario::where(&columnName, &symbol, &value);
    
    std::cout << "select where contains:\n";
    for (auto it=funcionarios_where.begin(); it!=funcionarios_where.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNome() << '\n';
    }
    func =  Funcionario::find(3);
    func->setNome("Ronaldo");
    func->setIdade(30);
    func->update();

    func = Funcionario::find(4);
    func->remove();

    columnName = "idade";
    symbol = "==";
    int i_value = 30;

    funcionarios_where = Funcionario::where(&columnName, &symbol, i_value);
    
    std::cout << "select where(int) contains:\n";
    for (auto it=funcionarios_where.begin(); it!=funcionarios_where.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNome() << '\n';
    }

    return 0;
}*/

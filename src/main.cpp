#include "../include/Interacao.h"
#include "../include/AnfibioExotico.h"
#include <string>
#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    //int escolha = 0;
    //menu(escolha);
    
    Tratador *t1 = new Tratador(1, "Jose", "7033", 32, 2, 'H', "limpar", 1);
    Veterinario* v1 = new Veterinario(4, "Arnaldo", "7013411", 21, 2, 'H', "cura", "aa");
    AnfibioExotico a1("Camaleao", "Amphibia Nautilia", 'M', 2.42, "Herbivoro", v1, t1, "Rango");
    a1.save();
    //Loop para o menu sempre permanecer na tela até que o input seja 0
    /*
    while(escolha > 0){ 
        menu(escolha);
    }
    */
    return 0;
}


/*
    Tratador t1(1, "Jose", "7033", 32, 2, 'H', "limpar", 1);
    t1.save();
    Tratador t2("Matheus", "7012", 19, 2, 'O', "cuidar", 2);
    t2.save();
    Tratador t3("Maria", "70111", 22, 2, 'H', "comida", 0);
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
    */

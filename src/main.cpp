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
    //int escolha = 0;
    //menu(escolha);
    
    Tratador *t1 = new Tratador(1, "Jose", "7033", 32, "A", 'H', "limpar", 1);
    Veterinario* v1 = new Veterinario(4, "Arnaldo", "7013411", 21, "A", 'H', "cura", "aa");
    
    t1->save();
    v1->save();
    
    /*
    AnfibioExotico a1("Camaleao", "Amphibia Nautilia", 'M', 2.42, "Herbivoro", v1, t1, "Rango");
    AnfibioExotico a2("Lagartixa", "Amphibia Lartichia", 'F', 6.61, "Herbivoro", NULL, NULL, "Iago");

    AnfibioNativo anfibioNativo("Sapo", "Amphibia Nautilus", 'M', 10.5, "Onívoro", v1, t1, "Sapo Frog", 2, new Date(12,12,2018), "RN", "Natal", "1054512-51");
    anfibioNativo.save();

    AnfibioExotico anfibioExotico("Sapo Rinoceronte", "Amphibia Sapus Rinocerontis", 'F', 15.3, "Herbívoro", v1, t1, "Rhino",1000, new Date(10,10,2015), "1511244-89", "Africa do Sul", "Kantilius");
    anfibioExotico.save();

    MamiferoNativo mamiferoNativo("Leão", "Mammalia Leoncius", 'M', 2000.6, "Carnivoro", v1, t1,"Samba", "Escamuças castanhas", "AC", "Brasileia", "152421-41");
    mamiferoNativo.save();

    MamiferoExotico mamiferoExotico("Onça Gigante", "Mammalia Oncea Gigantus", 'F', 10000.2, "Carnivoro", v1, t1, "Onça Braba", "Preto", "China", "Xiung Piang", "234151-31");
    mamiferoExotico.save();

    ReptilNativo reptilNativo("Lagarto", "Reptilia Lagartus", 'M', 10.5, "Herbívoro", v1, t1, "Cecil", true, "Ceplusplus", "AM", "João Bandeirante", "154121514-5");
    reptilNativo.save();

    ReptilExotico reptilExotico("Camaleão do Faroeste Caboclo", "Reptilia Camaleoncius", 'M', 15.6, "Herbivoro", v1, t1, "Ringo", false, "", "Estados Unidos da Ámerica", "Seattle", "1215121-87");
    reptilExotico.save();

    AveNativo aveNativo("Arara azul", "Aves Azulis", 'M', 25.2, "Herbívoro", v1, t1, "Carlos", 2.34, 12.5, "AM", "Efeême", "152451-451");
    aveNativo.save();

    AveExotico aveExotico("Pintinho Piu", "Aves Pìuzis", 'F',11.2, "Herbívoro", v1, t1, "Piu-piu", 0.4, 5.2, "Estados Unidos da América", "North Dakota", "12451-9");
    aveExotico.save(); 

    
    std::multimap<std::string,Animal*> animals_all = Animal::all();
    
    std::cout << "select where contains:\n";
    for (auto it=animals_all.begin(); it!=animals_all.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNomeBatismo() << '\n';
    }
    std::cout<<"Find test: "<<std::endl;
    std::cout<<Animal::find(4)->getNomeBatismo()<<std::endl;
    
    std::string column = "nome_batismo";
    std::string symbol = "==";
    std::string value = "Piu-piu";
    std::multimap<std::string,Animal*> animals_where = Animal::where(&column, &symbol, &value);
    
    std::cout << "select where contains:\n";
    for (auto it=animals_where.begin(); it!=animals_where.end(); ++it){
        std::cout << (*it).first << " => " << (*it).second->getNomeBatismo() << '\n';
    }*/
    /* Animal* animal = Animal::find(4);
    animal->setNomeBatismo("Jurema");
    animal->update();
    
    std::cout<<"Update test: "<<std::endl;
    std::cout<<Animal::find(4)->getNomeBatismo()<<std::endl;

    Animal::find(4)->remove(); */
    
    run();

    /*
    AnfibioExotico a3("Lagarto da Calda verde", "Amphibia Verdinis", 'M', 20.61, "Carnívoro", NULL, t1, "Sekto");
    AnfibioExotico a4("Sapo do gogó", "Amphibia Geologis Sapus", 'M', 10.61, "Onívoro", v1, NULL, "Gente Boa", 10, new Date(10,05,2019), "15242-51", "Itália", "Veneza");

    a1.save();
    a2.save();
    a3.save();
    a4.save();
    */
    
    
    //Loop para o menu sempre permanecer na tela até que o input seja 0
    /*
    while(escolha > 0){ 
        menu(escolha);
    }
    */
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

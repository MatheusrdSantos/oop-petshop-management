#include "Interacao.h"
#include "bprinter/table_printer.h"

void menu(int &escolha){
    std::cout << std::endl;
    
    textColor_red("PetFera 2019.1 | AMD - All Rights Reserved ©");
    std::cout << std::endl;
    textColor_red("============================================");
    std::cout << std::endl;
    
    std::cout << "Escolha uma opção e divirta-se: " << std::endl;
    std::cout << "    1 -> Adicionar Funcionário " << std::endl;
    std::cout << "    2 -> Listar Funcionários " << std::endl;
    //std::cout << "    3 -> Adicionar Animal " << std::endl;
    std::cout << "    0 -> Sair " << std::endl;
    std::cin >> escolha;

    switch (escolha)
    {
        case 0:
            std::cout << "Tchau! Volte sempre" << std::endl;
            break;
        case 1:
            std::cout << "Escolheu a opção 1, congrats" << std::endl;
            break;
        case 2:
            listAll_Funcionarios();
            break;
        
        default:
            std::cout << "Essa opção não existe, man" << std::endl;
            break;
    }
}

void textColor_red(std::string texto){
    std::cout << "\033[1;31m" << texto << "\033[0m";
}

void textColor_yellow(std::string texto){
    std::cout << "\033[1;33m" << texto << "\033[0m";
}

void listAll_Funcionarios(){
    std::multimap<std::string,Funcionario*> funcionarios = Funcionario::all();

    std::cout<<std::endl;
    if(funcionarios.size() == 0){
        textColor_yellow("Não há funcionários cadastrados no sistema!"); 
        std::cout<<std::endl;
    }else{
        bprinter::TablePrinter tp(&std::cout);
        tp.AddColumn("Cargo", 15);
        tp.AddColumn("Idade", 5);
        tp.AddColumn("Nome", 30);
        tp.AddColumn("CPF", 15);
        tp.AddColumn("Tipo Sanguineo", 15);
        tp.AddColumn("Fator RH", 5);
        tp.AddColumn("Especialidade", 15);

        tp.PrintHeader();
        for (auto it=funcionarios.begin(); it!=funcionarios.end(); ++it){
            tp << (*it).first 
               << (*it).second->getIdade() 
               << (*it).second->getNome() 
               << (*it).second->getCpf() 
               << (*it).second->getTipoSanguineo() 
               << (*it).second->getFatorRh() 
               << (*it).second->getEspecialidade();
        }

        tp.PrintFooter();
    }
}
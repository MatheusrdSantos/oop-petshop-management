#include "Interacao.h"

void menu(int &escolha){
    std::cout << std::endl;
    
    textColor_vermelhoBold("PetFera 2019.1 | AMD - All Rights Reserved ©");
    std::cout << std::endl;
    textColor_vermelhoBold("============================================");
    std::cout << std::endl;
    
    std::cout << "Escolha uma opção e divirta-se: " << std::endl;
    std::cout << "    1 -> Adicionar Funcionário " << std::endl;
    std::cout << "    2 -> Listar Funcionários " << std::endl;
    std::cout << "    3 -> Adicionar Animal " << std::endl;
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
            std::cout << "Escolheu a opção 2, congrats" << std::endl;
            break;
        
        default:
            std::cout << "Essa opção não existe, man" << std::endl;
            break;
    }
}

void textColor_vermelhoBold(std::string texto){
    std::cout << "\033[1;31m" << texto << "\033[0m";
}
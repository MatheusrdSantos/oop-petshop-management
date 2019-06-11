#include "../../include/Interacao.h"

void run(){
    int escolha = 0;
    menu(escolha);

    //Loop para o menu sempre permanecer na tela até que o input seja 0
    while(escolha > 0){
        menu(escolha);
    }
}

void menu(int &escolha){
    std::cout << std::endl;
    
    textColor_red("PetFera 2019.1 | AMD - All Rights Reserved ©");
    std::cout << std::endl;
    textColor_red("============================================");
    std::cout << std::endl;
    
    std::cout << "# Menu #" << std::endl;
    std::cout << "    1 -> Adicionar funcionário " << std::endl;
    std::cout << "    2 -> Listar todos funcionários " << std::endl;
    std::cout << "    3 -> Listar todos animais " << std::endl;
    std::cout << "    0 -> Sair " << std::endl;
    std::cin >> escolha;

    switch (escolha)
    {
        case 0:
            textColor_red("========== Tchau! PetFera 2019.1  ==========");
            std::cout << std::endl;
            break;
        case 1:
            add_Funcionario();
            break;
        case 2:
            listAll_Funcionarios();
            break;
        case 3:
            listAll_Animais();
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
        for (auto it=funcionarios.begin(); it!=funcionarios.end(); ++it){
            std::cout<< *(it->second);
        }
    }
}

void add_Funcionario(){
    char cargo;
    std::cout << "O funcionário é um tratador ou um veterinário (t/v)?" << std::endl;
    std::cin >> cargo;

    std::string nome;
    std::string cpf;
    short idade;
    short tipo_sanguineo;
    char fator_rh;
    std::string especialidade;

    if(cargo == 's'){
        return;
    }else if(cargo != 't' && cargo != 'v'){
        std::cout << "Há apenas duas opções: 't' caso queira adicionar um funcionário ou 'v' para adicionar um veterinário. Para voltar escolha 's'." << std::endl;
        add_Funcionario();
    }else{
        std::cout << "======= Dados do(a) "<< (cargo == 't' ? "Tratador(a)" : "Veterinário(a)") <<"======="<< std::endl;
        std::cout << "Nome: ";
        std::cin >> nome;
        
        std::cout << "CPF: ";
        std::cin >> cpf;

        std::cout << "Idade: ";
        std::cin >> idade;

        std::cout << "Tipo Sanguínio: ";
        std::cin >> tipo_sanguineo;

        std::cout << "Fator RH: ";
        std::cin >> fator_rh;

        std::cout << "Especialidade: ";
        std::cin >> especialidade;

        if(cargo == 't'){
            int nivel_de_seguranca;

            std::cout << "Nível de Segurança: ";
            std::cin >> nivel_de_seguranca;

            Tratador trat(nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_de_seguranca);
            trat.save(); 

            std::cout << "Tratador adicionado!" << std::endl;        
        }else if(cargo == 'v'){
            std::string cnmv;
            std::cout << "Nível de Segurança: ";
            std::cin >> cnmv;

            Veterinario vet(nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, cnmv);
            vet.save();

            std::cout << "Veterinário adicionado!" << std::endl;
        }
    }
}

void listAll_Animais(){
    std::multimap<std::string,Animal*> animais = Animal::all();

    std::cout<<std::endl;
    if(animais.size() == 0){
        textColor_yellow("Não há animais cadastrados no sistema!"); 
        std::cout<<std::endl;
    }else{
        for (auto it=animais.begin(); it!=animais.end(); ++it){
            std::cout<< *(it->second);
        }
    }
}
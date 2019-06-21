#include "../../include/Interacao.h"

void run(){
    int escolha = 0;
    menu(escolha);

    //Loop para o menu sempre permanecer na tela até que o input seja 0
    while(escolha > 0){
        menu(escolha);
    }
}

int getOrigem(){
    int option = 0;
    std::cout<<"Qual o tipo do animal?"<<std::endl;
    std::cout<<"1 -> Nativo"<<std::endl;
    std::cout<<"2 -> Exótico"<<std::endl;
    std::cin>>option;
    return option;
}

void identify_Animal(){
    std::string opt_animal_class = chooseClass_Animal();

    if(std::stoi(opt_animal_class) == 0){
        std::cout << std::endl;
    }else if(std::stoi(opt_animal_class) > 0 && std::stoi(opt_animal_class) < 5){
        std::string opt_animal_nature = chooseNature_Animal();
        
        if(std::stoi(opt_animal_nature) == 0){
            std::cout << std::endl;
        }else if(std::stoi(opt_animal_nature) == 1 || std::stoi(opt_animal_nature) == 2){
            add_Animal(std::stoi(opt_animal_class), std::stoi(opt_animal_nature));
        }else{
            textColor_yellow("Essa opção não existe!");
        }
    }else{
        textColor_yellow("Essa opção não existe!");
    }
    
}

void identify_Funcionario(){
    std::string opt_func = chooseRole_Funcionario();

    if(std::stoi(opt_func) == 0){
        std::cout << std::endl;
    }else if(std::stoi(opt_func) == 1 || std::stoi(opt_func) == 2){
        add_Funcionario(std::stoi(opt_func));
    }else{
        textColor_yellow("Essa opção não existe!");
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
    std::cout << "    2 -> Adicionar animal " << std::endl;
    std::cout << "    3 -> Listar todos funcionários " << std::endl;
    std::cout << "    4 -> Listar todos animais " << std::endl;
    std::cout << "    0 -> Sair " << std::endl;
    std::cin >> escolha;

    switch (escolha)
    {
        case 0:
            textColor_red("========== Tchau! PetFera 2019.1  ==========");
            std::cout << std::endl;
            break;
        case 1:
            identify_Funcionario();
            break;
        case 2:
            identify_Animal();
            break;
        case 3:
            listAll_Funcionarios();
            break;
        case 4:
            listAll_Animais();
            break;

        default:
            textColor_yellow("Essa opção não existe!");
            break;
    }
}

void textColor_red(std::string text){
    std::cout << "\033[1;31m" << text << "\033[0m";
}

void textColor_yellow(std::string text){
    std::cout << "\033[1;33m" << text << "\033[0m";
}

void textColor_green(std::string text){
    std::cout << "\033[1;32m" << text << "\033[0m";
}

void listAll_Funcionarios(){
    std::multimap<std::string,Funcionario*> funcionarios = Funcionario::all();

    std::cout<<std::endl;
    if(funcionarios.size() == 0){
        textColor_yellow("Não há funcionários cadastrados no sistema!"); 
        std::cout<<std::endl;
    }else{
        int counter = 1;
        for (auto it=funcionarios.begin(); it!=funcionarios.end(); ++it){
            std::cout<< *(it->second);
            delete it->second;

            std::cout<<"===================== "<< counter++ <<" ====================="<<std::endl<<std::endl;
        }
        std::cout<<std::endl<<"####### Há "<< funcionarios.size() <<" funcionarios cadastrados #######"<<std::endl;
    }
}

void listAll_Animais(){
    std::multimap<std::string,Animal*> animais = Animal::all();

    std::cout<<std::endl;
    if(animais.size() == 0){
        textColor_yellow("Não há animais cadastrados no sistema!"); 
        std::cout<<std::endl;
    }else{
        int counter = 1;
        for (auto it=animais.begin(); it!=animais.end(); ++it){
            std::cout<< *(it->second);
            delete it->second;

            std::cout<<"===================== "<< counter++ <<" ====================="<<std::endl<<std::endl;
        }
        std::cout<<std::endl<<"######### Há "<< animais.size() <<" animais cadastrados #########"<<std::endl;
    }
}

std::string chooseClass_Animal(){
    std::cout << "Qual a classe do Animal?" << std::endl;
    std::cout << "  1 -> Anfibio"<<std::endl;
    std::cout << "  2 -> Mamifero"<<std::endl;
    std::cout << "  3 -> Reptil"<<std::endl;
    std::cout << "  4 -> Ave"<<std::endl;
    std::cout << "  0 -> Voltar"<<std::endl;

    std::string opt;
    std::cin>>opt;

    while((std::stoi(opt)!=0) && (std::stoi(opt)!=1) && (std::stoi(opt)!=2)  && (std::stoi(opt)!=3) && (std::stoi(opt)!=4)){
        std::cout << "Qual a classe do Animal?" << std::endl;
        std::cout << "  1 -> Anfibio"<<std::endl;
        std::cout << "  2 -> Mamifero"<<std::endl;
        std::cout << "  3 -> Reptil"<<std::endl;
        std::cout << "  4 -> Ave"<<std::endl;
        std::cout << "  0 -> Voltar"<<std::endl;

        std::cin>>opt;
    }

    return opt;
}

std::string chooseNature_Animal(){
    std::cout << "Qual a natureza do Animal?" << std::endl;
    std::cout << "  1 -> Exotico"<<std::endl;
    std::cout << "  2 -> Nativo"<<std::endl;
    std::cout << "  0 -> Voltar"<<std::endl;

    std::string opt;
    std::cin>>opt;

    while((std::stoi(opt)!=0) && (std::stoi(opt)!=1) && (std::stoi(opt)!=2)){
        std::cout << "Qual a natureza do Animal?" << std::endl;
        std::cout << "  1 -> Exotico"<<std::endl;
        std::cout << "  2 -> Nativo"<<std::endl;
        std::cout << "  0 -> Voltar"<<std::endl;

        std::cin>>opt;
    }

    return opt;
}

void add_Animal(int animal_class, int animal_nature){
    std::string choosed_animal;

    if(animal_class == 1){
        //Classe: Anfíbio

        if(animal_nature == 1){
            //Natureza: Exótico

            AnfibioExotico *anfibio_exotico = new AnfibioExotico();
            Animal *animal = anfibio_exotico;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Anfibio Exotico";
        }else if(animal_nature == 2){
            //Natureza: Nativo

            AnfibioNativo *anfibio_nativo = new AnfibioNativo();
            Animal *animal = anfibio_nativo;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Anfibio Nativo";
        }
    }else if(animal_class == 2){
        //Classe: Mamifero

        if(animal_nature == 1){
            //Natureza: Exótico

            MamiferoExotico *mamifero_exotico = new MamiferoExotico();
            Animal *animal = mamifero_exotico;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Mamifero Exotico";
        }else if(animal_nature == 2){
            //Natureza: Nativo

            MamiferoNativo *mamifero_nativo = new MamiferoNativo();
            Animal *animal = mamifero_nativo;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Mamifero Nativo";
        }
    }else if(animal_class == 3){
        //Classe: Réptil

        if(animal_nature == 1){
            //Natureza: Exótico

            ReptilExotico *reptil_exotico = new ReptilExotico();
            Animal *animal = reptil_exotico;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Reptil Exotico";
        }else if(animal_nature == 2){
            //Natureza: Nativo

            ReptilNativo *reptil_nativo = new ReptilNativo();
            Animal *animal = reptil_nativo;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Reptil Nativo";
        }
    }else if(animal_class == 4){
        //Classe: Ave

        if(animal_nature == 1){
            //Natureza: Exótico

            AveExotico *ave_exotico = new AveExotico();
            Animal *animal = ave_exotico;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Ave Exotica";
        }else if(animal_nature == 2){
            //Natureza: Nativo

            AveNativo *ave_nativo = new AveNativo();
            Animal *animal = ave_nativo;
            std::cin>>(*animal);
            animal->save();

            choosed_animal = "Ave Nativa";
        }
    }

    textColor_green(choosed_animal +" adicionado(a) com sucesso!");
}


std::string chooseRole_Funcionario(){
    std::cout << "Qual o cargo do Funcionario?" << std::endl;
    std::cout << "  1 -> Tratador"<<std::endl;
    std::cout << "  2 -> Veterinario"<<std::endl;
    std::cout << "  0 -> Voltar"<<std::endl;

    std::string opt;
    std::cin>>opt;

    while((std::stoi(opt)!=0) && (std::stoi(opt)!=1) && (std::stoi(opt)!=2)){
    std::cout << "Qual o cargo do Funcionario?" << std::endl;
    std::cout << "  1 -> Tratador"<<std::endl;
    std::cout << "  2 -> Veterinario"<<std::endl;
    std::cout << "  0 -> Voltar"<<std::endl;

        std::cin>>opt;
    }

    return opt;
}

void add_Funcionario(int emp_role){
    std::string choosed_role;

    if(emp_role == 1){
        //Cargo: Tratador

        Tratador *tratador = new Tratador();
        Funcionario *funcionario = tratador;
        std::cin>>(*funcionario);
        funcionario->save();

        choosed_role = "Tratador(a)";
    }else if(emp_role == 2){
        //Cargo: Veterinario

        Veterinario *veterinario = new Veterinario();
        Funcionario *funcionario = veterinario;
        std::cin>>(*funcionario);
        funcionario->save();

        choosed_role = "Veterinario(a)";
    }

    textColor_green(choosed_role +" adicionado(a) com sucesso!");
}
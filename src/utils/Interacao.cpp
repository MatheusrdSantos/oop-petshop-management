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
    std::cout<<"1 => Nativo"<<std::endl;
    std::cout<<"2 => Exótico"<<std::endl;
    std::cin>>option;
    return option;
}
void add_Anfibio(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, std::string nome_batismo){
    int total_de_mudas;
    std::string date_stg;
    std::cout<<"Digite o total de mudas: "<<std::endl;
    std::cin>>total_de_mudas;
    std::cout<<"Digite a data da ultima muda(dd/mm/yyyy): "<<std::endl;
    std::cin>>date_stg;
    Date ultima_muda(date_stg, "/");
    std::string autorizacao_ibama;
    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    std::cin>>autorizacao_ibama;
    int tipo_origem = getOrigem();
    if(tipo_origem == 1){
        std::string uf_origem;
        std::string cidade_origem;
        
        std::cout<<"Digite a uf de origem:"<<std::endl;
        std::cin.ignore();
        std::getline(std::cin,uf_origem, '\n');

        std::cout<<"Digite a cidade de origem:"<<std::endl;
        
        std::cin.ignore();
        std::getline(std::cin,cidade_origem, '\n');

        AnfibioNativo an(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, total_de_mudas, &ultima_muda, uf_origem, cidade_origem, autorizacao_ibama);
        an.save();
    }else if (tipo_origem == 2){
        std::string pais_origem;
        std::cout<<"Digite o pais de origem:"<<std::endl;
        std::cin>>pais_origem;
        std::string cidade_origem;
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>cidade_origem;

        AnfibioExotico an(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, total_de_mudas, &ultima_muda, autorizacao_ibama, pais_origem, cidade_origem);
        an.save();
    }
}
void add_Mamifero(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, std::string nome_batismo){
    std::string cor_do_pelo;
    std::cout<<"Digite a cor do pelo: "<<std::endl;
    std::cin>>cor_do_pelo;
    std::string autorizacao_ibama;
    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    std::cin>>autorizacao_ibama;
    int tipo_origem = getOrigem();
    if(tipo_origem == 1){
        std::string uf_origem;
        std::cout<<"Digite a uf de origem:"<<std::endl;
        std::cin>>uf_origem;
        std::string cidade_origem;
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>cidade_origem;

        MamiferoNativo mam(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, cor_do_pelo, uf_origem, cidade_origem, autorizacao_ibama);
        mam.save();
    }else if (tipo_origem == 2){
        std::string pais_origem;
        std::cout<<"Digite o pais de origem:"<<std::endl;
        std::cin>>pais_origem;
        std::string cidade_origem;
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>cidade_origem;

        MamiferoExotico mam(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, cor_do_pelo, pais_origem, cidade_origem, autorizacao_ibama);
        mam.save();
    }
}
void add_Reptil(std::string nome, std::string nome_cientifico, char sexo, double tamanho, std::string dieta, std::string nome_batismo){
    int venenoso;
    std::cout<<"Digite se o animal é venenoso (0/1): "<<std::endl;
    std::cin>>venenoso;
    std::string tipo_veneno;
    std::cout<<"Digite o tipo do veneno: "<<std::endl;
    std::cin>>tipo_veneno;
    std::string autorizacao_ibama;
    std::cout<<"Digite a autorização do IBAMA:"<<std::endl;
    std::cin>>autorizacao_ibama;
    int tipo_origem = getOrigem();
    if(tipo_origem == 1){
        std::string uf_origem;
        std::cout<<"Digite a uf de origem:"<<std::endl;
        std::cin>>uf_origem;
        std::string cidade_origem;
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>cidade_origem;

        ReptilNativo rep(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, venenoso, tipo_veneno, uf_origem, cidade_origem, autorizacao_ibama);
        rep.save();
    }else if (tipo_origem == 2){
        std::string pais_origem;
        std::cout<<"Digite o pais de origem:"<<std::endl;
        std::cin>>pais_origem;
        std::string cidade_origem;
        std::cout<<"Digite a cidade de origem:"<<std::endl;
        std::cin>>cidade_origem;

        ReptilExotico rep(nome, nome_cientifico, sexo, tamanho, dieta, NULL, NULL, nome_batismo, venenoso, tipo_veneno, pais_origem, cidade_origem, autorizacao_ibama);
        rep.save();
    }
}

void identify_Animal(){
    std::string opt_animal_class = chooseClass_Animal();

    if(std::stoi(opt_animal_class) == 0){
        std::cout << std::endl;
        //run();
    }else if(std::stoi(opt_animal_class) > 0 && std::stoi(opt_animal_class) < 5){
        std::string opt_animal_nature = chooseNature_Animal();
        
        if(std::stoi(opt_animal_nature) == 0){
            std::cout << std::endl;
            //run();
        }else if(std::stoi(opt_animal_nature) == 1 || std::stoi(opt_animal_nature) == 2){
            add_Animal(std::stoi(opt_animal_class), std::stoi(opt_animal_nature));
        }else{
            std::cout << "Essa opção não existe!" << std::endl;
            //run();
        }
    }else{
        std::cout << "Essa opção não existe!" << std::endl;
        //run();
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
            add_Funcionario();
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
            std::cout << "Essa opção não existe!" << std::endl;
            break;
    }
}

void textColor_red(std::string texto){
    std::cout << "\033[1;31m" << texto << "\033[0m";
}

void textColor_yellow(std::string texto){
    std::cout << "\033[1;33m" << texto << "\033[0m";
}

void textColor_green(std::string texto){
    std::cout << "\033[1;32m" << texto << "\033[0m";
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
            delete it->second;
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
    std::string tipo_sanguineo;
    char fator_rh;
    std::string especialidade;

    if(cargo == 's'){
        return;
    }else if(cargo != 't' && cargo != 'v'){
        std::cout << "Há apenas duas opções: 't' caso queira adicionar um funcionário ou 'v' para adicionar um veterinário. Para voltar escolha 's'." << std::endl;
        add_Funcionario();
    }else{
        std::cout << "======= Dados do(a) "<< (cargo == 't' ? "Tratador(a)" : "Veterinário(a)") <<"======="<< std::endl;
        std::cout << "Nome: "<<std::endl;
        std::cin.ignore();
        std::getline (std::cin,nome, '\n');
        
        std::cout << "CPF: ";
        std::cin.ignore();
        std::getline (std::cin,cpf, '\n');

        std::cout << "Idade: ";
        std::cin >> idade;

        std::cout << "Tipo Sanguínio: ";
        std::cin >> tipo_sanguineo;

        std::cout << "Fator RH: ";
        std::cin >> fator_rh;

        std::cout << "Especialidade: ";
        // std::cin >> especialidade;
        std::cin.ignore();
        std::getline (std::cin,especialidade);

        if(cargo == 't'){
            int nivel_de_seguranca;

            std::cout << "Nível de Segurança: ";
            std::cin >> nivel_de_seguranca;

            Tratador trat(nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_de_seguranca);
            trat.save(); 

            std::cout << "Tratador adicionado!" << std::endl;        
        }else if(cargo == 'v'){
            std::string cnmv;
            std::cout << "CNMV: ";
            // std::cin >> cnmv;
            std::getline (std::cin,cnmv);

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
            delete it->second;
        }
    }
}

std::string chooseClass_Animal(){
    std::cout << "Qual a classe do Animal?" << std::endl;
    std::cout << "  1 => Anfibio"<<std::endl;
    std::cout << "  2 => Mamifero"<<std::endl;
    std::cout << "  3 => Reptil"<<std::endl;
    std::cout << "  4 => Ave"<<std::endl;
    std::cout << "  0 => Voltar"<<std::endl;

    std::string opt;
    std::cin>>opt;

    while((std::stoi(opt)!=0) && (std::stoi(opt)!=1) && (std::stoi(opt)!=2)  && (std::stoi(opt)!=3) && (std::stoi(opt)!=4)){
        std::cout << "Qual a classe do Animal?" << std::endl;
        std::cout << "  1 => Anfibio"<<std::endl;
        std::cout << "  2 => Mamifero"<<std::endl;
        std::cout << "  3 => Reptil"<<std::endl;
        std::cout << "  4 => Ave"<<std::endl;
        std::cout << "  0 => Voltar"<<std::endl;

        std::cin>>opt;
    }

    return opt;
}

std::string chooseNature_Animal(){
    std::cout << "Qual a natureza do Animal?" << std::endl;
    std::cout << "  1 => Exotico"<<std::endl;
    std::cout << "  2 => Nativo"<<std::endl;
    std::cout << "  0 => Voltar"<<std::endl;

    std::string opt;
    std::cin>>opt;

    while((std::stoi(opt)!=0) && (std::stoi(opt)!=1) && (std::stoi(opt)!=2)){
        std::cout << "Qual a natureza do Animal?" << std::endl;
        std::cout << "  1 => Exotico"<<std::endl;
        std::cout << "  2 => Nativo"<<std::endl;
        std::cout << "  0 => Voltar"<<std::endl;

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

    textColor_green("Animal, "+ choosed_animal +", adicionado com sucesso!");
}
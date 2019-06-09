#ifndef _INTERACAO_H_
#define _INTERACAO_H_

#include <iostream>
#include <string>
#include "Funcionario.h"
#include "bprinter/table_printer.h"
#include "Tratador.h"
#include "Veterinario.h"

//Inicia o programa
void run();

//Mostra o menu encaminhando o usuário para as funções do programa
void menu(int &escolha);

//Modificadores de cor de texto
void textColor_red(std::string texto);
void textColor_yellow(std::string texto);

//Imprime na tela todos os funcionários cadastrados e todas informações sobre eles
void listAll_Funcionarios();

//Adiciona um novo funcionário no banco de dados
void add_Funcionario();

#endif
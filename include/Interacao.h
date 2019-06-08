#ifndef _INTERACAO_H_
#define _INTERACAO_H_

#include <iostream>
#include <string>
#include "Funcionario.h"

//Mostra o menu encaminhando o usuário para as funções do programa
void menu(int &escolha);

//Modificadores de cor de texto
void textColor_red(std::string texto);
void textColor_yellow(std::string texto);

//Imprime na tela todos os funcionários cadastrados e todas informações sobre eles
void listAll_Funcionarios();

#endif
#ifndef _INTERACAO_H_
#define _INTERACAO_H_

#include <iostream>
#include <string>
#include "bprinter/table_printer.h"
#include "Funcionario.h"
#include "Tratador.h"
#include "Veterinario.h"
#include "Animal.h"
#include "Anfibio.h"
#include "Ave.h"
#include "Mamifero.h"
#include "Reptil.h"
#include "AnfibioNativo.h"
#include "AnfibioExotico.h"
#include "ReptilExotico.h"
#include "ReptilNativo.h"
#include "MamiferoExotico.h"
#include "MamiferoNativo.h"
#include "AveExotico.h"
#include "AveNativo.h"

/**
 * @brief Inicia o programa
 * 
 */
void run();

/**
 * @brief Mostra o menu encaminhando o usuário para as funções do programa
 * 
 * @param escolha 
 */
void menu(int &escolha);

/**
 * @brief Modificadores da cor do texto para vermelho
 * 
 * @param texto 
 */
void textColor_red(std::string texto);

/**
 * @brief Modificadores da cor do texto para amarelo
 * 
 * @param texto 
 */
void textColor_yellow(std::string texto);

/**
 * @brief Imprime na tela todos os funcionários cadastrados e todas informações sobre eles
 * 
 */
void listAll_Funcionarios();

/**
 * @brief Adiciona um novo funcionário no banco de dados
 * 
 */
void add_Funcionario();

/**
 * @brief Imprime na tela todos os animais cadastrados e todas informações sobre eles
 * 
 */
void listAll_Animais();

#endif
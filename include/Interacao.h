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
#include "exceptions/NonIntegerArgument.h"

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
 * @brief Modificadores da cor do texto para green
 * 
 * @param texto 
 */
void textColor_green(std::string texto);

/**
 * @brief Identifica, por meio do usuário, quais as características do funcionário a ser cadastrado
 * 
 */
void identify_Funcionario();

/**
 * @brief Imprime na tela todos os funcionários cadastrados e todas informações sobre eles
 * 
 */
void listAll_Funcionarios();

/**
 * @brief Imprime na tela os cargos possíveis para um funcionário para o usuário selecionar
 * 
 * @return std::string
 */
std::string chooseRole_Funcionario();

/**
 * @brief Adiciona um novo funcionário no banco de dados
 * 
 * @param emp_role
 */
void add_Funcionario(int emp_role);

/**
 * @brief Remove um funcionário que já foi comercializado
 * 
 */
void remove_Funcionario();

/**
 * @brief Lista todos os funcionários de um(a) determinado(a) cargo/funcao
 * 
 */
void listByRole_Funcionario();

/**
 * @brief Identifica, por meio do usuário, quais as características do animal a ser cadastrado
 * 
 */
void identify_Animal();

/**
 * @brief Imprime na tela todos os animais cadastrados e todas informações sobre eles
 * 
 */
void listAll_Animais();

/**
 * @brief Imprime na tela as classes dos animais para o usuário selecionar
 * 
 * @return std::string
 */
std::string chooseClass_Animal();

/**
 * @brief Imprime na tela as naturezas dos animais para o usuário selecionar
 * 
 * @return std::string
 */
std::string chooseNature_Animal();

/**
 * @brief Recebe os dados um animal e os adicionas ao banco de dados
 * 
 * @param animal_class
 * @param animal_nature
 */

void add_Animal(int animal_class, int animal_nature);

/**
 * @brief Remove um animal que já foi comercializado
 * 
 */
void remove_Animal();

/**
 * @brief Lista todos os animais de uma determinada classe
 * 
 */
void listByClass_Animal();

#endif
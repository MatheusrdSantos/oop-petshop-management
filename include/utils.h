/**
* @file utils.h
* @brief Classe em C++ para definição de funções de utilidades variadas, como: conversão de tipos, modelagem de dados e efetuação de oparações.
* @author AMD
* @date Atualizado por Matheus Santos em 07/06/2019
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "CSVparser.hpp"

/**
 * @brief Retorna o resultado da comparação de duas strings passado o símbolo de comparação por parâmetro.
 * 
 * @param value1 
 * @param value2 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool compare(std::string* value1, std::string* value2, std::string* symbol);

/**
 * @brief Retorna o resultado da comparação de dois inteiros passado o símbolo de comparação por parâmetro.
 * 
 * @param value1 
 * @param value2 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool compare(int value1, int value2, std::string* symbol);

/**
 * @brief Constroi uma string no padrão csv, com ';' como separados, baseado em um vetor de strings representando as colunas do cabeçalho.
 * 
 * @param header 
 * @return std::string 
 */
std::string buildHeaderString(std::vector<std::string>* header);

/**
 * @brief Constroi uma string no padrão csv, com ';' como separados, baseado em uma Row representando os valores contidos em uma linha do csv.
 * 
 * @param row 
 * @return std::string 
 */
std::string buildRowString(csv::Row* row);

/**
 * @brief Constroi um vetor de inteiros representando dia, mes e ano, com base em uma string e um separador.
 * 
 * @param date 
 * @param separator 
 * @return std::vector<int>* 
 */
std::vector<int>* splitStringDate(std::string date, std::string separator);
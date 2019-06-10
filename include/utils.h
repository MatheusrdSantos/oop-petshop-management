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
 * @brief 
 * 
 * @param header 
 * @return std::string 
 */
std::string buildHeaderString(std::vector<std::string>* header);

/**
 * @brief 
 * 
 * @param row 
 * @return std::string 
 */
std::string buildRowString(csv::Row* row);

/**
 * @brief 
 * 
 * @param date 
 * @param separator 
 * @return std::vector<int>* 
 */
std::vector<int>* splitStringDate(std::string date, std::string separator);
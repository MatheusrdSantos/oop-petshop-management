#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "CSVparser.hpp"
bool compare(std::string* value1, std::string* value2, std::string* symbol);
std::string buildHeaderString(std::vector<std::string>* header);
std::string buildRowString(csv::Row* row);
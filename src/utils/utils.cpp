#include "utils.h"

bool compare(std::string* value1, std::string* value2, std::string* symbol){
    if((*symbol) == "=="){
        if((*value1) == (*value2)){
            return true;
        }
    }else if((*symbol) == "!="){
        if((*value1) != (*value2)){
            return true;
        }
    }
    return false;
}

std::string buildHeaderString(std::vector<std::string>* header){
    std::stringstream ss;
    int n_columns = header->size();
    for (int i = 0; i < n_columns; i++)
    {
        if(i == n_columns-1){
            ss<<header->at(i)<<std::endl;
        }else{
            ss<<header->at(i)<<";";
        }
    }
    std::string s = ss.str();
    return s;    
}

std::string buildRowString(csv::Row* row){
    std::stringstream ss;
    int n_columns = row->size();
    for (int i = 0; i < n_columns; i++)
    {
        if(i == n_columns-1){
            ss<<(*row)[i]<<std::endl;
        }else{
            ss<<(*row)[i]<<";";
        }
    }
    std::string s = ss.str();
    return s; 
}
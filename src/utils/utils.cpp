#include "../../include/utils.h"
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
bool compare(int value1, int value2, std::string* symbol){
    if((*symbol) == "=="){
        if(value1 == value2){
            return true;
        }
    }else if((*symbol) == "!="){
        if(value1 != value2){
            return true;
        }
    }else if((*symbol) == ">"){
        if(value1>value2){
            return true;
        }
    }else if((*symbol) == "<"){
        if(value1<value2){
            return true;
        }
    }else if((*symbol) == "<="){
        if(value1<=value2){
            return true;
        }
    }else if((*symbol) == ">="){
        if(value1>=value2){
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

std::vector<int>* splitStringDate(std::string date, std::string separator){
    std::vector<int>* dates = new std::vector<int>();
    
    int pos = date.find(separator);
    int day = std::stoi(date.substr(0, pos));
    date.erase(0, pos+separator.length());

    pos = date.find(separator);
    int month = std::stoi(date.substr(0, pos));
    date.erase(0, pos+separator.length());

    int year = std::stoi(date);

    dates->push_back(day);
    dates->push_back(month);
    dates->push_back(year);

    return dates;
}
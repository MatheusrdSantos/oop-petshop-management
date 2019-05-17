/* 
Class: ModelDAO
Author: Arnaldo Barbosa    
*/
#ifndef _MODELDAO_H_
#define _MODELDAO_H_

#include<string>
#include<list>

#include"CRUD.h"
#include "CSVparser.hpp"

template<class T>
class ModelDAO : public CRUD{


    protected:
    
    public:
        ModelDAO();
        ~ModelDAO();
        
        /*
        *   Create
        */
        bool insert(T model);

        /*
        *   Read
        */
        ModelDAO find(int id);
        std::list<ModelDAO> where(std::string expression); 
        static csv::Parser readTable(std::string filePath);

        /*
        *   Update
        */
       bool update(std::string expression);

        /*
        *   Delete
        */
       bool remove(std::string expression);
};

csv::Parser ModelDAO<T>::readTable(std::string filePath){
    try
    {
        csv::Parser file = csv::Parser(filePath);
        return file;
    }
    catch (csv::Error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}  
#endif
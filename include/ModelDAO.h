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
class ModelDAO{


    protected:
    
    public:
        /*
        *   Create
        */
        bool save();

        /*
        *   Read
        */
        ModelDAO find(int id);
        std::list<ModelDAO> where(std::string expression); 
        static csv::Parser readTable(){
            try{
                csv::Parser file = csv::Parser(T::filePath, csv::DataType(0), ';');
                return file;
            }catch (csv::Error &e){
                std::cerr << e.what() << std::endl;
                return;
            }catch (...){
                std::cerr << "Erro desconhecido na leitura."<<std::endl;
            }
        };

        /*
        *   Update
        */
       bool update(std::string expression);

        /*
        *   Delete
        */
       bool remove(std::string expression);
};
#endif
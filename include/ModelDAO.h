/* 
Class: ModelDAO
Author: Arnaldo Barbosa    
*/
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include<string>
#include<list>

#include"CRUD.h"

template<class T>
class ModelDAO : public CRUD{

    protected:
        std::string filePath;
    
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
        std::list<ModelDAO> all(); 
        std::list<ModelDAO> where(std::string expression); 

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
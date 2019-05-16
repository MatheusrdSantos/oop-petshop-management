#ifndef _CRUD_H_
#define _CRUD_H_

#include<list>
#include<string>

#include"ModelDAO.h"

template<class T>
class CRUD{
    public:
        /*
        *   Create
        */
        virtual bool insert(T model);

        /*
        *   Read
        */
        virtual T find(int id);
        virtual T find(T model) = 0;
        virtual std::list<T> all(); 
        virtual std::list<T> where(std::string expression); 

        /*
        *   Update
        */
       virtual bool update(T model) = 0;
       virtual bool update(std::string expression);

        /*
        *   Delete
        */
       virtual bool remove(T model) = 0;
       virtual bool remove(std::string expression);

};
#endif
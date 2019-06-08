/* 
Class: ModelDAO
Author: Arnaldo Barbosa    
*/
#ifndef _MODELDAO_H_
#define _MODELDAO_H_

#include<string>
#include<list>
#include<fstream>

#include"CRUD.h"
#include "CSVparser.hpp"

template<class T>
class ModelDAO{

    private:
        std::string autoincrement_table_path = "./storage/autoincrement.csv";
    protected:

    public:
        /*
        *   Create
        */

        /*
        *   Read
        */
        ModelDAO find(int id);
        std::list<ModelDAO> where(std::string expression); 
        static csv::Parser readTable(){
            csv::Parser file = csv::Parser(T::filePath, csv::DataType(0), ';');
            return file;
        };


        static int getColumnIndex(std::vector<std::string>* columns, std::string* columnName){
            for (unsigned i = 0; i < columns->size(); i++)
            {
                if(columns->at(i) == (*columnName)){
                    return i;
                }
            }
            return -1;
        }    
        /*
        *   Update
        */
       bool update(std::string expression);

        /*
        *   Delete
        */
       bool remove(std::string expression);

       int getTableIncrementId(std::string table_name){
           csv::Parser file = csv::Parser(autoincrement_table_path, csv::DataType(0), ';');
           int n_rows = file.rowCount();
           for (int i = 0; i<n_rows;i++){
               if(file[i][0] == table_name){
                   return std::stoi(file[i][1]);
               }
           }
           return -1;
       };
       bool updateAutoIncrement(std::string table_name){
           csv::Parser file = csv::Parser(autoincrement_table_path, csv::DataType(0), ';');
           int n_rows = file.rowCount();

            std::fstream write_file;
            write_file.open(autoincrement_table_path, std::ios::out);
            if(!write_file.is_open()){
                return false;
            }
            write_file<<file.getHeader()[0]<<';'<<file.getHeader()[1]<<std::endl;

            for (int i = 0; i<n_rows;i++){
                if(file[i][0] == table_name){
                    int n = std::stoi(file[i][1])+1;
                    std::cout<<file[i][0]<<"->"<<n<<std::endl;
                    write_file<<file[i][0]<<';'<<n<<std::endl;
                }else{
                    write_file<<file[i][0]<<';'<<file[i][1]<<std::endl;
                }
            }
            write_file.close();
            return true;
       };
};
#endif
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
        std::string autoincrement_table_path = "./storage/autoincrement.csv"; /*< Define a tabela de Auto incremento, que armazena o próximo id do objeto que será armazenado no banco.*/
    protected:

    public:
        /*
        *   Create
        */

        /*
        *   Read
        */
        ModelDAO find(int id);

        /**
         * @brief Retorna uma lista dos objetos de uma tabela.
         * 
         * @param expression 
         * @return std::list<ModelDAO> 
         */
        std::list<ModelDAO> where(std::string expression); 
        static csv::Parser readTable(){
            csv::Parser file = csv::Parser(T::filePath, csv::DataType(0), ';');
            return file;
        };
 
        /*
        *   Update
        */
       bool update(std::string expression);

        /*
        *   Delete
        */
       bool remove(std::string expression);

       /**
        * @brief Retorna o id de incremento dada um nome de tabela por parâmetro.
        * 
        * @param table_name 
        * @return int 
        */
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
       
       /**
        * @brief Incrementa e atualiza o id na tabela de auto incremento.
        * 
        * @param table_name 
        * @return true 
        * @return false 
        */
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
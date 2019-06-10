/**
* @file Date.h
* @brief Classe em C++ para definição de Datas.
* @author Bernt A Oedegaard
* @date Atualizado por Arnaldo Souza em 07/06/2019
* @sa http://finance.bi.no/~bernt/gcc_prog/doc_date.pdf
*/

// File: Date.h
// author: Bernt A Oedegaard.
#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "utils.h"


class Date{
    protected:
        int year_; /*< Define o ano da data  */
        int month_; /*< Define o mês da data  */
        int day_; /*< Define o dia da data  */
    public:

        /**
         * @brief Constrói uma nova data
         * 
         */
        Date();

        /**
         * @brief Constrói uma nova data
         * 
         * @param date 
         */
        Date(Date& date);

        /**
         * @brief Constrói uma nova data
         * 
         * @param d 
         * @param m 
         * @param y 
         */
        Date(const int& d, const int& m, const int& y);

        /**
         * @brief Constrói uma nova data
         * 
         * @param date 
         * @param separator 
         */
        Date(std::string date, std::string separator);

        /**
         * @brief Retorna true se a data for válida.
         * 
         * @return true 
         * @return false 
         */
        bool valid(void) const;

        /**
         * @brief Retorna o dia da data.
         * 
         * @return int 
         */
        int day() const;

        /**
         * @brief Retorna o mês da data.
         * 
         * @return int 
         */
        int month() const;

        /**
         * @brief Retorna o ano da data.
         * 
         * @return int 
         */
        int year() const;

        /**
         * @brief Define o dia da data
         * 
         * @param day 
         */
        void set_day(const int& day);

        /**
         * @brief Define o mês da data
         * 
         * @param month 
         */
        void set_month(const int& month);

        /**
         * @brief Define o ano da data
         * 
         * @param year 
         */
        void set_year(const int& year);

        /**
         * @brief Adiciona um dia à data.
         * 
         * @return Date 
         */
        Date operator ++();

        /**
         * @brief Adiciona um dia à data.
         * 
         * @return Date 
         */
        Date operator ++(int);

        /**
         * @brief Remove um dia da data.
         * 
         * @return Date 
         */
        Date operator --();

        /**
         * @brief Remove um dia da data.
         * 
         * @return Date 
         */
        Date operator --(int);

        /**
         * @brief Remove x dias da data.
         * 
         * @return Date 
         */
        Date operator - (int);

        /**
         * @brief Adiciona x dias à data.
         * 
         * @return Date 
         */
        Date operator + (int);
};

/**
 * @brief Retorna true se duas datas são iguais
 * 
 * @return true 
 * @return false 
 */
bool operator == (const Date&, const Date&);

/**
 * @brief Compara se duas datas são diferentes (true para sim e false para não).
 * 
 * @return true 
 * @return false 
 */
bool operator != (const Date&, const Date&);

/**
 * @brief Retorna true se uma data vem antes da outra
 * 
 * @return true 
 * @return false 
 */
bool operator < (const Date&, const Date&);

/**
 * @brief Retorna true se uma data vem depois da outra
 * 
 * @return true 
 * @return false 
 */
bool operator > (const Date&, const Date&);

/**
 * @brief Retorna true se uma data vem antes ou é igual à outra
 * 
 * @return true 
 * @return false 
 */
bool operator <=(const Date&, const Date&);

/**
 * @brief Retorna true se uma data vem depois ou é igual à outra
 * 
 * @return true 
 * @return false 
 */
bool operator >=(const Date&, const Date&);

/**
 * @brief Saída para print da data.
 * 
 * @param os 
 * @param d 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& os, const Date& d);

#endif

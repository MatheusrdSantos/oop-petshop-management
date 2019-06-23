/**
* @file exportar.h
* @brief Define o namespace 'exportar' e um conjunto de funções para permitir a exportação dos dados do projeto
* @author Matheus Santos
* @date Atualizado por Matheus Santos em 22/06/2019
* @sa https://github.com/MatheusrdSantos/oop-petshop-management/blob/master/include/exportar.h
*/
#ifndef _EXPORTARLIB_H_
#define _EXPORTARLIB_H_
#include <map>
#include <vector>
#include "Animal.h"
namespace exportar
{
    class Filter{
        public:
            std::string m_key; /*< Chave que se refere à coluna na tabela de consulta*/
            std::string m_value; /*< Valor referente ao registro da coluna representada pelo campo m_key*/
        Filter();
        Filter(std::string key, std::string value);
        ~Filter(){};
    };

    /**
     * @brief Constroi um vetor de filtros com base nos argumentos passados por linha de comando
     * 
     * @param argc contador de parametros
     * @param argv vetor de parametros
     * @return std::vector<Filter>
     */
    std::vector<Filter> buildFilters(int argc, char const *argv[]);

    /**
     * @brief Recupera objetos da classe Animal com base em um vetor de Filtro passado
     * 
     * @param filters Ponteiro para um std::vector de Filtro
     * @return std::multimap<std::string, Animal*> Multimap contendo os animais
     */
    std::multimap<std::string, Animal*> getAnimalByFilters(std::vector<Filter> *filters = NULL);

    /**
     * @brief Verifica se um dado Animal está tem as propriedades do filtro passado
     * 
     * @param filters Ponteiro para um std::vector de Filtro
     * @param animal Ponteiro para um Animal
     * @return bool Retorna true caso o animal tenha as propriedades do filtro e false caso contrário
     */
    bool matchFilter(std::vector<Filter> *filters, Animal *animal);

    /**
     * @brief Escreve todos os animais de um multimap em um arquivo
     * 
     * @param animals Multimap contendo os animais
     * @param filename O nome do arquivo de escrita
     * @return void
     */
    void saveAnimals(std::multimap<std::string, Animal*> animals, std::string filename);
} // namespace exportar


#endif
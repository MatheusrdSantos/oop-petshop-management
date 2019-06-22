#include "../../include/exportar.h"
#include "../../include/Animal.h"
namespace exportar
{
    Filter::Filter(){
        
    }
    
    Filter::Filter(std::string key, std::string value){
        m_key = key;
        m_value = value;
    }

    bool matchFilter(std::vector<Filter> *filters, Animal *animal){
        bool match = true;
        for(auto it: (*filters)){
            if(it.m_key == "classe"){
                if(it.m_value != animal->getClasse()){
                    match = false;
                }
            }else if(it.m_key == "veterinario"){
                if(animal->getVeterinario()){
                    if(it.m_value != animal->getVeterinario()->getNome()){
                        match = false;
                    }
                }else{
                    match = false;
                }
            }else if(it.m_key == "tratador"){
                if(animal->getTratador()){
                    if(it.m_value != animal->getTratador()->getNome()){
                        match = false;
                    }
                }else{
                    match = false;
                }
            }
            if(!match){
                return match;
            }
        }

        return match;
    }

    std::multimap<std::string, Animal*> getAnimalByFilters(std::vector<Filter> *filters){
        std::multimap<std::string, Animal*> animals = Animal::all();
        for (auto it=animals.begin(); it!=animals.end(); ++it){
            if(!matchFilter(filters, it->second)){
                animals.erase(it);
            }
        }
        return animals;
    }

    void saveAnimals(std::multimap<std::string, Animal*> animals, std::string filename){
        std::ofstream file;
        file.open(filename, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo
        std::string header = Animal::getTableHeaderString();
        file<<header;
        if(file.is_open()){
            for (auto it=animals.begin(); it!=animals.end(); ++it){
                file<<it->second->printInFile(it->second->getId());
            }
            file.close();
        }
    }
} // namespace exportar

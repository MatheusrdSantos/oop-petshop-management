#include "ModelDAO.h"

bool ModelDAO::save(){
    std::ofstream file;
    file.open(this->pathToFile, std::ios::app); //app significa Append, ou seja, escrita no fim do arquivo

    if(file.is_open()){
        std::cout<<"Saving..."<<std::endl;
        file<<this->getStringTemplateToSave();
    }else{
        std::cerr<<"Couldn't open the file!"<<std::endl;
    }

    file.close();
    return true;
}
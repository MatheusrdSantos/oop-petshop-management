#include "../include/PetFera.h"
#include "../include/Animal.h"
#include "../include/AnfibioExotico.h"
#include "../include/AnfibioNativo.h"
#include "../include/MamiferoExotico.h"
#include "../include/MamiferoNativo.h"
#include "../include/ReptilExotico.h"
#include "../include/ReptilNativo.h"
#include "../include/AveExotico.h"
#include "../include/AveNativo.h"
#include "../include/Tratador.h"
#include "../include/Funcionario.h"
#include "../include/Mamifero.h"
#include "../include/Anfibio.h"
#include <string>
#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    PetFera* app = new PetFera();
    app->run();
    return 0;
}
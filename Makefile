OBJS_DIR	:= build
LIB_DIR := lib
OBJS	= $(addprefix $(OBJS_DIR)/, main.o Anfibio.o AnfibioExotico.o AnfibioNativo.o Animal.o AnimalExotico.o AnimalNativo.o AnimalSilvestre.o Ave.o AveExotico.o AveNativo.o CSVparser.o Date.o Funcionario.o Mamifero.o MamiferoExotico.o MamiferoNativo.o ModelDAO.o Reptil.o ReptilExotico.o ReptilNativo.o Tratador.o Veterinario.o utils.o PetFera.o InvalidBloodType.o NonIntegerArgument.o InvalidSecurityLevel.o)

OBJS_LIB	= $(addprefix $(OBJS_DIR)/$(LIB_DIR)/, Anfibio.o AnfibioExotico.o AnfibioNativo.o Animal.o AnimalExotico.o AnimalNativo.o AnimalSilvestre.o Ave.o AveExotico.o AveNativo.o CSVparser.o Date.o Funcionario.o Mamifero.o MamiferoExotico.o MamiferoNativo.o ModelDAO.o Reptil.o ReptilExotico.o ReptilNativo.o Tratador.o Veterinario.o utils.o exportar.o main_export.o)

ANIMALS_OBJS = main.o Anfibio.o AnfibioExotico.o AnfibioNativo.o Animal.o AnimalExotico.o AnimalNativo.o AnimalSilvestre.o Ave.o AveExotico.o AveNativo.o CSVparser.o Mamifero.o MamiferoExotico.o MamiferoNativo.o ModelDAO.o Reptil.o ReptilExotico.o ReptilNativo.o 
SOURCE	= src/main.cpp src/classes/Anfibio.cpp src/classes/AnfibioExotico.cpp src/classes/AnfibioNativo.cpp src/classes/Animal.cpp src/classes/AnimalExotico.cpp src/classes/AnimalNativo.cpp src/classes/AnimalSilvestre.cpp src/classes/Ave.cpp src/classes/AveExotico.cpp src/classes/AveNativo.cpp src/classes/CSVparser.cpp src/classes/Date.cpp src/classes/Funcionario.cpp src/classes/Mamifero.cpp src/classes/MamiferoExotico.cpp src/classes/MamiferoNativo.cpp src/classes/ModelDAO.cpp src/classes/Reptil.cpp src/classes/ReptilExotico.cpp src/classes/ReptilNativo.cpp src/classes/Tratador.cpp src/classes/Veterinario.cpp src/utils/utils.cpp src/classes/PetFera.cpp
LIB_SOURCE	= src/classes/Anfibio.cpp src/classes/AnfibioExotico.cpp src/classes/AnfibioNativo.cpp src/classes/Animal.cpp src/classes/AnimalExotico.cpp src/classes/AnimalNativo.cpp src/classes/AnimalSilvestre.cpp src/classes/Ave.cpp src/classes/AveExotico.cpp src/classes/AveNativo.cpp src/classes/CSVparser.cpp src/classes/Date.cpp src/classes/Funcionario.cpp src/classes/Mamifero.cpp src/classes/MamiferoExotico.cpp src/classes/MamiferoNativo.cpp src/classes/ModelDAO.cpp src/classes/Reptil.cpp src/classes/ReptilExotico.cpp src/classes/ReptilNativo.cpp src/classes/Tratador.cpp src/classes/Veterinario.cpp src/utils/utils.cpp src/utils/exportar.cpp src/utils/main_export.cpp
HEADER	= include/Anfibio.h include/AnfibioExotico.h include/AnfibioNativo.h include/Animal.h include/AnimalExotico.h include/AnimalNativo.h include/AnimalSilvestre.h include/Ave.h include/AveExotico.h include/AveNativo.h include/CRUD.h include/CSVparser.hpp include/Date.h include/Funcionario.h include/PetFera.h include/Mamifero.h include/MamiferoExotico.h include/MamiferoNativo.h include/ModelDAO.h include/Reptil.h include/ReptilExotico.h include/ReptilNativo.h include/Tratador.h include/utils.h include/Veterinario.h include/exceptions/InvalidBloodType.h include/exceptions/NonIntegerArgument.h include/exceptions/InvalidSecurityLevel.h include/exportar.h
OUT	= $(OBJS_DIR)/exec.o
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -pedantic -I include/ -O0 -ansi
CC_11 = -std=c++11

all: $(OBJS) 
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	make clean
animals: $(ANIMALS_OBJS)
	$(CC) -g $(ANIMALS_OBJS) -o $(OUT) $(LFLAGS)
	make clean

build/InvalidBloodType.o: src/exceptions/InvalidBloodType.cpp
	$(CC) $(FLAGS) src/exceptions/InvalidBloodType.cpp -std=c++11 -o build/InvalidBloodType.o

build/NonIntegerArgument.o: src/exceptions/NonIntegerArgument.cpp
	$(CC) $(FLAGS) src/exceptions/NonIntegerArgument.cpp -std=c++11 -o build/NonIntegerArgument.o

build/InvalidSecurityLevel.o: src/exceptions/InvalidSecurityLevel.cpp
	$(CC) $(FLAGS) src/exceptions/InvalidSecurityLevel.cpp -std=c++11 -o build/InvalidSecurityLevel.o

build/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++11 -o build/main.o

build/utils.o: src/utils/utils.cpp
	$(CC) $(FLAGS) src/utils/utils.cpp -std=c++11 -o build/utils.o

build/PetFera.o: src/classes/PetFera.cpp
	$(CC) $(FLAGS) src/classes/PetFera.cpp -std=c++11 -o build/PetFera.o

build/Anfibio.o: src/classes/Anfibio.cpp
	$(CC) $(FLAGS) src/classes/Anfibio.cpp -std=c++11 -o build/Anfibio.o

build/AnfibioExotico.o: src/classes/AnfibioExotico.cpp
	$(CC) $(FLAGS) src/classes/AnfibioExotico.cpp -std=c++11 -o build/AnfibioExotico.o

build/AnfibioNativo.o: src/classes/AnfibioNativo.cpp
	$(CC) $(FLAGS) src/classes/AnfibioNativo.cpp -std=c++11 -o build/AnfibioNativo.o

build/Animal.o: src/classes/Animal.cpp
	$(CC) $(FLAGS) src/classes/Animal.cpp -std=c++11 -o build/Animal.o

build/AnimalExotico.o: src/classes/AnimalExotico.cpp
	$(CC) $(FLAGS) src/classes/AnimalExotico.cpp -std=c++11 -o build/AnimalExotico.o

build/AnimalNativo.o: src/classes/AnimalNativo.cpp
	$(CC) $(FLAGS) src/classes/AnimalNativo.cpp -std=c++11 -o build/AnimalNativo.o

build/AnimalSilvestre.o: src/classes/AnimalSilvestre.cpp
	$(CC) $(FLAGS) src/classes/AnimalSilvestre.cpp -std=c++11 -o build/AnimalSilvestre.o

build/Ave.o: src/classes/Ave.cpp
	$(CC) $(FLAGS) src/classes/Ave.cpp -std=c++11 -o build/Ave.o

build/AveExotico.o: src/classes/AveExotico.cpp
	$(CC) $(FLAGS) src/classes/AveExotico.cpp -std=c++11 -o build/AveExotico.o

build/AveNativo.o: src/classes/AveNativo.cpp
	$(CC) $(FLAGS) src/classes/AveNativo.cpp -std=c++11 -o build/AveNativo.o

build/CSVparser.o: src/classes/CSVparser.cpp
	$(CC) $(FLAGS) src/classes/CSVparser.cpp -std=c++11 -o build/CSVparser.o

build/Date.o: src/classes/Date.cpp
	$(CC) $(FLAGS) src/classes/Date.cpp -std=c++11 -o build/Date.o

build/Funcionario.o: src/classes/Funcionario.cpp
	$(CC) $(FLAGS) src/classes/Funcionario.cpp -std=c++11 -o build/Funcionario.o

build/Mamifero.o: src/classes/Mamifero.cpp
	$(CC) $(FLAGS) src/classes/Mamifero.cpp -std=c++11 -o build/Mamifero.o

build/MamiferoExotico.o: src/classes/MamiferoExotico.cpp
	$(CC) $(FLAGS) src/classes/MamiferoExotico.cpp -std=c++11 -o build/MamiferoExotico.o

build/MamiferoNativo.o: src/classes/MamiferoNativo.cpp
	$(CC) $(FLAGS) src/classes/MamiferoNativo.cpp -std=c++11 -o build/MamiferoNativo.o

build/ModelDAO.o: src/classes/ModelDAO.cpp
	$(CC) $(FLAGS) src/classes/ModelDAO.cpp -std=c++11 -o build/ModelDAO.o

build/Reptil.o: src/classes/Reptil.cpp
	$(CC) $(FLAGS) src/classes/Reptil.cpp -std=c++11 -o build/Reptil.o

build/ReptilExotico.o: src/classes/ReptilExotico.cpp
	$(CC) $(FLAGS) src/classes/ReptilExotico.cpp -std=c++11 -o build/ReptilExotico.o

build/ReptilNativo.o: src/classes/ReptilNativo.cpp
	$(CC) $(FLAGS) src/classes/ReptilNativo.cpp -std=c++11 -o build/ReptilNativo.o

build/Tratador.o: src/classes/Tratador.cpp
	$(CC) $(FLAGS) src/classes/Tratador.cpp -std=c++11 -o build/Tratador.o

build/Veterinario.o: src/classes/Veterinario.cpp
	$(CC) $(FLAGS) src/classes/Veterinario.cpp -std=c++11 -o build/Veterinario.o


#linux: exportar.so exportar

windows: exportar.dll exportar.exe

# linux
exportar.so:  $(LIB_SOURCE)
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Anfibio.cpp -o build/lib/Anfibio.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AnfibioExotico.cpp -o build/lib/AnfibioExotico.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AnfibioNativo.cpp -o build/lib/AnfibioNativo.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Animal.cpp -o build/lib/Animal.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AnimalExotico.cpp -o build/lib/AnimalExotico.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AnimalNativo.cpp -o build/lib/AnimalNativo.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AnimalSilvestre.cpp -o build/lib/AnimalSilvestre.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Ave.cpp -o build/lib/Ave.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AveExotico.cpp -o build/lib/AveExotico.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/AveNativo.cpp  -o build/lib/AveNativo.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/CSVparser.cpp -o build/lib/CSVparser.o
	
	
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Date.cpp -o build/lib/Date.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Funcionario.cpp -o build/lib/Funcionario.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Mamifero.cpp -o build/lib/Mamifero.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/MamiferoExotico.cpp -o build/lib/MamiferoExotico.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/MamiferoNativo.cpp -o build/lib/MamiferoNativo.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/ModelDAO.cpp -o build/lib/ModelDAO.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Reptil.cpp -o build/lib/Reptil.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/ReptilExotico.cpp -o build/lib/ReptilExotico.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/ReptilNativo.cpp -o build/lib/ReptilNativo.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Tratador.cpp -o build/lib/Tratador.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/classes/Veterinario.cpp -o build/lib/Veterinario.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/utils/utils.cpp -o build/lib/utils.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/utils/exportar.cpp -o build/lib/exportar.o
	$(CC) $(LFLAGS) $(CC_11) -Wall -fPIC -c src/utils/main_export.cpp -o build/lib/main_export.o

	$(CC) $(CC_11) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJS_LIB)
	@echo "biblioteca dinamica criada"

exportar: 
	$(CC) -Wall $(LFLAGS) $(CC_11) src/utils/main_export.cpp -g $(LIB_DIR)/exportar.so -o $(OBJS_DIR)/$@ 

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_LIB)
run:
	./build/exec.o
debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
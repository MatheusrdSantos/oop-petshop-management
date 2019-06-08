OBJS	= src/main.o src/classes/Anfibio.o src/classes/AnfibioExotico.o src/classes/AnfibioNativo.o src/classes/Animal.o src/classes/AnimalExotico.o src/classes/AnimalNativo.o src/classes/AnimalSilvestre.o src/classes/Ave.o src/classes/AveExotico.o src/classes/AveNativo.o src/classes/CSVparser.o src/classes/Data.o src/classes/Funcionario.o src/classes/Mamifero.o src/classes/MamiferoExotico.o src/classes/MamiferoNativo.o src/classes/ModelDAO.o src/classes/Reptil.o src/classes/ReptilExotico.o src/classes/ReptilNativo.o src/classes/Tratador.o src/classes/Veterinario.o
SOURCE	= src/main.cpp src/classes/Anfibio.cpp src/classes/AnfibioExotico.cpp src/classes/AnfibioNativo.cpp src/classes/Animal.cpp src/classes/AnimalExotico.cpp src/classes/AnimalNativo.cpp src/classes/AnimalSilvestre.cpp src/classes/Ave.cpp src/classes/AveExotico.cpp src/classes/AveNativo.cpp src/classes/CSVparser.cpp src/classes/Data.cpp src/classes/Funcionario.cpp src/classes/Mamifero.cpp src/classes/MamiferoExotico.cpp src/classes/MamiferoNativo.cpp src/classes/ModelDAO.cpp src/classes/Reptil.cpp src/classes/ReptilExotico.cpp src/classes/ReptilNativo.cpp src/classes/Tratador.cpp src/classes/Veterinario.cpp
HEADER	= include/Anfibio.h include/AnfibioExotico.h include/AnfibioNativo.h include/Animal.h include/AnimalExotico.h include/AnimalNativo.h include/AnimalSilvestre.h include/Ave.h include/AveExotico.h include/AveNativo.h include/CRUD.h include/CSVparser.hpp include/Data.h include/Funcionario.h include/Interacao.h include/Mamifero.h include/MamiferoExotico.h include/MamiferoNativo.h include/ModelDAO.h include/Reptil.h include/ReptilExotico.h include/ReptilNativo.h include/Tratador.h include/utils.h include/Veterinario.h
OUT	= myproject1
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

src/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++11

src/classes/Anfibio.o: src/classes/Anfibio.cpp
	$(CC) $(FLAGS) src/classes/Anfibio.cpp -std=c++11

src/classes/AnfibioExotico.o: src/classes/AnfibioExotico.cpp
	$(CC) $(FLAGS) src/classes/AnfibioExotico.cpp -std=c++11

src/classes/AnfibioNativo.o: src/classes/AnfibioNativo.cpp
	$(CC) $(FLAGS) src/classes/AnfibioNativo.cpp -std=c++11

src/classes/Animal.o: src/classes/Animal.cpp
	$(CC) $(FLAGS) src/classes/Animal.cpp -std=c++11

src/classes/AnimalExotico.o: src/classes/AnimalExotico.cpp
	$(CC) $(FLAGS) src/classes/AnimalExotico.cpp -std=c++11

src/classes/AnimalNativo.o: src/classes/AnimalNativo.cpp
	$(CC) $(FLAGS) src/classes/AnimalNativo.cpp -std=c++11

src/classes/AnimalSilvestre.o: src/classes/AnimalSilvestre.cpp
	$(CC) $(FLAGS) src/classes/AnimalSilvestre.cpp -std=c++11

src/classes/Ave.o: src/classes/Ave.cpp
	$(CC) $(FLAGS) src/classes/Ave.cpp -std=c++11

src/classes/AveExotico.o: src/classes/AveExotico.cpp
	$(CC) $(FLAGS) src/classes/AveExotico.cpp -std=c++11

src/classes/AveNativo.o: src/classes/AveNativo.cpp
	$(CC) $(FLAGS) src/classes/AveNativo.cpp -std=c++11

src/classes/CSVparser.o: src/classes/CSVparser.cpp
	$(CC) $(FLAGS) src/classes/CSVparser.cpp -std=c++11

src/classes/Data.o: src/classes/Data.cpp
	$(CC) $(FLAGS) src/classes/Data.cpp -std=c++11

src/classes/Funcionario.o: src/classes/Funcionario.cpp
	$(CC) $(FLAGS) src/classes/Funcionario.cpp -std=c++11

src/classes/Mamifero.o: src/classes/Mamifero.cpp
	$(CC) $(FLAGS) src/classes/Mamifero.cpp -std=c++11

src/classes/MamiferoExotico.o: src/classes/MamiferoExotico.cpp
	$(CC) $(FLAGS) src/classes/MamiferoExotico.cpp -std=c++11

src/classes/MamiferoNativo.o: src/classes/MamiferoNativo.cpp
	$(CC) $(FLAGS) src/classes/MamiferoNativo.cpp -std=c++11

src/classes/ModelDAO.o: src/classes/ModelDAO.cpp
	$(CC) $(FLAGS) src/classes/ModelDAO.cpp -std=c++11

src/classes/Reptil.o: src/classes/Reptil.cpp
	$(CC) $(FLAGS) src/classes/Reptil.cpp -std=c++11

src/classes/ReptilExotico.o: src/classes/ReptilExotico.cpp
	$(CC) $(FLAGS) src/classes/ReptilExotico.cpp -std=c++11

src/classes/ReptilNativo.o: src/classes/ReptilNativo.cpp
	$(CC) $(FLAGS) src/classes/ReptilNativo.cpp -std=c++11

src/classes/Tratador.o: src/classes/Tratador.cpp
	$(CC) $(FLAGS) src/classes/Tratador.cpp -std=c++11

src/classes/Veterinario.o: src/classes/Veterinario.cpp
	$(CC) $(FLAGS) src/classes/Veterinario.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)

debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
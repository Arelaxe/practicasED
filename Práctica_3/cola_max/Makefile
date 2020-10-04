SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -I$(SRC) -c

all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o
	$(CXX) $(OBJ)/pruebacola_max.o -o $(BIN)/pruebacola_max

$(OBJ)/pruebacola_max.o: $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebacola_max.cpp -o $(OBJ)/pruebacola_max.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

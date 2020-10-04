SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario : $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INCLUDE)/Termino.h $(INCLUDE)/Diccionario.h
	$(CXX) -c -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INCLUDE)/Termino.h 
	$(CXX) -c -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INCLUDE)/Diccionario.h $(INCLUDE)/Termino.h 
	$(CXX) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INCLUDE) -std=c++11


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INClUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

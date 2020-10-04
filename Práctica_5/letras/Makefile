SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INCLUDE) -c

all: $(BIN)/testdiccionario $(BIN)/letras $(BIN)/cantidad_letras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o -std=c++11

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(INCLUDE)/Diccionario.h
	$(CXX) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp $(INCLUDE)/Diccionario.h $(INCLUDE)/Conjunto_Letras.h
	$(CXX) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INCLUDE) -std=c++11


$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o -std=c++11

$(OBJ)/letras.o: $(SRC)/letras.cpp $(INCLUDE)/Bolsa_Letras.h $(INCLUDE)/Diccionario.h
	$(CXX) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Bolsa_Letras.o: $(SRC)/Bolsa_Letras.cpp $(INCLUDE)/Bolsa_Letras.h $(INCLUDE)/Conjunto_Letras.h
	$(CXX) -c -o $(OBJ)/Bolsa_Letras.o $(SRC)/Bolsa_Letras.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Conjunto_Letras.o: $(SRC)/Conjunto_Letras.cpp $(INCLUDE)/Conjunto_Letras.h $(INCLUDE)/Letra.h
	$(CXX) -c -o $(OBJ)/Conjunto_Letras.o $(SRC)/Conjunto_Letras.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Letra.o: $(SRC)/Letra.cpp $(INCLUDE)/Letra.h
	$(CXX) -c -o $(OBJ)/Letra.o $(SRC)/Letra.cpp -I$(INCLUDE) -std=c++11


$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o -std=c++11

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp $(INCLUDE)/Bolsa_Letras.h $(INCLUDE)/Diccionario.h
	$(CXX) -c -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp -I$(INCLUDE) -std=c++11

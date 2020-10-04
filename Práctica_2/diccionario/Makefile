SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INCLUDE) -c


all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario : $(OBJ)/pruebadiccionario.o $(INCLUDE)/Lista.h $(INCLUDE)/Lista.cpp $(INCLUDE)/Vector_Dinamico.tpp $(INCLUDE)/Vector_Dinamico.h $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/Termino.o $(OBJ)/Diccionario.o -I$(INCLUDE) -std=c++11

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INCLUDE)/Lista.h $(INCLUDE)/Lista.cpp $(INCLUDE)/Vector_Dinamico.tpp $(INCLUDE)/Vector_Dinamico.h $(INCLUDE)/Diccionario.h $(INCLUDE)/Termino.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INCLUDE)/Termino.h $(INCLUDE)/Lista.h $(INCLUDE)/Vector_Dinamico.h
	$(CXX) -c -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INCLUDE)/Diccionario.h $(INCLUDE)/Termino.h
	$(CXX) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INCLUDE) -std=c++11

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INCLUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

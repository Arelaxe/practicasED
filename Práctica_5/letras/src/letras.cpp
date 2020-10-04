#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <list>
#include <unordered_set>
#include "Bolsa_Letras.h"
#include "Diccionario.h"

using namespace std;

int main(int argc, char *argv[]){
	if (argc!=5){
		cerr << "Número de argumentos incorrecto" << endl;
		cerr << "Uso: <" << argv[0] << "> <fichero diccionario> <fichero letras> <número de letras> <modalidad de juego>" << endl;
		exit(1);
	}

	if (strcmp(argv[4],"L") && strcmp(argv[4],"P")!=0){
		cerr << argv[4] << " no es una modalidad de juego, escoge P (puntuación) o L (palabra más larga)" << endl;
		exit(2);
	}

	Conjunto_Letras c;
	Diccionario d;
	string respuesta;
	char quiere_seguir[5] = "S";
	int puntuacion;
	list<char> letras_sacadas;
	list<string> respuestas_programa;
	char nueva_letra;

	ifstream f1(argv[2]); //Abrimos el fichero de letras

	if (!f1){
		cout << "No puedo abrir el fichero " << argv[2] << endl;
		exit (3);
	}

	f1 >> c; //Leemos el conjunto de letras a partir del fichero de letras
	Bolsa_Letras b(c); //Creamos una bolsa de letras a partir del conjunto

	ifstream f2(argv[1]); //Abrimos el fichero diccionario

	if (!f2){
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		exit (4);
	}

	f2 >> d; //Leemos el diccionario
	
	while (strcmp("S",quiere_seguir)==0 && nueva_letra!=-1){ //Continúa el juego hasta que el usuario no quiera seguir o se nos acaben las letras de la bolsa
	
		cout << "Las letras son: ";

		for (int i=0; i<atoi(argv[3]) && nueva_letra!=-1; i++){ //Sacamos tantas letras como nos pide el usuario
			nueva_letra = b.SacaUnaLetra();
			if (nueva_letra!=-1){
				letras_sacadas.push_back(nueva_letra);
				cout << nueva_letra << " ";
			}
		}

		cout << endl;

		cout << "¿Cuál es tu solución: ";
		cin >> respuesta;

		while(!d.PalabraValida(respuesta,letras_sacadas)){ //Obligamos al usuario a que nos dé una respuesta válida
			cout << "Esta palabra no vale, dime otra: ";
			cin >> respuesta;
		}

		if (strcmp(argv[4],"L")==0){ // Según el modo de juego elegido, calculamos la puntuación de la respuesta del usuario y el programa calcula sus respuestas
			puntuacion = respuesta.size();
			respuestas_programa = d.FormaPalabrasMaxLongitud(letras_sacadas);
		}
		else {
			puntuacion = c.CalcularPuntuacion(respuesta);
			respuestas_programa = d.FormaPalabrasMaxPuntuacion(letras_sacadas, c);
		}

		cout << respuesta << "\tPuntuación: " << puntuacion << endl;

		list<string>::iterator it_lista;

		for(it_lista=respuestas_programa.begin(); it_lista!=respuestas_programa.end(); it_lista++){
			cout << "Mi respuesta: " << *it_lista << " Puntuación: ";

			if (strcmp(argv[4],"L")==0)
				cout << (*it_lista).size();
			else
				cout << c.CalcularPuntuacion(*it_lista);
			cout << endl;
		}

		letras_sacadas.clear(); //Borra la lista de letras sacadas para sacar otras nuevas

		if (nueva_letra==-1)
			cout << "Ya no me quedan más letras, termina el juego" << endl;
		else{
			do{
				cout << "¿Quieres seguir jugando? [S/N]? ";
				cin >> quiere_seguir;
			}
			while(strcmp("S",quiere_seguir)!=0 && strcmp("N",quiere_seguir)!=0);
		}
	}

	return (0);
}

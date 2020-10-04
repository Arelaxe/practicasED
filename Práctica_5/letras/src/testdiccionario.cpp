#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"

using namespace std;

int main (int argc, char *argv[]){
	if (argc != 2){
		cout << "Número de parámetros incorrecto, uso: " << endl
             << "<nombre del programa> <fichero con las palabras>" << endl;
		exit (1);
	}

	ifstream f(argv[1]);

	if (!f){
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		exit (2);
	}

	Diccionario d;

	cout << "Cargando diccionario..." << endl;
	f >> d;

	cout << "Diccionario leído: " << endl;
	cout << d;

	int longitud;

	cout << "Dime la longitud de las palabras: ";
	cin >> longitud;

	vector<string> v = d.PalabrasLongitud(longitud);

	cout << "Palabras de longitud " << longitud << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	string p;

	cout << "Dime una palabra: ";
	cin >> p;

	if (d.Esta(p))
		cout << "Esta palabra existe" << endl;
	else
		cout << "Esta palabra no existe" << endl;

	return (0);
}

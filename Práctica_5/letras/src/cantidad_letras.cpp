#include <iostream>
#include <fstream>
#include <cctype>
#include "Diccionario.h"
#include "Bolsa_Letras.h"

using namespace std;

int main (int argc, char *argv[]){
	if(argc!=4){
		cerr << "Número de argumentos incorrecto." << endl;
		cerr << "Uso: <" << argv[0] << "> <fichero diccionario> <fichero letras> <fichero salida>" << endl;
		exit(1);
	}

	ifstream f1(argv[1]), f2(argv[2]); //Abrimos el fichero diccionario y el fichero letras

	if(!f1){
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		exit(2);
	}

	if(!f2){
		cout << "No puedo abrir el fichero " << argv[2] << endl;
		exit(3);
	}

	Diccionario d;
	Conjunto_Letras c;
	
	f1 >> d;
	f2 >> c;


	ofstream f3(argv[3]); //Abrimos el fichero de salida

	if(!f3){
		cout << "No puedo abrir el fichero " << argv[3] << endl;
		exit(4);
	}

	f3 << "#Letra FAbs Frel" << endl; //Imprime la cabecera del fichero
	Diccionario::iterator it_diccionario;
	Conjunto_Letras::iterator it_conjunto;

	for (it_conjunto=c.begin(); it_conjunto!=c.end(); it_conjunto++){ //Busca cuántas veces aparece cada letra
		int f_absoluta = 0;
		int total_letras = 0;
		for (it_diccionario=d.begin(); it_diccionario!=d.end(); it_diccionario++){
			for (int i=0; i<(*it_diccionario).size(); i++){
				total_letras++;
				if(toupper((*it_diccionario)[i])==(*it_conjunto).GetCaracter())
					f_absoluta++;
			}
		}
		double f_relativa = ((double)f_absoluta/(double)total_letras) * 100; //Calcula la frecuencia relativa de la letra
		f3 << (*it_conjunto).GetCaracter() << "\t" << f_absoluta << "\t" << f_relativa << endl; //Imprime los resultados
	}
	

	return(0);
}

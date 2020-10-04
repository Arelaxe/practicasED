#include "Diccionario.h"
#include "Termino.h"
#include "Lista.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){

	if (argc!=2){
		cout<<"Dime el nombre del fichero con el diccionario"<<endl;
		return 0;
	}

	ifstream f (argv[1]);

	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    	return 0;
	}

	int max_defs, max_defs_termino;
	float promedio_defs;
	Diccionario mi_diccionario; 

	f>>mi_diccionario; //Cargamos en memoria el diccionario

	cout << "///////////////////////" << endl
		 << "//EL DICCIONARIO LEÍDO: " << endl
		 << "///////////////////////" << endl;

	cout << mi_diccionario;

	Diccionario sub1 = mi_diccionario.Intervalo ('a', 'c');

	cout << "/////////////////////////////" << endl
		 << "//SUBDICCIONARIO ENTRE A Y C: " << endl
		 << "/////////////////////////////" << endl;
	cout << sub1;

	Diccionario sub2 = mi_diccionario.PalabraClave ("Old");
	
	cout << "/////////////////////////////" << endl
		 << "//SUBDICCIONARIO CON PALABRA CLAVE OLD: " << endl
		 << "/////////////////////////////" << endl;
	cout << sub2;


	mi_diccionario.RecuentoDefiniciones (max_defs, max_defs_termino, promedio_defs);
	
	cout << "//////////////////////////////////////////////" << endl
		 << "//DATOS INTERESANTES DEL PRIMER DICCIONARIO: " << endl
		 << "//////////////////////////////////////////////" << endl << endl;

	cout << "TOTAL DEFINICIONES: " << max_defs << endl;
	cout << "MÁXIMO DE DEFINICIONES POR TÉRMINO: " << max_defs_termino << endl;
	cout << "PROMEDIO DE DEFINICIONES POR TÉRMINO: " << promedio_defs << endl;
}

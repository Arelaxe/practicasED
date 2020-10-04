#include "Diccionario.h"
#include <fstream>
#include <iostream>

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
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
   Diccionario::const_iterator it; 
   for(it = mi_diccionario.begin(); it != mi_diccionario.end(); ++it){
     cout << (*it) << endl;
   }
	
	cout << endl;   
	
	cout << "----------------------------------------------" << endl;
	cout << "|DEFINICIONES ASOCIADAS A LA PALABRA 'BROWNIE'" << endl;
	cout << "----------------------------------------------" << endl;

	vector<string> defs = mi_diccionario.GetDefiniciones("brownie");

	for (int i = 0; i < defs.size(); i++){
		cout <<"-" << defs[i] << endl;
	}

	cout << endl;   
	
	cout << "----------------------------------------------" << endl;
	cout << "|SUBDICCIONARIO ENTRE B Y D" << endl;
	cout << "----------------------------------------------" << endl;	

	Diccionario sub1, sub2;

	sub1 = mi_diccionario.FiltraPorIntervalo('b','d');

	cout << sub1 << endl;

	cout << endl;   
	
	cout << "----------------------------------------------" << endl;
	cout << "|SUBDICCIONARIO CON LA PALABRA 'YELLOW'" << endl;
	cout << "----------------------------------------------" << endl;	

	sub2 = mi_diccionario.FiltraPorPalabraClave("yellow");

	cout << sub2 << endl;

	cout << endl;   
	
	cout << "----------------------------------------------" << endl;
	cout << "|DATOS INTERESANTES DEL DICCIONARIO" << endl;
	cout << "----------------------------------------------" << endl;	

	int total_defs, max_defs_palabra;
	float promedio_defs;

	mi_diccionario.RecuentoDefiniciones(total_defs, max_defs_palabra, promedio_defs);

	cout << "Total de definiciones: " << total_defs << endl
		 << "Máximo de definiciones por palabra: " << max_defs_palabra << endl
		 << "Promedio de definiciones: " << promedio_defs << endl;

}

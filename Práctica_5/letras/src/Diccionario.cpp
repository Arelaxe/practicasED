#include "Diccionario.h"
#include <iostream>

using namespace std;

Diccionario::Diccionario(){
}

int Diccionario::size() const{
	return (datos.size());
}

vector<string> Diccionario::PalabrasLongitud(int longitud) const{
	Diccionario::iterator it;
	vector<string> a_devolver;

	for (it=begin(); it!=end(); it++){
		if ((*it).size() == longitud){
			a_devolver.push_back(*it);
		}
	}
	return (a_devolver);
}

bool Diccionario::Esta(string palabra) const{
	return (datos.find(palabra)!=end());
}

bool Diccionario::PalabraValida(const string palabra, const list<char> lista) const{
	list<char> otra_lista = lista; //Necesitamos una lista auxiliar en la que eliminaremos las letras que vayamos sacando
	bool es_valida = true;

	for (int i=0; i<palabra.size() && es_valida; i++){
		bool esta = false;
		for (list<char>::const_iterator it=otra_lista.cbegin(); it!=otra_lista.cend() && !esta; it++){
			if(toupper(palabra[i])==*it){
				esta = true;
				otra_lista.erase(it);
			}
		}
		if (!esta){
			es_valida = false;
		}
	}

	return (es_valida && Esta(palabra)); //Es válida si se puede formar con la lista y si está en el diccionario
}

list<string> Diccionario::FormaPalabras(const list<char> lista) const{
	list<string> palabras;
	Diccionario::const_iterator it;

	for(it=datos.begin();it!=datos.end();it++){
		if(PalabraValida((*it),lista))
			palabras.push_back(*it);	
	}
	
	return (palabras);
}

list<string> Diccionario::FormaPalabrasMaxPuntuacion(const list<char> lista, const Conjunto_Letras c) const{
	list<string> palabras = FormaPalabras(lista); //Miramos todas las palabras que se pueden formar con las letras
	list<string> palabras_max;
	list<string>::iterator it1, it2;
	int puntuacion_max = 0;

	for (it1=palabras.begin(); it1!=palabras.end(); it1++){ //Hacemos un primer recorrido para hallar la máxima puntuación, vamos eliminando algunas palabras
		if(c.CalcularPuntuacion(*it1)>=puntuacion_max){
			palabras_max.push_back(*it1);
			puntuacion_max = c.CalcularPuntuacion(*it1);
		}
	}

	for (it2=palabras_max.begin(); it2!=palabras_max.end(); ){ //Nos quedamos solo con las que tengan la máxima puntuación
		if(c.CalcularPuntuacion(*it2)<puntuacion_max){
			it2=palabras_max.erase(it2);
		}
		else
			it2++;
	}

	return (palabras_max);
}

list<string> Diccionario::FormaPalabrasMaxLongitud(const list<char> lista) const{ //Igual que el anterior, pero con la longitud en vez de con la puntuación
	list<string> palabras = FormaPalabras(lista);
	list<string> palabras_max;
	list<string>::iterator it1, it2;
	int longitud_max = 0;
	
	for (it1=palabras.begin(); it1!=palabras.end(); it1++){
		if((*it1).size()>=longitud_max){
			palabras_max.push_back(*it1);
			longitud_max = (*it1).size();
		}
	}

	for (it2=palabras_max.begin(); it2!=palabras_max.end(); ){
		if((*it2).size()<longitud_max){
			it2=palabras_max.erase(it2);
		}
		else
			it2++;
	}

	return (palabras_max);
}

istream & operator>>(istream & in, Diccionario & d){
	string a_leer;

	while (!in.eof()){
		in >> a_leer;
		d.datos.insert(a_leer);
	}
	
	return (in);
}

ostream & operator<<(ostream & out, const Diccionario & d){
	Diccionario::iterator it;

	for (it=d.begin(); it!=d.end(); it++){
		out << (*it) << endl;
	}

	return (out);
}

Diccionario::iterator Diccionario::begin(){
	return (datos.begin());
}

Diccionario::const_iterator Diccionario::begin() const{
	return (datos.cbegin());
}

Diccionario::iterator Diccionario::end(){
	return (datos.end());
}

Diccionario::const_iterator Diccionario::end() const{
	return (datos.cend());
}

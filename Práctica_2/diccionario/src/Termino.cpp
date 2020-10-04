#include <string>
#include "Termino.h"
#include "Lista.h"
#include "Vector_Dinamico.h"
#include <iostream>
#include <sstream>

Termino :: Termino (){
	palabra = "";
	definiciones.resize (1);
}

Termino :: Termino (string p, Vector_Dinamico<string> defs){
	palabra = p;
	definiciones.resize (defs.size());
	definiciones = defs;
}

Termino :: Termino (const Termino & t){
	palabra = t.palabra;
	definiciones = t.definiciones;
}

string Termino :: GetPalabra () const{
	return (palabra);
}

Vector_Dinamico<string> Termino :: GetDefiniciones () const{
	return (definiciones);
}

int Termino :: GetNumeroDefiniciones () const{
	return (definiciones.size());
}

void Termino :: SetPalabra (string p){
	palabra = p;
}

void Termino :: SetDefiniciones (Vector_Dinamico<string> defs){
	definiciones.resize (defs.size());
	definiciones = defs;
}

void Termino :: AniadeDefinicion (string def){
	definiciones.add (def);
}

Termino & Termino :: operator= (const Termino & t){
	if (this != &t){
		palabra = t.palabra;
		definiciones = t.definiciones;
	}

	return (*this);
	
}

Termino Termino :: operator + (const Termino & t) const{
    Termino suma = *this;

    for (int i = 0 ; i < t.GetNumeroDefiniciones() ; i++)
        suma.AniadeDefinicion(t.definiciones[i]);

    return suma;
}

bool Termino :: operator== (const Termino & t) const{
	return ((palabra.compare(t.palabra)==0));
}

bool Termino :: operator!= (const Termino & t) const{
	return (!(palabra==t.palabra));
}

bool Termino :: operator< (const Termino & t) const{
	return ((palabra.compare(t.palabra)<0));
}

bool Termino :: operator> (const Termino & t) const{
	return ((palabra.compare(t.palabra)>0));
}

istream & operator>> (istream & in, Termino & t){
	int pos = 0;	
	string cad, p = "", def = "";
	
	getline(in,cad);
	
	while (cad[pos] != ';'){
		p += cad[pos];
		pos++;
	}

	t.palabra = p;

	pos++;

	while (pos < cad.size()){
		def += cad[pos];
		pos++;
	}

	Vector_Dinamico<string> defs;
	defs.resize (1);
	defs[0] = def;

	t.definiciones = defs;

	return in;
}

ostream & operator<< (ostream & out, Termino & t){
	out << "Palabra: " << t.palabra << endl;
	
	out << "Definiciones: ";
	for (int i = 0; i < t.definiciones.size(); i++){
		out << t.definiciones[i] << endl;
	}

	return out;
}

#include "Diccionario.h"
#include "Termino.h"
#include "Lista.h" 
#include <iostream>
#include <string>

Diccionario :: Diccionario (){
	
}

Diccionario :: Diccionario (Lista<Termino> tnos){
	terminos = tnos;
}

Diccionario :: Diccionario (const Diccionario & otro){
	terminos = otro.terminos; 
}

Diccionario & Diccionario :: operator= (const Diccionario & d){
	if (this != &d){
		terminos = d.terminos;
	}

	return (*this);
}

Vector_Dinamico<string> Diccionario :: GetDefiniciones (Termino t) const{
	return (t.GetDefiniciones());
}

Lista<Termino> Diccionario :: GetTerminos () const{
	return terminos;
} 

int Diccionario :: GetNumeroTerminos () const{ 
	return terminos.GetNumeroElementos ();
} 

void Diccionario :: AniadeTermino (Termino t){
	Posicion<Termino> p = terminos.begin();
			
	while (t > terminos.get(p) && p != terminos.end()){
		++p;
	}
			
	if (terminos.get(p) == t){
		Termino a_insertar = terminos.get(p) + t;
		terminos.set (p, a_insertar);
	}
	else{
		terminos.insertar (p, t);
	}
}

void Diccionario :: EliminaTermino (Termino t){
	Posicion<Termino> p = terminos.begin();

	while (terminos.get(p) != t && p != terminos.end()){
		++p;
	}
 
	terminos.borrar(p);
}

istream & operator>> (istream & in, Diccionario & d){
	while (!in.eof()){
		Termino t;
		in >> t;
		d.AniadeTermino (t);
	}

	return in;      
}

ostream & operator<< (ostream & out, Diccionario & d){
	Posicion<Termino> p = d.terminos.begin();
	p++;

	while (p != d.terminos.end()){
		Termino a_mostrar = d.terminos.get(p);
		out << a_mostrar << endl;
		p++; 
	}

	return out;
}

Diccionario Diccionario :: Intervalo (char caracter_inicio, char caracter_fin){
	Diccionario subdiccionario;
	Posicion <Termino> p = terminos.begin();
	
	// Encontrar inicio
	while (terminos.get(p).GetPalabra()[0] != caracter_inicio && p != terminos.end()){		
		p++;
	}

	// Añadir
	while (terminos.get(p).GetPalabra()[0] >= caracter_inicio && terminos.get(p).GetPalabra()[0] <= caracter_fin && p != terminos.end()){
		subdiccionario.AniadeTermino (terminos.get(p));
		p++;
	}
	subdiccionario.AniadeTermino (terminos.get(terminos.end()));

	return subdiccionario;
}

Diccionario Diccionario :: PalabraClave (string palabra){
	Diccionario subdiccionario;
	Posicion <Termino> p = terminos.begin();

	while (p != terminos.end()){
		for (int i = 0; i < terminos.get(p).GetDefiniciones().size(); i++){
			if (terminos.get(p).GetDefiniciones()[i].find(palabra) != string::npos){
				Vector_Dinamico<string> defs;
				defs.add(terminos.get(p).GetDefiniciones()[i]);
				Termino t (terminos.get(p).GetPalabra(), defs);
				subdiccionario.AniadeTermino(t);
			}
		}
		p++;
	}
	subdiccionario.AniadeTermino (terminos.get(terminos.end()));

	return subdiccionario;
} 

void Diccionario :: RecuentoDefiniciones (int & total_definiciones, int & max_defs_palabra, float & promedio_defs){
	Posicion<Termino> p = terminos.begin();
	
	total_definiciones = 0;
	max_defs_palabra = 0;
	promedio_defs = 0;

	while (p != terminos.end()){
		int defs_palabra = 0;

		for (int i = 0; i < terminos.get(p).GetDefiniciones().size(); i++){
			defs_palabra++;
		}
		
		total_definiciones += defs_palabra;

		if (defs_palabra > max_defs_palabra)
			max_defs_palabra = defs_palabra;

		p++;
	}	

	promedio_defs = total_definiciones / (float)GetNumeroTerminos ();

}

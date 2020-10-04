#include "Letra.h"
#include <cctype>

Letra::Letra(){
	caracter = ' ';
	apariciones_posibles = 0;
	puntuacion = 0;
}

Letra::Letra(char c, int a, int p){
	caracter = c;
	apariciones_posibles = a;
	puntuacion = p;
}

char Letra::GetCaracter() const{
	return (caracter);
}

int Letra::GetPuntuacion() const{
	return (puntuacion);
}

int Letra::GetApariciones() const{
	return (apariciones_posibles);
}

bool Letra::operator==(const Letra & l) const{
	return (caracter==l.caracter && apariciones_posibles==l.apariciones_posibles && puntuacion==l.puntuacion);
}

bool Letra::operator!=(const Letra & l) const{
	return !((*this)==l);
}

bool Letra::operator<(const Letra & l) const{
	return (caracter<l.caracter);
}

istream & operator>>(istream & in, Letra & l){
	char c;
	int a, p;

	cin >> c >> a >> p;

	l.caracter = toupper(c);
	l.apariciones_posibles = a;
	l.puntuacion = p;
	
	return (in);
}

ostream & operator<<(ostream & out, const Letra & l){
	out << l.caracter << " " << l.apariciones_posibles << " " << l.puntuacion << endl;

	return (out);
}

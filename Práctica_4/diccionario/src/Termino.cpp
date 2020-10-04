#include "Termino.h"

Termino::Termino(){
}

Termino::Termino(string palabra, vector<string> defs){
	termino.first = palabra;
	termino.second = defs;
}

Termino::Termino(const Termino & otro){
	termino.first = otro.termino.first;
	termino.second = otro.termino.second;
}

string Termino::GetPalabra() const{
	return (termino.first);
}

vector<string> Termino::GetDefiniciones() const{
	return (termino.second);
}

int Termino::GetNumeroDefiniciones() const{
	return (termino.second.size());
}

void Termino::SetPalabra(string palabra){
	termino.first = palabra;
}

void Termino::SetDefiniciones(vector<string> definiciones){
	termino.second = definiciones;
}

void Termino::AniadeDefinicion(string def){
	termino.second.push_back(def);
}


Termino & Termino::operator=(const Termino & otro){
	if (this != &otro){
		termino.first = otro.termino.first;
		termino.second = otro.termino.second;
	}

	return (*this);
}

bool Termino::operator==(const Termino & t) const{
	return(termino.first.compare(t.termino.first)==0);
}

bool Termino::operator!=(const Termino & t) const{
	return(!(termino==t.termino));
}

bool Termino::operator< (const Termino & t) const{
	return ((termino.first.compare(t.termino.first)<0));
}

bool Termino::operator> (const Termino & t) const{
	return ((termino.first.compare(t.termino.first)>0));
}

istream & operator>>(istream & in, Termino & t){
	int pos = 0;	
	string cad, p = "", def = "";
	
	getline(in,cad);
	
	while (cad[pos] != ';'){
		p += cad[pos];
		pos++;
	}

	t.termino.first = p;

	pos++;

	while (pos < cad.size()){
		def += cad[pos];
		pos++;
	}

	vector<string> defs;
	defs.push_back(def);

	t.termino.second = defs;

	return (in);
}

ostream & operator<<(ostream & out, const Termino & t){
	Termino::const_iterator i;

	out << "Palabra: " << t.termino.first << endl;

	for (i = t.begin(); i != t.end(); i++){
		out << "Definiciones: " << (*i) << endl;
	}

	return (out);
}


Termino::iterator Termino::begin(){
	return (termino.second.begin());
}

Termino::const_iterator Termino::begin() const{
	return (termino.second.cbegin());
}

Termino::iterator Termino::end(){
	return (termino.second.end());
}

Termino::const_iterator Termino::end() const{
	return (termino.second.cend());
}

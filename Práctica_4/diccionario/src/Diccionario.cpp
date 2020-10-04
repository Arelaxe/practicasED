#include "Diccionario.h"

Diccionario::Diccionario(){
}

Diccionario::Diccionario(set<Termino> terminos){
	diccionario = terminos;
}

Diccionario::Diccionario(const Diccionario & otro){
	diccionario = otro.diccionario;
}

vector<string> Diccionario::GetDefiniciones(string palabra) const{
	Diccionario::const_iterator i;
	vector<string> defs;
	bool encontrado = false;

	for (i = begin(); i != end() && !encontrado; i++){
		if ((*i).GetPalabra() == palabra){
			encontrado = true;
			defs = (*i).GetDefiniciones();
		}
	}
	return (defs);
}

set<Termino> Diccionario::GetTerminos() const{
	return (diccionario);
}

int Diccionario::GetNumeroTerminos() const{
	return (diccionario.size());
}

void Diccionario::AniadeTermino(const Termino t){
	Diccionario::iterator it = diccionario.find(t);
	if (it == diccionario.end())
		diccionario.insert(t);
	else{
		string def = t.GetDefiniciones().at(0);
		Termino t1 = (*it);
		t1.AniadeDefinicion(def);
		diccionario.erase(t);
		diccionario.insert(t1);
	}
}

void Diccionario::EliminaTermino(const Termino t){
	diccionario.erase(t);
}


istream & operator>>(istream & in, Diccionario & d){
	Termino t;
	while (in >> t){
		d.AniadeTermino(t);
	}

	return (in);
}

ostream & operator<<(ostream & out, const Diccionario & d){
	Diccionario::const_iterator i;

	for (i = d.begin(); i != d.end(); i++){
		out << (*i) << endl;
	}
	return (out);
}


Diccionario::iterator Diccionario::begin(){
	return (diccionario.begin());
}

Diccionario::const_iterator Diccionario::begin() const{
	return (diccionario.cbegin());
}

Diccionario::iterator Diccionario::end(){
	return (diccionario.end());
}

Diccionario::const_iterator Diccionario::end() const{
	return (diccionario.cend());
}


Diccionario Diccionario::FiltraPorIntervalo(char inicio, char fin){
	Diccionario subdiccionario;
	bool encontrado = false;

	Diccionario::iterator i;

	for(i = begin(); i != end() && (*i).GetPalabra()[0] < inicio; i++){
	}

	while (i != end() && (*i).GetPalabra()[0] <= fin){
		subdiccionario.AniadeTermino(*i);		
				
		i++;
	}
	return subdiccionario;
}

Diccionario Diccionario::FiltraPorPalabraClave(string palabra){
	Diccionario subdiccionario;
	Diccionario::iterator i = begin();

	while (i != end()){
		for (int j = 0; j < (*i).GetDefiniciones().size(); j++){
			if ((*i).GetDefiniciones().at(j).find(palabra) != string::npos){
				vector<string> defs;
				defs.push_back((*i).GetDefiniciones().at(j));
				Termino t ((*i).GetPalabra(), defs);
				subdiccionario.AniadeTermino(t);
			}
		}
		i++;
	}
	return subdiccionario;
}

void Diccionario :: RecuentoDefiniciones(int & total_defs, int & max_defs_palabra, float & promedio_defs){
	Diccionario::iterator i = begin();

	total_defs = max_defs_palabra = promedio_defs = 0;

	while (i != end()){
		int defs_palabra = 0;
	
		for (int j = 0; j < (*i).GetDefiniciones().size(); j++){
			defs_palabra++;
		}

		total_defs += defs_palabra;

		if (defs_palabra > max_defs_palabra)
			max_defs_palabra = defs_palabra;

		i++;
	}

	promedio_defs = total_defs / (float)GetNumeroTerminos();
}

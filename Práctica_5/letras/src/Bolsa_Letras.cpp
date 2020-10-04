#include "Bolsa_Letras.h"
#include <cstdlib>
#include <chrono>
#include <random>

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

Bolsa_Letras::Bolsa_Letras(){
}

Bolsa_Letras::Bolsa_Letras(Conjunto_Letras c){
	for (Conjunto_Letras::iterator it=c.begin(); it!=c.end(); it++){
		for (int i=0; i<(*it).GetApariciones(); i++){ // Inserta tantas letras de ese tipo como apariciones tenga
			bolsa.insert((*it).GetCaracter());
		}
	}
}

int Bolsa_Letras::GetTotalLetras() const{
	return (bolsa.size());
}

char Bolsa_Letras::SacaUnaLetra(){
	unordered_multiset<char>::iterator it = bolsa.end();
	while (it==bolsa.end() && !bolsa.empty()){ //Saca letras aleatorias hasta encontrar una que esté en la bolsa
		it=bolsa.find(aleatorio<65,90>());
	}

	char l = (*it);

	bolsa.erase(it);

	if(bolsa.empty()){ // Si la bolsa se ha quedado vacía, devuelve -1 para informar
		l = -1;
	}

	return(l);
}

ostream & operator<<(ostream & out, const Bolsa_Letras & b){
	unordered_multiset<char>::const_iterator it;
	for (it=b.bolsa.cbegin(); it!=b.bolsa.cend(); it++){
		out << *it << " ";
	}

	out << endl;

	return (out);
}

#include "Conjunto_Letras.h"

int Conjunto_Letras::CalcularPuntuacion(const string palabra) const{
	int puntuacion = 0;

	for(int i=0; i<palabra.size(); i++){
		Letra l = EncuentraLetra(toupper(palabra[i])); // Busca el dato de tipo Letra en el conjunto para poder hallar su puntuación
		puntuacion += l.GetPuntuacion();
	}
	return (puntuacion);
}

Letra Conjunto_Letras::EncuentraLetra(char letra) const{
	bool encontrada = false;
	Letra a_devolver;

	for(Conjunto_Letras::iterator it=conjunto.begin(); it!=conjunto.end() && !encontrada; it++){
		if((*it).GetCaracter()==letra){
			encontrada = true;
			a_devolver = *it;
		}
	}

	return (a_devolver);
}

istream & operator>>(istream & in, Conjunto_Letras & c){
	string cad;
	char letra;
	int cantidad, puntos;

	getline(in,cad);

	if(cad[0]=='#'){ //Si no empieza por '#' no es un fichero de letras
		while (in>>letra){
			in >> cantidad >> puntos;

			Letra l(letra, cantidad, puntos);
			c.conjunto.insert(l);
		}
	}
	return (in);
}

ostream & operator<<(ostream & out, const Conjunto_Letras & c){
	Conjunto_Letras::const_iterator it;

	for (it=c.conjunto.cbegin(); it!=c.conjunto.cend(); it++){
		out << *it << endl;
	}
}

Conjunto_Letras::iterator Conjunto_Letras::begin(){
	return (conjunto.begin());
}

Conjunto_Letras::const_iterator Conjunto_Letras::begin() const{
	return (conjunto.cbegin());
}

Conjunto_Letras::iterator Conjunto_Letras::end(){
	return (conjunto.end());
}

Conjunto_Letras::const_iterator Conjunto_Letras::end() const{
	return (conjunto.cend());
}

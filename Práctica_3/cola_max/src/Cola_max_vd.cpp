#include "Cola_max_vd.h"

////////////////////////////////////////
// MÉTODOS PÚBLICOS
////////////////////////////////////////

template <class T>
Cola_max<T> :: Cola_max(){
}

template <class T>
void Cola_max<T> :: poner (T elemento){
	Pareja<T> p;
	
	p.dato = p.max = elemento; 

	if (num_elementos() > 0){
		if (elemento > maximo()){
			actualizar_maximo(elemento);
		}
		else if (elemento > datos[num_elementos()-1].max){
			actualizar_maximo_intervalo (elemento);
		}
	}

	datos.push_back (p);
}

template <class T>
void Cola_max<T> :: quitar (){
	for (int i = 0; i < num_elementos(); i++){
		datos[i].dato = datos[i+1].dato;
		datos[i].max = datos[i+1].max;
	}

	datos.resize (num_elementos() - 1);
}

template <class T>
const T & Cola_max<T> :: maximo(){
	return (datos[0].max);
}

template <class T>
int Cola_max<T> :: num_elementos(){
	return (datos.size());
}

template <class T>
const T & Cola_max<T> :: frente (){
	return (datos[0].dato);
}

template <class T>
bool Cola_max<T> :: vacia (){
	return (datos.size() == 0);
}

////////////////////////////////////////
// MÉTODOS PRIVADOS
////////////////////////////////////////

template <class T>
void Cola_max<T> :: actualizar_maximo (T nuevo_maximo){
	for (int i = 0; i < num_elementos() && datos[i].max < nuevo_maximo; i++){
		datos[i].max = nuevo_maximo;
	}
}

template <class T>
void Cola_max<T> :: actualizar_maximo_intervalo (T nuevo_maximo){
	for (int i = num_elementos()-1; i >= 0 && datos[i].max < nuevo_maximo; i--){
		datos[i].max = nuevo_maximo;
	}
}

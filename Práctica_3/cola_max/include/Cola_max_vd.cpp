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
			actualizar_maximo (elemento);
		}
	}

	datos.push_back (p);
}

template <class T>
void Cola_max<T> :: quitar (){
	if (datos[0].dato == maximo ()){
		T nuevo_maximo = 0;

		for (int i = 1; i < num_elementos(); i++){
			if (datos[i].dato > nuevo_maximo)
				nuevo_maximo = datos[i].dato;
		}
		
		actualizar_maximo (nuevo_maximo);
	}

	for (int i = 0; i < num_elementos(); i++){
		datos[i].dato = datos[i+1].dato;
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
			for (int i = 0; i < num_elementos(); i++){
				datos[i].max = nuevo_maximo;
			}
}

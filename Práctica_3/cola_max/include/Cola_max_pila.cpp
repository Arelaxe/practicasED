#include "Cola_max_pila.h"

////////////////////////////////////////
// MÉTODOS PÚBLICOS
////////////////////////////////////////

template <class T>
Cola_max<T> :: Cola_max(){
}

template <class T>
void Cola_max<T> :: poner (T elemento){
	Pareja<T> a_insertar;
	a_insertar.dato = elemento;
	a_insertar.max = elemento;
	
	if (!vacia()){
		if (elemento > maximo()){
			actualizar_maximo (elemento);
		}
		else
			a_insertar.max = maximo();
	}
	
	entrada.push (a_insertar);
}

template <class T>
void Cola_max<T> :: quitar (){
	volcar_pila(entrada, salida);

	T valor = salida.top().max;
	T antiguo_max = maximo();
	salida.pop();

	if (valor == antiguo_max){
		T nuevo_maximo = 0;
		
		for (unsigned i = 0; i < salida.size(); i++){
			if (salida.top().dato > nuevo_maximo)
				nuevo_maximo = salida.top().dato;

			entrada.push (salida.top());
			salida.pop();
		} 
		volcar_pila (entrada, salida);
		actualizar_maximo (nuevo_maximo);
	}
}

template <class T>
const T & Cola_max<T> :: maximo (){
	if (salida.empty())
		return (entrada.top().max);
	else
		return (salida.top().max);
}

template <class T>
int Cola_max<T> :: num_elementos(){
	volcar_pila(entrada, salida);
	int tam = salida.size();
	volcar_pila(salida, entrada);

	return (tam);
}

template <class T>
const T Cola_max<T> :: frente (){
	volcar_pila(entrada, salida);
	T f = salida.top().dato;
	volcar_pila (salida, entrada);

	return (f);
}

template <class T>
bool Cola_max<T> :: vacia (){
	return (salida.empty() && entrada.empty());
}

////////////////////////////////////////
// MÉTODOS PRIVADOS
////////////////////////////////////////

template <class T>
void Cola_max<T> :: actualizar_maximo (T nuevo_maximo){

	while (!entrada.empty()){
		salida.push(entrada.top());
		salida.top().max = nuevo_maximo;
		entrada.pop();
	}

	volcar_pila (salida, entrada);
}

template <class T>
void Cola_max<T> :: volcar_pila (stack<Pareja<T>> & a_volcar, stack<Pareja<T>> & volcada){
	while (!a_volcar.empty()){
			volcada.push(a_volcar.top());
			a_volcar.pop();
	}
}

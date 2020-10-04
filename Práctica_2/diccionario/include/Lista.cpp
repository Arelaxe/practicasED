#include <cassert>
#include <iostream>
#include "Lista.h"

using namespace std;

// Clase Posición

template <class T>
Posicion<T> :: Posicion(){
	puntero = 0;
}

template <class T>
Posicion<T> & Posicion<T> :: operator= (const Posicion<T> & p){
	puntero = p.puntero;
}

template <class T>
Posicion<T> & Posicion<T> :: operator++(){
	puntero = puntero->siguiente;
	return *this;
}

template <class T>
Posicion<T> Posicion<T> :: operator++(int){
	Posicion<T> p(*this);
	++(*this);
	return p;
}

template <class T>
Posicion<T> & Posicion<T> :: operator--(){
	puntero = puntero->anterior;
	return *this;
}

template <class T>
Posicion<T> Posicion<T> :: operator--(int){
	Posicion<T> p(*this);
	--(*this);
	return p;
} 

template <class T>
bool Posicion<T> :: operator== (const Posicion<T> & p) const{
	return (puntero == p.puntero);
}

template <class T>
bool Posicion<T> :: operator!= (const Posicion<T> & p) const{
	return (puntero != p.puntero);
}

// Clase Lista

template <class T>
Lista<T> :: Lista(){
	cabecera = new CeldaLista<T>;
	cabecera->siguiente = cabecera;
	cabecera->anterior = cabecera;
}

template <class T>
Lista<T> :: Lista(const Lista<T> & l){
	cabecera = new CeldaLista<T>;
	cabecera->siguiente = cabecera;
	cabecera->anterior = cabecera;

	CeldaLista<T> * p = l.cabecera->siguiente;
	while (p != l.cabecera){
		CeldaLista<T> * q = new CeldaLista<T>;
		q->elemento = p->elemento;
		q->anterior = cabecera->anterior;
		cabecera->anterior->siguiente = q;
		cabecera->anterior = q;
		q->siguiente = cabecera;
		p = p->siguiente;
	}

}

template <class T>
Lista<T> :: ~Lista(){
	while(begin() != end())
		borrar(begin());
	delete cabecera;
}

template <class T>
Lista<T> & Lista<T> :: operator=(const Lista<T> & l){
	Lista<T> aux(l);
	intercambiar(this->cabecera, aux.cabecera);
	return (*this);
}

template <class T> 
void Lista<T> :: set(Posicion<T> p, T e){
	p.puntero->elemento = e;
} 

template <class T>
T Lista<T> :: get(Posicion<T> p) const{
	return p.puntero->elemento;
}

template <class T>
Posicion<T> Lista<T> :: insertar(Posicion<T> p, T e){
	CeldaLista<T> * q = new CeldaLista<T>;
	q->elemento = e;
	q->anterior = p.puntero->anterior;
	q->siguiente = p.puntero;
	p.puntero->anterior = q;
	q->anterior->siguiente = q;
	p.puntero = q;
	return p;
}

template <class T>
Posicion<T> Lista<T> :: borrar (Posicion<T> p){
	assert (p != end()); 
	CeldaLista<T> * q = p.puntero;
	q->anterior->siguiente = q->siguiente;
	q->siguiente->anterior = q->anterior;
	p.puntero = q->siguiente;
	delete q;
	return p;
}

template <class T>
Posicion<T> Lista<T> :: begin() const{
	Posicion<T> p;
	p.puntero = cabecera->siguiente;
	return p;
}

template <class T>
Posicion<T> Lista<T> :: end() const{
	Posicion<T> p;
	p.puntero = cabecera;
	return p;
}

template <class T>
int Lista<T> :: GetNumeroElementos() const{
	Posicion<T> p = begin();
	int nelem = 0;

	while (p != end()){		
		p++;
		nelem++;
	} 

	return nelem;
}

template <class T>
void intercambiar (T p, T q){
	T aux;
	aux = p;
	p = q;
	q = aux;
}

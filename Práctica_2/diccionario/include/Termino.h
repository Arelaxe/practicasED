/**
 * @file Termino.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Termino 
*/


#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <string>
#include "Lista.h"
#include "Vector_Dinamico.h"

using namespace std;

/**
	*@brief Una instancia t del TDA Termino es un objeto compuesto por una palabra de tipo string y un vector dinámico de string compuesto por definiciones
*/

class Termino{
private:
	/**
	* @page repTermino Rep del TDA Termino
	* @section invTermino Invariante de la representación
	* Se debe cumplir que si el campo definiciones no está vacío, el número de elementos de definiciones debe ser mayor que 0
	* @section faTermino Función de abstracción
	* Un objeto válido @e rep del TDA Termino debe seguir la siguiente representación:
	*- El dato miembro palabra es un string
	*- El dato miembro definiciones es un objeto de la clase Vector_Dinamico. Los datos del vector son de tipo string. Cada string es una definicón del término
	*/
	string palabra; /**< Palabra del término */
	Vector_Dinamico<string> definiciones; /**< Vector con las definiciones */

public:
	/**
		*@brief Constructor por defecto
	*/
	Termino ();
	/**
		*@brief Constructor con dos parámetros
		*@param p Palabra del término
		*@param defs Vector de definiciones del término
	*/
	Termino (string p, Vector_Dinamico<string> defs);
	/**
		*@brief Constructor de copia
		*@param otro Término que se va a copiar en this
	*/
	Termino (const Termino & otro);
	/**
		*@brief Consultor de la palabra del objeto
		*@return Un string con la palabra
	*/
	string GetPalabra () const;
	/**
		*@brief Consultor de las definiciones del objeto
		*@return Un vector dinámico de string con las definiciones
	*/
	Vector_Dinamico<string> GetDefiniciones () const;
	/**
		*@brief Consultor del número de definiciones
		*@return Un entero que representa el número de definiciones del término
	*/
	int GetNumeroDefiniciones () const;
	/**
		*@brief Modificador de la palabra
		*@param p Nueva palabra del objeto
	*/
	void SetPalabra (string p);
	/**
		*@brief Modificador de las definiciones
		*@param defs Vector dinámico de string con las nuevas definiciones el objeto
	*/
	void SetDefiniciones (Vector_Dinamico<string> defs);
	/**
		*@brief Añade una definición al término, conservando las anteriores
		*@param def Definición a añadir
	*/
	void AniadeDefinicion (string def);
	/**
		*@brief Operador de asignación
		*@param t Término a asignar
		*@return Una referencia a *this
	*/
	Termino & operator= (const Termino & t);
	/**
		*@brief Operador + (suma). Sumar dos términos consiste en juntar sus definiciones
		*@param t Término a sumar
		*@pre Las palabras deben ser las mismas
		*@return El término suma de t con *this
	*/
	Termino operator+ (const Termino & t) const;
	/**
		*@brief Operador ==. Compara dos términos para ver si son iguales. Dos términos son iguales si sus palabras son iguales
		*@param t Término con el que comparar
		*@return True si *this y t son iguales
		*        False si no lo son
	*/
	bool operator== (const Termino & t) const;
	/**
		*@brief Operador !=. Compara dos términos para ver si son distintos. Dos términos son distintos si sus palabras son distintas
		*@param t Término con el que comparar
		*@return True si *this y t son distintos
		*        False si no lo son
	*/
	bool operator!= (const Termino & t) const;
	/**
		*@brief Operador <. Comprueba si *this es menor que t. Un término es menor que otro si va por antes que él en el orden alfabético
		*@param t Término con el que comparar
		*@return True si *this es menor que t
		*        False si no lo es
	*/
	bool operator< (const Termino & t) const;
	/**
		*@brief Operador >. Comprueba si *this es mayor que t. Un término es mayor que otro si va después que él en el orden alfabético
		*@param t Término con el que comparar
		*@return True si *this es mayor que t
		*        False si no lo es
	*/
	bool operator> (const Termino & t) const;
	/**
		*@brief Operador de extracción de flujo. Lee un término
		*@param in Flujo de entrada
		*@param t Término a leer
		*@return Una referencia al flujo in
	*/
	friend istream & operator>> (istream & in, Termino & t);
	/**
		*@brief Operador de inserción de flujo. Imprime un término
		*@param in Flujo de salida
		*@param t Término a imprimir
		*@return Una referencia al flujo out
	*/
	friend ostream & operator<< (ostream & out, Termino & t);
};

#endif

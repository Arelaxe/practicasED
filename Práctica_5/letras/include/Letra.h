/**
 * @file Letra.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera de TDA Letra
*/

#ifndef LETRA
#define LETRA

#include <iostream>

using namespace std;

/**
 * @brief Una instancia l del TDA Letra es un objeto que consta de un caracter, un número de apariciones posibles y una puntuación
*/

class Letra{
private:
	/**
	 * @page repLetra Rep del TDA Letra
	 * @section invLetra Invariante de la representación
	 *- El caracter debe ser una letra del alfabeto en mayúsculas, es decir, debe estar entre los ASCII 65-90
	 * @section faLetra Función de abstracción
	 * Un objeto válido @e rep del TDA Letra debe seguir la siguiente representación:
	 *- El caracter debe ser de tipo char, así se facilitan las operaciones con él
	 *- apariciones_posibles debe ser de tipo int
	 *- puntuacion debe ser de tipo int
	*/
	char caracter; /**< Caracter que define la letra */
	int apariciones_posibles; /**< Apariciones posibles de la letra en un conjunto */
	int puntuacion; /**< Puntuación de la letra */
public:
	/**
	 * @brief Constructor por defecto
	*/
	Letra();
	/**
	 * @brief Constructor con parámteros
	 * @param c Caracter de la letra
	 * @param a Apariciones posibles de la letra
	 * @param p Puntuación de la letra
	*/
	Letra(char c,int a, int p);
	/**
	 * @brief Consultor del caracter de la letra
	 * @return El caracter de la letra
	*/
	char GetCaracter() const;
	/**
	 * @brief Consultor de la puntuación de la letra
	 * @return La puntuación de la letra
	*/
	int GetPuntuacion() const;
	/**
	 * @brief Consultor de las apariciones posibles de la letra
	 * @return Las apariciones posibles de la letra
	*/
	int GetApariciones() const;
	
	/**
	 * @brief Operador ==. Compara dos letras para ver si son iguales. Dos letras son iguales si su caracter, puntuacion y apariciones posibles son iguales
	 * @param l Letra con la que comparar
	 * @return True si las letras son iguales.
	 *         False si no lo son
	*/
	bool operator==(const Letra & l) const;
	/**
	 * @brief Operador !=. Compara dos letras para ver si son distintas
	 * @param l Letra con la que comparar
	 * @return True si las letras son distintas.
	 *         False si no lo son
	*/
	bool operator!=(const Letra & l) const;
	/**
	 * @brief Operador <. Comprueba si *this es menor que l. Una letra es menor que otra si va antes en el orden alfabético
	 * @param l Letra con la que comparar
	 * @return True si *this es menor que l.
	 *         False si no lo es
	*/
	bool operator<(const Letra & l) const;

	/**
	 * @brief Operador de extracción de flujo. Lee una letra
	 * @param in Flujo de entrada
	 * @param l Letra a leer
	 * @return Una referencia al flujo in
	*/
	friend istream & operator>>(istream & in, Letra & l);
	/**
	 * @brief Operador de inserción de flujo. Imprime una letra
	 * @param out Flujo de salida
	 * @param l Letra a imprimir
	 * @return una referencia al flujo out
	*/
	friend ostream & operator<<(ostream & out, const Letra & l);
};

#endif

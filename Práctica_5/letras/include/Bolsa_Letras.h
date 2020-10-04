/**
 * @file Bolsa_Letras.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Bolsa_Letras
*/

#ifndef BOLSA_LETRAS
#define BOLSA_LETRAS

#include "Letra.h"
#include "Conjunto_Letras.h"
#include <unordered_set>
#include <set>
#include <iostream>

/**
 * @brief Una instancia b del TDA Bolsa_Letras es un contenedor unordered_multiset con datos de tipo char
*/

class Bolsa_Letras{
private:
	/**
	 * @page repBolsa_Letras Rep del TDA Bolsa_Letras
	 * @section invBolsa_Letras Invariante de la representación
	 *- Todos los caracteres de la bolsa deben ser letras mayúsculas, es decir, deben estar entre los ASCII 65-90
	 * @section faBolsa_Letras Función de abstracción
	 * Un objeto válido @e rep del TDA Bolsa_Letras debe seguir la siguiente representación:
	 *- Está formado por un unordered_multiset (STL) de char, que permite que los caracteres no estén ordenados y poder tener caracteres repetidos
	*/
	unordered_multiset<char> bolsa; /**< Bolsa de letras */
public:
	/**
	 * @brief Constructor por defecto
	*/
	Bolsa_Letras();
	/**
	 * @brief Constructor con un parámetro, forma una bolsa de letras a partir de un conjunto de letras
	 * @param c Conjunto de letras a partir del cuál se formará la bolsa
	*/
	Bolsa_Letras(Conjunto_Letras c);

	/**
	 * @brief Método consultor del total de letras de la bolsa
	 * @return El número de letras de la bolsa
	*/
	int GetTotalLetras() const;
	/**
	 * @brief Método que saca aleatoriamente una letra de la bolsa, es decir, la devuelve y la elimina de ésta
	 * @return La letra sacada
	*/
	char SacaUnaLetra();

	/**
	 * @brief Operador de inserción de flujo. Imprime una bolsa de letras
	 * @param out Flujo de salida
	 * @param b Bolsa a imprimir
	 * @return Una referencia al flujo out
	*/
	friend ostream & operator<<(ostream & out, const Bolsa_Letras & b);
};

#endif

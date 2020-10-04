/**
 * @file Conjunto_Letras.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Conjunto_Letras
*/

#ifndef CONJUNTO_LETRAS
#define CONJUNTO_LETRAS

#include "Letra.h"
#include <string>
#include <cctype>
#include <set>

using namespace std;

/**
 * @brief Una instancia c del TDA Conjunto_Letras es un contenedor set con datos de tipo Letra
*/

class Conjunto_Letras{
private:
	/**
	 * @page repConjunto_Letras Rep del TDA Conjunto_Letras
	 * @section invConjunto_Letras Invariante de la representación
	 *- No puede haber letras repetidas
	 *- No puede haber dos o más letras que tengan el mismo caracter pero distinto número de apariciones posibles y/o puntuación
	 *- Todas las letras del conjunto deben ser letras válidas (véase TDA Letra)
	 * @section faConjunto_Letras Función de abstracción
	 * Un objeto válido @e rep del TDA Conjunto_Letras debe seguir la siguiente representación:
	 *- Está formado por un set (STL) de Letra, que permite que las letras estén ordenadas alfabéticamente y no puedan estar repetidas. De esta forma se pueden consultar sus datos muy fácilmente
	*/
	set<Letra> conjunto; /**< Conjunto de letras */
public:
	/**
	 * @brief Método que calcula la puntuación de una palabra según los datos del conjunto de letras
	 * @param palabra Palabra a la cuál se le calculará la puntuación
	 * @return La puntuación de la palabra
	 * @pre La palabra debe estar formada por las letras del conjunto
	*/
	int CalcularPuntuacion(const string palabra) const;
	/**
	 * @brief Método que encuentra una letra en el conjunto de letras a partir de su carácter
	 * @param letra Caracter de la letra a encontrar
	 * @return La letra
	 * @pre La letra debe estar en el conjunto
	*/
	Letra EncuentraLetra(char letra) const;

	/**
	 * @brief Operador de extracción de flujo. Lee un conjunto de letras
	 * @param in Flujo de entrada
	 * @param c Conjunto a leer
	 * @return Una referencia al flujo in
	*/
	friend istream & operator>>(istream & in, Conjunto_Letras & c);
	/**
	 * @brief Operador de inserción de flujo. Imprime un conjunto de letras
	 * @param out Flujo de salida
	 * @param c Conjunto a imprimir
	 * @return Una referencia al flujo out
	*/
	friend ostream & operator<<(ostream & out, const Conjunto_Letras & c);

	/**
	 * @brief Iterador del conjunto de letras. Itera por las letras de éste
	*/
	typedef set<Letra>::iterator iterator;
	/**
	 * @brief Iterador constante del conjunto de letras. Itera por las letras de éste
	*/
	typedef set<Letra>::const_iterator const_iterator;
	/**
	 * @brief Método begin del iterador del conjunto de letras
	 * @return Un iterador a la primera letra del conjunto
	*/
	Conjunto_Letras::iterator begin();
	/**
	 * @brief Método begin del iterador constante del conjunto de letras
	 * @return Un iterador constante a la primera letra del conjunto
	*/
	Conjunto_Letras::const_iterator begin() const;
	/**
	 * @brief Método end del iterador del conjunto de letras
	 * @return Un iterador al final del contenedor set de letras (no a la última letra del conjunto)
	*/
	Conjunto_Letras::iterator end();
	/**
	 * @brief Método end del iterador constante del conjunto de letras
	 * @return Un iterador constante al final del contenedor set de letras (no a la última letra del conjunto)
	*/
	Conjunto_Letras::const_iterator end() const;
};

#endif

/**
 * @file Diccionario.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera de TDA Diccionario
*/

#ifndef DICCIONARIO
#define DICCIONARIO

#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include "Termino.h"

using namespace std;

/**
 * @brief Una instancia d del TDA Diccionario es un objeto que consta de un contenedor set que contiene objetos de la clase Termino
*/

class Diccionario{
private:
	/**
	 * @page repDiccionario Rep del TDA Diccionario
	 * @section invDiccionario Invariante de la representación
	 *- Los términos del diccionario deben estar ordenados alfabéticamente
	 *- No puede haber términos vacíos en el diccionario ni tampoco términos repetidos (que tengan la misma palabra)
	 * @section faDiccionario Función de abstracción
	 * Un objeto válido @e rep del TDA Diccionario debe seguir la siguiente representación:
	 *- El dato miembro diccionario es un contenedor set que contiene objetos de la clase Termino. Esto facilita las inserciones de términos alfabéticamente.
	*/
	set<Termino> diccionario; /**< Contenedor set con los términos del diccionario */
public:
	/**
	 * @brief Constructor por defecto
	*/
	Diccionario();
	/**
	 * @brief Constructor con un parámetro
	 * @param terminos Contenedor set con los términos del diccionario
	*/
	Diccionario(set<Termino> terminos);
	/**
	 * @brief Constructor de copia
	 * @param otro Diccionario que se va a copiar en this
	*/
	Diccionario(const Diccionario & otro);
	/**
	 * @brief Consultor de definiciones asignadas a una palabra
	 * @param palabra Palabra a la que se le buscarán las definiciones
	 * @return Vector con las definiciones asociadas a la palabra
	 * @pre Si la palabra no se encuentra en el diccionario (o su término no contiene definiciones), se devolverá basura
	*/
	vector<string> GetDefiniciones(string palabra) const;
	/**
	 * @brief Consultor de términos del diccionario
	 * @return Contenedor set con lso términos del diccionario
	*/
	set<Termino> GetTerminos() const;
	/**
	 * @brief Consultor del número de términos del diccionario
	 * @return Número de términos del diccionario
	*/
	int GetNumeroTerminos() const;
	/**
	 * @brief Modificador que añade un nuevo término al diccionario
	 * @param t Término a añadir
	*/
	void AniadeTermino(const Termino t);
	/**
	 * @brief Modificador que elimina un término del diccionario
	 * @param t Término a eliminar
	*/
	void EliminaTermino(const Termino t);

	/**
	 * @brief Operador de extracción de flujo. Lee un diccionario
	 * @param in Flujo de entrada
	 * @param d Diccionario a leer
	 * @return Una referencia al flujo in
	*/
	friend istream & operator>>(istream & in, Diccionario & d);
	/**
	 * @brief Operador de inserción de flujo. Imprime un diccionario
	 * @param out Flujo de salida
	 * @param d Diccionario a imprimir
	 * @return Una referencia al flujo out
	*/
	friend ostream & operator<<(ostream & out, const Diccionario & d);
	
	/**
	 * @brief Iterador del diccionario (itera por los términos de éste)
	*/
	typedef set<Termino>::iterator iterator;
	/**
	 * @brief Iterador constante del diccionario (itera por los términos de éste)
	*/
	typedef set<Termino>::const_iterator const_iterator;
	/**
	 * @brief Método begin del iterador del diccionario
	 * @return Un iterador al primer término del diccionario
	*/
	Diccionario::iterator begin();
	/**
	 * @brief Método begin del iterador constante del diccionario
	 * @return Un iterador constante al primer término del diccionario
	*/
	Diccionario::const_iterator begin() const;
	/**
	 * @brief Método end del iterador del diccionario
	 * @return Un iterador al final del contenedor set de términos (no al último término del diccionario)
	*/
	Diccionario::iterator end();
	/**
	 * @brief Método end del iterador constante del diccionario
	 * @return Un iterador constante al final del contenedor set de términos (no al último término del diccionario)
	*/
	Diccionario::const_iterator end() const;

	/**
	 * @brief Construye un subdiccionario de términos comprendidos entre 2 caracteres
	 * @param inicio Primer caracter del subdiccionario
	 * @param fin Último caracter del diccionario. También están incluidos los términos cuyas palabras empiecen por este caracter
	 * @return El subdiccionario comprendido entre los caracteres
	*/
	Diccionario FiltraPorIntervalo(char inicio, char fin);
	/**
	 * @brief Construye un subdiccionario con los términos que contengan la palabra pasada como argumento en alguna de sus definiciones. Sólo serán incluidas las definiciones que la contengan
	 * @param palabra Palabra que filtrará los términos que formarán parte del subdiccionario
	* @return El subdiccionario con los términos cuyas definiciones contengan la palabra
	*/
	Diccionario FiltraPorPalabraClave(string palabra);	
	/**
	 * @brief Hace diversos cálculos que tienen que ver con las definiciones de los términos el diccionario
	 * @param total_defs (Referencia) Total de definiciones del diccionario
	 * @param max_defs_palabra (Referencia) Máximo de definiciones que contiene un término
	 * @param promedio_defs (Referencia) Promedio de definiciones de un término
	 * @return (Por referencia) Los parámetros mencionados anteriormente, pero con los valores correctos
	*/
	void RecuentoDefiniciones(int & total_defs, int & max_defs_palabra, float & promedio_defs);
};

#endif

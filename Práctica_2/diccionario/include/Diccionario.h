/**
 * @file Diccionario.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Diccionario
*/


#ifndef DICCIONARIO
#define DICCIONARIO

#include <string>
#include "Termino.h"
#include "Lista.h"
#include "Vector_Dinamico.h"

/**
	*@brief Una instancia d del TDA Diccionario es un objeto que consta de una lista de objetos de la clase Termino
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
	*- El dato miembro terminos es una Lista de objetos de la clase Termino. Esto facilita las inserciones de términos alfabéticamente
	*/
	Lista<Termino> terminos; /**< Lista de términos del diccionario */
public:
	/**
		*@brief Constructor por defecto
	*/
	Diccionario ();
	/**
		*@brief Constructor con un parámetro
		*@param tnos Lista de términos del diccionario
	*/
	Diccionario (Lista<Termino> tnos);
	/**
		*@brief Constructor de copia
		*@param otro Diccionario que se va a copiar en this
	*/
	Diccionario (const Diccionario & otro);
	/**
		*@brief Operador de asignación
		*@param d Diccionario a asignar
		*@return Una referencia a *this
	*/
	Diccionario & operator= (const Diccionario & d);
	/**
		*@brief Consultor de las definiciones de un término
		*@param t Termino del cuál se quiere consultar las definiciones
		*@return Vector_Dinamico de las definiciones del Termino
	*/
	Vector_Dinamico<string> GetDefiniciones (Termino t) const;
	/**
		*@brief Consultor de términos del Diccionario
		*@return Lista de términos del Diccionario
	*/
	Lista<Termino> GetTerminos () const;
	/**
		*@brief Consultor del número de términos del Diccionario
		*@return Número de términos del Diccionario
	*/
	int GetNumeroTerminos () const;
	/**
		*@brief Modificador que añade un nuevo Termino al Diccionario
		*@param t Termino a añadir
	*/
	void AniadeTermino (Termino t);
	/**
		*@brief Modificador que elimina un Termino del Diccionario
		*@param t Termino a eliminar
	*/
	void EliminaTermino (Termino t);
	/**
		*@brief Operador de extracción de flujo. Lee un diccionario
		*@param in Flujo de entrada
		*@param d Diccionario a leer
		*@return Una referencia al flujo in
	*/
	friend istream & operator>> (istream & in, Diccionario & d);
	/**
		*@brief Operador de inserción de flujo. Imprime un diccionario
		*@param out Flujo de salida
		*@param d Diccionario a imprimir
		*@return Una referencia al flujo out
	*/
	friend ostream & operator<< (ostream & out, Diccionario & d);
	/**
		*@brief Construye un subdiccionario de términos comprendidos entre 2 caracteres
		*@param caracter_inicio Primer caracter del subdiccionario
		*@param caracter_fin Último caracter del diccionario. También están icluidos los términos cuyas palabras empiecen por este caracter
		*@return El subdiccionario comprendido entre los caracteres
	*/
	Diccionario Intervalo (char caracter_inicio, char caracter_fin);
	/**
		*@brief Construye un subdiccionario con los términos que contengan la palabra pasada como argumento en alguna de sus definiciones. Sólo serán incluidas las definiciones que la contengan
		*@param palabra Palabra que filtrará los términos que formarán parte del subdiccionario
		*@return El subdiccionario con los términos cuyas definiciones contengan la palabra
	*/
	Diccionario PalabraClave (string palabra);
	/**
		*@brief Hace diversos cálculos que tienen que ver con las definiciones de los términos del Diccionario
		*@param total_definiciones (Referencia) Total de definiciones del diccionario
		*@param max_defs_palabra (Referencia) Máximo de definiciones que contiene un Termino
		*@param promedio_defs (Referencia) Promedio de definiciones de un Termino
		*@return (Por referencia) Los parámetros mencionados anteriormente, pero con los valores correctos
	*/
	void RecuentoDefiniciones (int & total_definiciones, int & max_defs_palabra, float & promedio_defs);
};

#endif

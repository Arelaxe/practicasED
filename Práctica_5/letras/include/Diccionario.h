/**
 * @file Diccionario.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Diccionario
*/

#ifndef DICCIONARIO
#define DICCIONARIO

#include <vector>
#include <set>
#include <list>
#include "Conjunto_Letras.h"
#include <string>

using namespace std;

/**
 * @brief Una instancia d del TDA Diccionario es un contenedor set con datos de tipo string, que son las palabras que forman el diccionario
*/

class Diccionario{
private:
	/**
	 * @page repDiccionario Rep del TDA Diccionario
	 * @section invDiccionario Invariante de la representación
	 *- Se debe cumplir que los string estén ordenados alfabéticamente, lo cual está garantizado gracias al contenedor set
	 *- No debe haber palabras vacías
	 *- No puede haber palabras repetidas. Esto también lo garantiza el set
	 * @section faDiccionario Función de abstracción
	 * Un objeto válido @e rep del TDA Diccionario debe seguir la siguiente representación:
	 *- Está formado por un set (STL) de string, que permite que las string (palabras) estén ordenadas alfabéticamente
	*/
	set<string> datos; /**< Conjunto de palabras */
public:
	/**
	 * @brief Constructor por defecto
	*/
	Diccionario();
	/**
	 * @brief Consultor del tamaño del diccionario
	 * @return El número de palabras del diccionario
	*/
	int size() const;
	/**
	 * @brief Método que halla las palabras de una determinada longitud
	 * @param longitud La longitud de las palabras que se quieren consultar
	 * @return Las palabras de dicha longitud
	*/
	vector<string> PalabrasLongitud(int longitud) const;
	/**
	 * @brief Método que comprueba si una palabra está en el diccionario
	 * @param palabra Palabra a consultar
	 * @return True si palabra está en el diccionario. False si no lo está
	*/
	bool Esta(string palabra) const;
	/**
	 * @brief Comprueba si una palabra es válida, es decir, si se puede formar con las letras de la lista y está en el diccionario
	 * @param palabra Palabra a comprobar si es válida
	 * @param lista Lista de letras de las que deberá estar formada la palabra
	 * @return True si la palabra es válida. False si no lo es
	 * @pre Los caracteres de la lista deben ser letras
	*/
	bool PalabraValida(const string palabra, const list<char> lista) const;
	/**
	 * @brief Método que forma palabras que están en el diccionario a partir de una lista de letras
	 * @param lista Lista de letras con las que formar palabras
	 * @return Todas las palabras del diccionario que se pueden formar con las letras de la lista
	 * @pre Los caracteres de la lista deben ser letras
	*/
	list<string> FormaPalabras(const list<char> lista) const;
	/**
	 * @brief Método que forma las palabras de máxima puntuación con las letras de una lista
	 * @param lista Lista de letras con las que formar palabras
	 * @param c Conjunto de letras del que coger la puntuación de las letras
	 * @return Las palabras de máxima puntuación del diccionario que se pueden formar con las letras de la lista
	 * @pre Los caracteres de la lista deben ser letras
	 * @pre Las letras de la lista deben estar en el conjunto
	*/
	list<string> FormaPalabrasMaxPuntuacion(const list<char> lista, const Conjunto_Letras c) const;
	/**
	 * @brief Método que forma las palabras de máxima longitud con las letras de una lista
	 * @param lista Lista de letras con las que formar palabras
	 * @return Las palabras de máxima longitud del diccionario que se pueden formar con las letras de la lista
	 * @pre Los caracteres de la lista deben ser letras
	 * @pre Las letras de la lista deben estar en el conjunto
	*/
	list<string> FormaPalabrasMaxLongitud(const list<char> lista) const;

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
	 * @brief Iterador del diccionario (itera por las palabras de éste)
	*/
	typedef set<string>::iterator iterator;
	/**
	 * @brief Iterador constante del diccionario (itera por las palabras de éste)
	*/
	typedef set<string>::const_iterator const_iterator;
	/**
	 * @brief Método begin del iterador del diccionario
	 * @return Un iterador a la primera palabra del diccionario
	*/
	Diccionario::iterator begin();
	/**
	 * @brief Método begin del iterador constante del diccionario
	 * @return Un iterador constante la primera palabra del diccionario
	*/
	Diccionario::const_iterator begin() const;
	/**
	 * @brief Método end del iterador del diccionario
	 * @return Un iterador al final del contenedor set de string (no al último string del diccionario)
	*/
	Diccionario::iterator end();
	/**
	 * @brief Método end del iterador constante del diccionario
	 * @return Un iterador constante al final del contenedor set de string (no al último string del diccionario)
	*/
	Diccionario::const_iterator end() const;
};

#endif

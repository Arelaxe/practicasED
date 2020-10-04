/**
 * @file Termino.h
 * @author Noelia Escalera Mejías
 * @brief Fichero cabecera del TDA Termino
*/

#ifndef TERMINO
#define TERMINO

#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Una instancia t del TDA Termino es un objeto compuesto por una pareja (pair), cuyo primer campo es un string que simboliza una palabra y cuyo segundo campo es un vector de string compuesto por definiciones
*/

class Termino{
private:
	/**
	 * @page repTermino Rep del TDA Termino
	 * @section invTermino Invariante de la representación
	 * Se debe cumplir que si termino.second no está vacío, termino.first tampoco debe estarlo
	 * @section faTermino Función de abstracción
	 * Un objeto válido @e rep del TDA Termino debe seguir la siguiente representación:
	 *El dato miembro termino es un pair de string y vector<string>, donde:
	 *- termino.first representa la palabra y es un string
	 *- termino.second es un vector (STL) que contiene datos de tipo string. Cada string es una definición de término
	*/
	pair<string,vector<string>> termino; /**< Término: Pareja palabra/definiciones */
public:
	/**
	 * @brief Constructor por defecto
	*/
	Termino();
	/**
	 * @brief Constructor con dos parámetros
	 * @param palabra Palabra del término
	 * @param defs Vector de definiciones del término
	*/
	Termino(string palabra, vector<string> defs);
	/**
	 * @brief Constructor de copia
	 * @param otro Término que se va a copiar en this
	*/
	Termino(const Termino & otro);
	/**
	 * @brief Consultor de la palabra del objeto
	 * @return Un vector dinámico de string con las definiciones
	*/
	string GetPalabra() const;
	/**
	 * @brief Consultor de las definiciones del objeto
	 * @return Un vector de string con las definiciones
	*/
	vector<string> GetDefiniciones() const;
	/**
	 * @brief Consultor del número de definiciones
	 * @return Un entero que representa el número de definiciones del término
	*/
	int GetNumeroDefiniciones() const;
	/**
	 * @brief Modificador de la palabra
	 * @param palabra Nueva palabra del objeto
	*/
	void SetPalabra(string palabra);
	/**
	 * @brief Modificador de las definiciones
	 * @param definiciones Vector dinámico de string con las nuevas definiciones del objeto
	*/
	void SetDefiniciones(vector<string> definiciones);
	/**
	 * @brief Añade una definición al término, conservando las anteriores
	 * @param def Definición a añadir
	*/
	void AniadeDefinicion(string def);

	/**
	 * @brief Operador de asignación
	 * @param otro Término a asignar
	 * @return Una referencia a this
	*/
	Termino & operator=(const Termino & otro);
	/**
	 * @brief Operador ==. Compara dos términos para ver si son iguales. Dos términos son iguales si sus palabras son iguales
	 * @param t Término con el que comparar
	 * @return True si this y t son distintos
	 *         False si no lo son
	*/
	bool operator==(const Termino & t) const;
	/**
	 * @brief Operador !=. Compara dos terminos para ver si son distintos. Dos términos son distintos si sus palabras son distintas
	 * @param t Término con el que comparar
	 * @return True si this y t son distintos
	 *         False si no lo son
	*/
	bool operator!=(const Termino & t) const;
	/**
	 * @brief Operador <. Comprueba si this es menor que t. Un término es menor que otro si va antes que él en el orden alfabético
	 * @param t Término con el que comparar
	 * @return True si this es mayor que t
	 *         False si no lo es
	*/
	bool operator<(const Termino & t) const;
	/**
	 * @brief Operador >. Comprueba si this es mayor que t. Un término es mayor que otro si va después que él en el orden alfabético
	 * @param t Término con el que comparar
	 * @return True si this es mayor que t
	 *         False si no lo es
	*/
	bool operator>(const Termino & t) const;
	/**
	 * @brief Operador de extracción de flujo. Lee un término
	 * @param in Flujo de entrada
	 * @param t Término a leer
	 * @return Una referencia al flujo in
	*/
	friend istream & operator>>(istream & in, Termino & t);
	/**
	 * @brief Operador de inserción de flujo. Imprime un término
	 * @param out Flujo de salida
	 * @param t Término a imprimir
	 * @return Una referencia al flujo out
	*/
	friend ostream & operator<<(ostream & out, const Termino & t);

	/**
	 * @brief Iterador del término (itera entre las definiciones)
	*/
	typedef vector<string>::iterator iterator;
	/**
	 * @brief Iterador constante del término (itera entre las definiciones)
	*/
	typedef vector<string>::const_iterator const_iterator;
	/**
	 * @brief Método begin del iterador del término
	 * @return Un iterador a la primera definición del término
	*/
	Termino::iterator begin();
	/**
	 * @brief Método begin del iterador constante del término
	 * @return un iterador constante a la primera definición del término
	*/
	Termino::const_iterator begin() const;
	/**
	 * @brief Método end del iterador del término
	 * @return Un iterador al final del vector de definiciones (no la última definición)
	*/
	Termino::iterator end();
	/**
	 * @brief Método end del iterador constante del término
	 * @return Un iterador constante al final del vector de definiciones (no la última definición)
	*/
	Termino::const_iterator end() const;
};

#endif

/**
 * @file Lista.h
 * @brief Fichero cabecera del TDA Lista
*/

#ifndef LISTA
#define LISTA

template <class T>
void intercambiar (T p, T q);

/**
	*@brief Una instancia c del struct CeldaLista es un objeto que contiene un elemento de tipo T y un puntero a la celda anterior y otro a la celda siguiente de la lista a la que pertenece
*/
template <class T>
struct CeldaLista{
  /**
	* @page repCeldaLista Rep de CeldaLista
	* @section invCeldaLista Invariante de la representación
	*- anterior y siguiente deben apuntar a elementos de la lista a la que pertenece la celda actual
	* @section faCeldaLista Función de abstracción
	* Un objeto válido @e rep del TDA CeldaLista debe seguir la siguiente representación:
	*- El dato miembro elementos es un dato de tipo T (es decir, está parametrizado). Es el dato de la celda.
	*- El dato miembro anterior es un puntero a la celda anterior de la Lista
	*- El dato miembro siguiente es un puntero a la celda posterior de la Lista
  */
	T elemento; /**< Dato de la celda */
	CeldaLista<T> * anterior; /**< Puntero a la celda anterior*/
	CeldaLista<T> * siguiente; /**< Puntero a la celda siguiente */
};

template <class T>
class Lista;

/**
	*@brief Una instancia p de la clase Posicion es un objeto que contiene un elemento de tipo puntero a CeldaLista, que apunta a una celda de la lista
*/

template <class T>
class Posicion{
private:
	/**
	* @page repPosicion Rep de Posicion
	* @section invPosicion Invariante de la representación
	*- puntero debe apuntar a una celda de una Lista correctamente formada
	* @section faPosicion Función de abstracción
	* Un objeto válido @e rep del TDA Posicion debe seguir la siguiente representación:
	*- El dato miembro puntero es un puntero a un dato de tipo CeldaLista parametrizado
  */
	CeldaLista<T> * puntero; /**< Puntero a la celda de la Lista */
public:
	/**
	*@brief Constructor por defecto
	*/
	Posicion();
	/**
	*@brief Operador de asignación
	*@param p Posición a asignar
	*/
	Posicion<T> & operator= (const Posicion<T> & p);
	/**
	*@brief Operador de incremento prefijo. Incrementar una posición significa pasar a la posición siguiente
	*@return La posición incrementada
	*/
	Posicion<T> & operator++ ();
	/**
	*@brief Operador de incremento postfijo. Incrementar una posición significa pasar a la posición siguiente
	*@return La posición antes de ser incrementada
	*/
	Posicion<T> operator++ (int);
	/**
	*@brief Operador de decremento prefijo. Decrementar una posición significa pasar a la posición anterior
	*@return La posición decrementada
	*/
	Posicion<T> & operator-- ();
	/**
	*@brief Operador de decremento postfijo. Decrementar una posición significa pasar a la posición anterior
	*@return La posición antes de ser decrementada
	*/
	Posicion<T> operator-- (int);
	/**
	*@brief Operador ==. Compara dos posiciones para ver si son iguales. Dos posiciones son iguales si apuntan al mismo elemento
	*@param p La posición con la que se comparará
	*@return True si p es igual que *this
	*        False si p no es igual que *this
	*/
	bool operator== (const Posicion<T> & p) const;
	/**
	*@brief Operador !=. Compara dos posiciones para ver si son distintas. Dos posiciones son distintas si no apuntan al mismo elemento
	*@param p La posición con la que se comparará
	*@return True si p es distinto de *this,
	*        False si p no es distinto de *this
	*/
	bool operator!= (const Posicion<T> & p) const;
	friend class Lista<T>;
};

	/**
	*@brief Una instancia l de la clase Lista está formada por una cabecera, que es un puntero a la primera celda de la Lista. La Lista en sí, es una sucesión de celdas enlazadas de tipo CeldaLista. La lista es de tipo circular, es decir, cada celda apunta a la posición anterior y a la siguiente
	*/
template <class T>
class Lista{
private:
	/**
	* @page repLista Rep de Lista
	* @section invLista Invariante de la representación
	*- cabecera debe apuntar a la primera celda (la que se devuelve con begin()) de una lista formada correctamente
	*- El puntero anterior de la primera celda apuntará a la última celda
	*- El puntero siguiente de la última celda apuntará a la primera celda
	* @section faLista Función de abstracción
	* Un objeto válido @e rep del TDA Lista debe seguir la siguiente representación:
	*- El dato miembro cabecera es un puntero a la primera celda de la Lista
  */
	CeldaLista<T> * cabecera; /**< Puntero a la primera celda de la Lista */
public:
	/**
	@brief Constructor por defecto
	*/
	Lista();
	/**
	@brief Constructor de copia
	@param l Lista que se va a copiar en this
	*/
	Lista (const Lista<T> & l);
	/**
	@brief Destructor. Libera la memoria ocupada por la lista
	*/
	~Lista();
	/**
	@brief Operador de asignación
	@param l Lista a asignar
	@return Una referencia a *this
	*/
	Lista<T> & operator= (const Lista<T> & l);
	/**
	@brief Modificador que cambia el valor de un elemento de la lista
	@param p Posición de la celda en la que está el elemento a cambiar
	@param e Nuevo elemento
	*/
	void set (Posicion<T> p, T e);
	/**
	@brief Consultor que devuelve lo que hay en una posición determinada
	@param p Posición que se consultará
	@return El elemento de la posición consultada
	*/
	T get (Posicion<T>) const;
	/**
	@brief Modificador que inserta un nuevo elemento en la lista
	@param p Posición en la que se insertará la nueva celda
	@param e Nuevo elemento
	@return La posición en la que se ha insertado
	*/
	Posicion<T> insertar (Posicion<T> p, T e);
	/**
	@brief Modificador que borra una celda de la lista
	@param p Posición de la celda a borrar
	@return La posición en la que se ha borrado
	*/
	Posicion<T> borrar (Posicion<T> p);
	/**
	@brief Consultor del primer elemento de la lista
	@return La posición del primer elemento de la lista
	*/
	Posicion<T> begin () const;
	/**
	@brief Consultor de la última celda de la lista
	@return La última celda de la lista
	*/
	Posicion<T> end () const;
	/**
	@brief Consultor del número de elementos de la lista
	@return El número de elementos de la lista
	*/
	int GetNumeroElementos () const;
};

#include "Lista.cpp"
#endif

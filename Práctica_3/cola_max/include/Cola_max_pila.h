/**
 * @file Cola_max_pila.h
 * @brief Fichero cabecera del TDA Cola_max_pila
 * @author Noelia Escalera Mejías 
*/

#ifndef COLA_MAX_PILA
#define COLA_MAX_PILA

#include <stack>

using namespace std;

/**
 * @brief Una instancia p del struct Pareja es un objeto que contiene dos elementos de tipo T. Se usa para representar las celdas de Cola_max. El primer dato miembro es el dato correspondiente a la celda y el segundo es el máximo de la cola 
*/

template <class T>
struct Pareja{
    /**
     * @page repPareja Rep de Pareja
     * @section invPareja Invariante de la representación
     * - max debe estar actualizado en todo momento
     * @section faPareja Función de abstracción
     * Un objeto válido @e rep del struct Pareja debe seguir la siguiente representación:
     * - dato es el elemento de la celda de la cola que representa la Pareja
     * - max es el máximo de la cola
	*/
	T dato; /**< Elemento de la celda */
	T max; /**< Máximo de la cola */
};

/**
 * @brief Una instancia c de la clase Cola_max (implementada con pilas) es un objeto que contiene dos elementos de la clase stack de la STL. La primera pila se usará para la entrada de datos y la segunda para la salida de datos 
*/

template <class T>
class Cola_max{
private:
    /**
     * @page repCola_max Rep de Cola_max
     * @section invCola_max Invariante de la representación
     * - La pila entrada sólo se utiliza para operaciones de entrada de datos o como pila auxiliar
     * - La pila salida sólo se utiliza para operaciones de salida o como pila auxiliar
     * - Las inserciones y extracciones deben seguir el orden FIFO
     * @section faCola_max Función de abstracción
     * Un objeto válido @e rep del TDA Cola_max (con pilas) debe seguir la siguiente representación:
     * - Debe tener una pila entrada para la entrada de datos
     * - Debe tener una pila salida para la salida de datos
    */
	stack<Pareja<T>> entrada; /**< Pila para la entrada de datos */
	stack<Pareja<T>> salida; /**< Pila para la salida de datos */
public:
    /**
     * @brief Constructor por defecto de la clase 
    */
	Cola_max();
    /**
     * @brief Añade un elemento al final de la cola
     * @param elemento Elemento a añadir 
    */
	void poner (T elemento);
    /**
     * @brief Quita el primer elemento de la cola 
    */
	void quitar ();
    /**
     * @brief Consultor del máximo de la cola
     * @return El máximo de la cola 
    */
	const T maximo ();
    /**
     * @brief Consultor del número de elementos de la cola
     * @return El número de elementos de la cola 
     * @pre Al menos una de las dos pilas debe no estar vacía
    */
	int num_elementos ();
    /**
     * @brief Consultor del frente de la cola
     * @return El primer elemento de la cola 
    */
	const T frente ();
    /**
     * @brief Método que comprueba si la cola está vacía
     * @return True si la cola está vacía
     *         \n False si no lo está 
    */
	bool vacia ();
private:
    /**
     * @brief Método auxiliar que actualiza el máximo de la cola
     * @param nuevo_maximo Nuevo máximo de la cola 
    */
	void actualizar_maximo (T nuevo_maximo);

	/**
     * @brief Método auxiliar que actualiza el máximo parcial de la cola
     * @param nuevo_maximo Nuevo máximo parcial de la cola 
    */
	void actualizar_maximo_intervalo (T nuevo_maximo);
    /**
     * @brief Método auxiliar que vuelca una pila en otra. Se usa principalmente para realizar correctamente la entrada/salida de datos
     * @param a_volcar Pila que se va a volcar
     * @param volcada Pila en la que se volcará 
    */
	void volcar_pila (stack<Pareja<T>> & a_volcar, stack<Pareja<T>> & volcada);
};


#include "Cola_max_pila.cpp"

#endif

/**
 * @file Cola_max_vd.h
 * @brief Fichero cabecera del TDA Cola_max_vd
 * @author Noelia Escalera Mejías 
*/

#ifndef COLA_MAX_VD
#define COLA_MAX_VD

#include <vector>

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
 * @brief Una instancia c de la clase Cola_max (implementada con vector dinámico) es un objeto que contiene un elemento de la clase vector de STL, que funciona como envoltorio para datos de tipo Pareja  
*/

template <class T>
class Cola_max{
private:
    /**
     * @page repCola_max Rep de Cola_max
     * @section invCola_max Invariante de la representación
     * - El vector que envuelve los datos debe ser en todo momento una cola correcta y seguir el orden FIFO en la inserción y extracción de datos
     * @section faCola_max Función de abstracción
     * Un objeto válido @e rep del TDA Cola_max (con vector dinámico) debe seguir la siguiente representación:
     * - Debe tener un vector que almacena los datos, sobre el que se harán todas las operacines de la cola
    */
	vector<Pareja<T>> datos; /**< Vector que almacena los datos de tipo Pareja<T> */
public:
    /**
     * @brief Constructor por defecto de la clase 
    */
    Cola_max ();
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
	const T & maximo ();
    /**
     * @brief Consultor del número elementos de la cola
     * @return El número de elementos de la cola
    */
	int num_elementos ();
    /**
     * @brief Consultor del frente de la cola
     * @return El primer elemento de la cola 
    */
	const T & frente ();
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
	void actualizar_maximo(T nuevo_maximo);

	/**
     * @brief Método auxiliar que actualiza parcialmente el máximo de la cola
     * @param nuevo_maximo Nuevo máximo parcial de la cola 
    */
	void actualizar_maximo_intervalo(T nuevo_maximo);
};

#include "Cola_max_vd.cpp"

#endif

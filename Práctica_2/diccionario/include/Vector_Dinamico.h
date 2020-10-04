/**
 * @file Vector_Dinamico.h
 * @brief Fichero cabecera del TDA Vector_Dinamico
*/

#ifndef VectorDinamico_h
#define VectorDinamico_h

/**
	*@brief Una instancia v del TDA Vector_Dinamico es un objeto compuesto por un puntero a los datos miembro de un array (es decir, un vector dinámico clásico) y el número de elementos de dicho array.
*/

template <class T>
class Vector_Dinamico{
private:
  /**
	* @page repVector_Dinamico Rep del TDA Vector_Dinamico
	* @section invVector_Dinamico Invariante de la representación
	*- nelementos siempre debe ser igual al tamaño del vector datos
	*- nelementos debe ser mayor que 0
	* @section faVector_Dinamico Función de abstracción
	* Un objeto válido @e rep del TDA Vector_Dinamico debe seguir la siguiente representación:
	*- El dato miembro datos es un puntero a datos de tipo T (es decir, el tipo está parametrizado). En otras palabras, un vector dinámico
	*- El dato miembro nelementos es un entero con el tamaño del vector dinámico datos
  */
  T * datos; /**< Vector dinámico con los datos */
  int nelementos; /**< Número de elementos del vector dinámico */

public:
  /**
	*@brief Constructor por defecto
	*@param n (Opcional, 0 por defecto) Número de elementos inicial del vector
  */
  Vector_Dinamico<T>(int n=0);
   /**
	*@brief Constructor de copia
	*@param original Vector_Dinamico que se copiará en this
  */
  Vector_Dinamico<T>(const Vector_Dinamico & original);
  /**
	*@brief Destructor. Libera la memoria ocupada por el objeto
  */
  ~Vector_Dinamico<T>();
  /**
	*@brief Consultor del tamaño del vector
	*@return El tamaño del vector
  */
  int size() const;
  /**
	*@brief Redimensiona el vector
	*@param n Nuevo tamaño del vector
  */
  void resize(int n);
  /**
	*@brief Añade un elemento al final del vector
	*@param elemento Elemento a añadir
  */
  void add (T elemento);
  /**
	*@brief Operador de acceso
    *@param i Posición del elemento que se quiere consultar
	*@return Una referencia al elemento del vector que se quiere consultar
  */
  T & operator[](const int i);
  /**
	*@brief Versión constante del operador de acceso
	*@param i Posición del elemento que se quiere consultar
	*@return Una referencia constante al elemento del vector que se quiere consultar
  */
  const T & operator[](const int i) const;
  /**
	*@brief Operador de asignación
	*@param original Vector_Dinamico a asignar
	*@return Una referencia a this
  */
  Vector_Dinamico <T>& operator=(const Vector_Dinamico<T> & original);
};

#include "Vector_Dinamico.tpp"

#endif // VectorDinamico_h

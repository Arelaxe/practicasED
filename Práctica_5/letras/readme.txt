PRÁCTICA FINAL ED. NOELIA ESCALERA MEJÍAS. GRUPO A3.

Para la realización de esta práctica, he seguido los pasos del pdf y he ido haciendo los distintos programas por separado. Primero he hecho el programa testdiccionario, para ello, he modificado ligeramente el código que venía en la página 4 del pdf para hacer el main. Luego he empezado a implementar el TDA Diccionario, me he inspirado en las páginas 8 y 9 del pdf, por lo tanto he usado un set para que así me ordene las palabras alfabéticamente. El iterador no lo he hecho como viene en el pdf, sólo he implementado los métodos begin y end (del iterador y del iterador constante) llamando a los de set, de forma que los demás métodos también los coja del iterador ya implementado de set.

Después he implementado el programa letras. Para ello, a parte del main he tenido que desarrollar tres nuevos TDA: Letra, Conjunto_Letras y Bolsa_Letras. He tenido que añadirle nuevos métodos al TDA Diccionario para poder implementar este programa: PalabraValida, FormaPalabras, FormaPalabrasMaxPuntuacion y FormaPalabrasMaxLongitud. Para el TDA Letra no he usado ninguna estructura de datos, ya que simplemente son 3 datos independientes (caracter, apariciones_posibles y puntuacion). Para el TDA Conjunto_Letras he usado de nuevo un set para tener las letras ordenadas y que no haya repetidas. Por último, para el TDA Bolsa_Letras he usado un unordered_multiset, ya que podía haber letras repetidas y no seguían un orden específico.

Para el programa cantidad_letra no he tenido que desarrollar ningún TDA nuevo ni añadir ningún método a los TDA ya desarrollados, simplemente he tenido que desarrollar un nuevo main.

Para más información mirar la documentación de los TDA y los comentarios de los cpp.

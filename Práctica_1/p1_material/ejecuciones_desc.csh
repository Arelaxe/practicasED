#!/bin/csh
@ inicio = 100
@ fin = 2000000
@ incremento = 100
set ejecutable = ejercicio_desc
set salida = tiempos_desc3.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end

#!/bin/csh
@ inicio = 100
@ fin = 2300
@ incremento = 100
set ejecutable = matrices
set salida = tiempos_matrices.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end

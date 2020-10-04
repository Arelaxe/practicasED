#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  int tam=atoi(argv[1]);     // Tamaño del vector
  int vmax=atoi(argv[2]);    // Valor máximo
  
  // Generación del vector aleatorio
  int ** m1=new int * [tam]; 
	int ** m2=new int * [tam];
	int ** resultado=new int * [tam];
	
	for (int i=0; i<tam; i++){
		m1[i] = new int [tam];
		m2[i] = new int [tam];
		resultado[i] = new int [tam];
	}
      
  srand(time(0));        
    
  for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			m1[i][j] = rand()%vmax;
			m2[i][j] = rand()%vmax;
		}			
	}
  
  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  
	for (int i=0; i<tam; ++i){
		for (int j=0; j<tam; ++j){
			for (int k=0; k<tam; ++k){
				resultado[i][j] += m1[i][k] * m2[k][j]; 
			}
		}
	}

  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
}

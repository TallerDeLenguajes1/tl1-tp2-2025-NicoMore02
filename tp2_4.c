#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ESTRUCTURAS//

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz
    int anio; // Año de fabricación
    int cantidad_nucleos;  // Cantidad de núcleos
    char *tipo_cpu; // Tipo de procesador
} typedef tCompu;


int main () {
    srand(time(NULL)); // Semilla para generar números aleatorios
    
    int total_pcs = 5;
    int i, j;
    tCompu *pc = malloc(total_pcs * sizeof(tCompu));

    //listas de cpu disponibles
    char *tipos_cpu[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium" };
    
    //generacion aleatorias de datos para las 5 computadoras
    for ( i = 0; i < total_pcs; i++)
    {
        pc[i].tipo_cpu = tipos_cpu[rand() % 6];
        pc[i].velocidad = rand() % (3 - 1 + 1) + 1;
        pc[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        pc[i].cantidad_nucleos = rad() % (8 - 1 + 1) + 1;
    }
    

}
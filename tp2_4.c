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

//FUNCIONES//
void mostrarpc(tCompu *pc, int n);
void mostrarMasVieja(tCompu *pc, int n);
void mostrarMasVeloz(tCompu *pc, int n);

int main () {
    srand(time(NULL)); // Semilla para generar números aleatorios
    
    int total_pcs = 5;
    int i, j;
    tCompu *pc = malloc(total_pcs * sizeof(tCompu));

    //listas de cpu disponibles
    char *tipos_cpu[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium" };
    
    //generacion aleatorias de datos para las 5 computadoras
    for ( i = 0; i < total_pcs; i++)
    {
        pc[i].tipo_cpu = tipos_cpu[rand() % 6];
        pc[i].velocidad = rand() % (3 - 1 + 1) + 1;
        pc[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        pc[i].cantidad_nucleos = rand() % (8 - 1 + 1) + 1;
    }

    //Muestra los datos de las 5 computadoras 
    mostrarpc(pc, total_pcs);
    //Muestra la computadora mas antigua
    mostrarMasVieja(pc, total_pcs);
    //Muestra la computadora mas veloz
    mostrarMasVeloz(pc, total_pcs);

    free(pc);
    return 0;
}

//DEFINICION

void mostrarpc(tCompu *pc, int n) {
    puts("Listados de Computadoras");
    for (int i = 0; i < n; i++)
    {
        printf("Computadora %d: \n", i + 1);
        printf("Tipo de CPU: %s \n", pc[i].tipo_cpu);
        printf("Velocidad de procesamiento: %d GHz \n", pc[i].velocidad);
        printf("Anio de fabricacion: %d \n", pc[i].anio);
        printf("Cantidad de nucleos: %d \n", pc[i].cantidad_nucleos);
        printf("\n");
    }
    
}

void mostrarMasVieja(tCompu *pc, int n) {
    int viejo = 0;
    for (int i = 1; i < n; i++)
    {
        if (pc[i].anio < pc[viejo].anio) {
            viejo = i;
        }
    }
    printf("El pc mas viejo es: \n");
    printf("Tipo de CPU: %s \n", pc[viejo].tipo_cpu);
    printf("Anio: %d\n", pc[viejo].anio);
}

void mostrarMasVeloz(tCompu *pc, int n) {
    int veloz = 0;
    for (int i = 1; i < n; i++)
    {
        if (pc[i].velocidad > pc[veloz].velocidad)
        {
            veloz = i;
        }
        
    }
    printf("La pc mas veloz es: \n");
    printf("Tipo de CPU: %s \n", pc[veloz].tipo_cpu);
    printf("Velocidad de procesamiento: %d GHz \n", pc[veloz].velocidad);
    printf("Anio de fabricacion: %d \n", pc[veloz].anio);
}
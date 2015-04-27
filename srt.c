
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tiempoActual=0;		
int numProcesos;				

typedef struct {
	char nombre[3];
	int tiempoLlegada;
	int nroRafagas;
	int tiempoInicio;
	int tiempoFinalizacion;
	int tiempoEspera;
	int tiempoActivo;
}proceso;

typedef struct {
	char nombre[3];
}nombres;


void ordenarProcesos(proceso *, int);			
int seleccionarProceso(proceso *);			
void ejecutarProcesos(proceso *, int, nombres *);		
int obtenerTotalRafagas(proceso *, int);        
void srt(proceso *, nombres *);			


int main(void) {
	proceso procesos[10];
	nombres nombresProcesos[10];
	srt(procesos, nombresProcesos);
	return EXIT_SUCCESS;
}

void ordenarProcesos(proceso procesos[], int numProcesos) {
	int i, j, test;
	proceso temp;

	for(i = numProcesos - 1; i > 0; i--) {
		test = 0;
		for(j=0; j < i; j++) {
			if((procesos[j].tiempoLlegada) > (procesos[j+1].tiempoLlegada) ) {
				temp = procesos[j];
				procesos[j] = procesos[j+1];
				procesos[j+1] = temp;
				test=1;
			}
		}
		if(test==0) break;
	}
}

int obtenerTotalRafagas(proceso procesos[], int numProcesos) {
	int i, sum = 0;
	for(i=0; i< numProcesos; i++) {
		sum += procesos[i].nroRafagas;
	}
	return sum;

}

int seleccionarProceso(proceso procesos[]) {

    int i=0, j, indiceProcesoMenorNroRafagas=-1, minNroRafagas=3000;

    while ( procesos[i].tiempoLlegada <= tiempoActual && i < numProcesos) {
        i++; 									
    } 

    i--;

    for(j=0; j <= i && procesos[j].nroRafagas == 0; j++);

    minNroRafagas = procesos[j].nroRafagas;
    indiceProcesoMenorNroRafagas = j;

    while(j<=i) {
        if(procesos[j].nroRafagas != 0 && procesos[j].nroRafagas < minNroRafagas) {
            minNroRafagas = procesos[j].nroRafagas;
            indiceProcesoMenorNroRafagas = j;
        }
        j++;
    }

	return indiceProcesoMenorNroRafagas;
}

void ejecutarProcesos(proceso procesos[], int totalNroRafagas, nombres nombresProcesos[]) {
	int indiceProcesoMenorNroRafagas;

	while (tiempoActual != totalNroRafagas) { 

		indiceProcesoMenorNroRafagas = seleccionarProceso(procesos); 

        /*printf("Indice menor : %d\t", indiceProcesoMenorNroRafagas );*/
        /*printf("Proceso nombre: %s\t", procesos[indiceProcesoMenorNroRafagas].nombre );*/
        /*printf("Proceso rafagas: %d\n", procesos[indiceProcesoMenorNroRafagas].nroRafagas);*/
		procesos[indiceProcesoMenorNroRafagas].nroRafagas -= 1;

		strcpy(nombresProcesos[tiempoActual].nombre, procesos[indiceProcesoMenorNroRafagas].nombre); 
		tiempoActual += 1;
	}

}

void srt(proceso procesos[], nombres nombresProcesos[]) {

		int i, nroTotalRafagas;
		tiempoActual = 0;

        puts("\nSimulacion del algoritmo SRT(Shortest remaining time)\n");
        puts("Ingrese numero de procesos: ");
        scanf("%d", &numProcesos);
        for(i=0; i<numProcesos; i++) {
            printf("Nombre de proceso(Max 2 caracteres): ");
            scanf("%s", procesos[i].nombre);
            printf("Tiempo de llegada de %s: ", procesos[i].nombre);
            scanf("%d", &procesos[i].tiempoLlegada);
            printf("Nro de rafagas de cpu de %s: ", procesos[i].nombre);
            scanf("%d", &procesos[i].nroRafagas);

        }

		printf("\n\nNombre\tLlegada\tRafagas\n");

		for(i=0; i<numProcesos; i++) {
			printf("\n%s\t%d\t%d", procesos[i].nombre, procesos[i].tiempoLlegada, procesos[i].nroRafagas);
		}

		ordenarProcesos(procesos, numProcesos);
		puts("\n");

		nroTotalRafagas = obtenerTotalRafagas(procesos, numProcesos);
		printf("\nTotal de rafagas de cpu: %d \n", nroTotalRafagas );

	    ejecutarProcesos(procesos, nroTotalRafagas, nombresProcesos);

		printf("\n\nTodos los procesos ejecutados...\n\n");

		printf("Diagrama Gantt:\n");


	    for(i=0; i<=tiempoActual; i++) {
	        printf("|%2d ",i);
	    }
	    printf("\n");

		for(i=0; i<tiempoActual; i++) {
			printf("|%s  ", nombresProcesos[i].nombre );
		}
		printf("|\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void crearProcesos(int cantidad) {
    int i;
    pid_t pid;

    for (i = 0; i < cantidad; i++) {
        pid = fork();

        if (pid < 0) {
            perror("Error al crear el proceso hijo.");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Este es el proceso hijo
            // Aquí puedes llamar a la función que deseas ejecutar

            // Termina el proceso hijo
            exit(EXIT_SUCCESS);
        }
    }

    // Espera a que todos los procesos hijos terminen
    for (i = 0; i < cantidad; i++) {
        wait(NULL);
    }
}

int main() {
    int cantidadProcesos = 5;
    crearProcesos(cantidadProcesos);
    
    return 0;
}

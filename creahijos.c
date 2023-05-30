#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void f0() {
    printf("MI pid es %d\n", getpid());
    sleep(10);
}

void f1() {
    printf("MI pid es %d\n", getpid());
    sleep(10);
}

void f2() {
    printf("MI pid es %d\n", getpid());
    sleep(10);
}

void f3() {
    printf("MI pid es %d\n", getpid());
    sleep(10);
}

void main() {
    // Declaración de variables
    int i;
    pid_t pidh, wpidh;
    pid_t pidn, wpidn;

    // Zona de código principal
    for (i = 0; i < 4; i++) {
        pidh = fork();

        if (pidh < 0) exit(-1); // Comprobación

        // Código del hijo
        if (pidh == 0) {
            if (i == 0) {
                f0();
                exit(0);
            } else {
                // Código del nieto
                pidn = fork();
                if (pidn < 0) exit(-1); // Comprobación

                if (pidn == 0) {
                    switch (i) {
                        // Funciones nietas
                        case 1:
                            f1();
                            exit(0);
                        case 2:
                            f2();
                            exit(0);
                        case 3:
                            f3();
                            exit(0);
                    }
                }
                wpidn = wait(NULL); // Espera a los procesos nietos
                exit(0);//malditos procesos zombis y los padres que no mataron a los hijos
            }
        }
    }

    // Esperar a los procesos hijos
    for (i = 0; i < 4; i++) {
        wpidh = wait(NULL);
        exit(0);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void f0() {
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
        // Código del hijo
        pidh = fork();
        if (pidh < 0)
            exit(-1);

        if (pidh == 0) {
            if (i == 0) {
                f0();
                exit(0);
            } else {
                pidn = fork();
                if (pidn < 0)
                    exit(-1);
                // Código del nieto

                if (pidn == 0) {
                    f0();
                    exit(0);
                }

                // Esperar al nieto
                wpidn = wait(NULL);
                exit(0);
            }
        }
    }

    // Esperar al hijo
    for (i = 0; i < 4; i++) {
        wpidh = wait(NULL);
        exit(0);
    }
}

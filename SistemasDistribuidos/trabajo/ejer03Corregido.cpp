#include <stdio.h>     // Incluido para printf
#include <stdlib.h>    // Incluido para exit
#include <unistd.h>    // Incluido para fork, pipe, read, write, close
#include <string.h>    // Incluido para strlen

#define LEER 0
#define ESCRIBIR 1

int main() {
    int descr[2]; // Descriptores de E y S de la tuberia
    int bytesleidos;
    char mensaje[100];

    // Corrección: Se cambió la declaración de frase a un puntero a char
    // En C++, las cadenas literales son de tipo const char[]
    const char *frase = "Veremos si la transferencia es buena";

    printf("Ejemplo de tuberia entre padre e hijo\n");

    // Corrección: Se verifica si la llamada a pipe() tuvo éxito
    if (pipe(descr) == -1) {
        perror("Error al crear la tuberia"); // Imprime un mensaje de error
        exit(1); // Sale del programa con un código de error
    }

    if (fork() == 0) {
        close(descr[LEER]); // El hijo no necesita leer, así que cerramos el descriptor de lectura
        write(descr[ESCRIBIR], frase, strlen(frase)); // El hijo escribe la frase en la tubería
        close(descr[ESCRIBIR]); // Cerramos el descriptor de escritura después de escribir
    } else {
        close(descr[ESCRIBIR]); // El padre no necesita escribir, así que cerramos el descriptor de escritura
        bytesleidos = read(descr[LEER], mensaje, sizeof(mensaje) - 1); // El padre lee el mensaje de la tubería

        // Corrección: Aseguramos que el mensaje termine con un carácter nulo para evitar problemas al imprimir
        mensaje[bytesleidos] = '\0';

        // Corrección: Se agregó bytesleidos como argumento para el formato %d
        printf("Bytes leidos: %d\n", bytesleidos);
        printf("Mensaje: %s\n", mensaje);
        close(descr[LEER]); // Cerramos el descriptor de lectura después de leer
    }

    return 0;
}

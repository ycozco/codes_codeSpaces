#include <stdlib.h>
#include <unistd.h>

#define LEER 0
#define ESCRIBIR 1

int main(){
    int descr[2]; /* Descriptores de E y S de la tuberia*/
    int bytesleidos;
    char mensaje[100];
    *frase = "Veremos si la transferencia es buena";

    printf("Ejemplo de tuberia entre padre e hijo");
    pipe(descr);
    if(fork()==0)
    {
        close(descr[LEER]);
        write(descr[ESCRIBIR],frase,strlen(frase));
        close(descr[ESCRIBIR]);
    }
    else
    {
        close(descr[ESCRIBIR]);
        bytesleidos=read(descr[LEER],mensaje,100);
        printf("Bytes leidos:%d\n");
        printf("\nBytes leidos: %d\nMensaje: %s\n",bytesleidos,mensaje);
        close(descr[LEER]);
        
    }

}
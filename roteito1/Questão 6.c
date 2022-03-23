//QUESTÃO 6:

#include <stdio.h>
#include <stdlib.h>

void inverter(int v[], int inicio, int fim){
    int aux;
    if(inicio < fim){
        aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
        inverter(v, inicio + 1, fim - 1);
    }
}

void imprimir(int v[], int tam){
    if(tam == 1)
        printf("%d, ", v[tam - 1]);
    else{
        imprimir(v, tam - 1);
        printf("%d, ", v[tam - 1]);
    }
}

int main () {

    int vet[10] = {17,56,65,8,300,87,44,1001,80,12};

    imprimir(vet, 10);
    inverter(vet, 0, 9); 
    printf("\n");
    imprimir(vet, 10);

    return 0;
}
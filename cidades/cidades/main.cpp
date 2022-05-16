#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void rotas(){
    FILE *f = fopen("tourar9152.tour", "r");
    int a, b;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    while (!feof(f)){
        printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);
    }
    fclose(f);
}

int main(){
    FILE *arquivo = fopen("ar9152.tsp", "r");
    int c;
    float la;
    float lg;
    int N = 9152;
    double cidLa[N];
    double cidLg[N];

    double *grafo;
    grafo = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo[i*N + j] = 0.;
        }
    }
    

    int k=0;
    float media = 0, Dtotal=0; //aqui eu defini as variaveis media e Distancia total
    
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            float maiorDis[i][j], menorDis[i][j];//aqui eu defini as variaveis de maior e menor distancia
            grafo[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));

            Dtotal += grafo[i*N +j]; //a minha ideia seria que a distancia total fosse somada dessa forma. A cada resultado, fosse sendo atribuido ao resultado anterior na variavel

            if (grafo[i*N+j] > maiorDis[i][j]){
                maiorDis[i][j] = grafo[i*N+j]; //Dessa maneira eu poderia encontrar a maior distancia entre cidades
            }
            if (grafo[i*N+j] < menorDis[i][j]){
                menorDis[i][j] = grafo[i*N+j]; //Dessa maneira eu poderia encontrar a menor distancia entre cidades
            }
            
            
        }
    }
    media = Dtotal / N; //Ja a media, seria a distancia total dividida pelo numedo de cidades
    
    rotas();
    printf("A distancia total eh: %2.f \n", Dtotal);
    printf("A media total eh: %2.f \n", media);
    

}
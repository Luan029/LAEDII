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
    int N = 5;
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
    
    while (k < 5)
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        k++;
    }
    fclose(arquivo);
    float maior, menor;//aqui eu defini as variaveis de maior e menor distancia
    maior = 0;
    menor = sqrt(pow(cidLa[0] - cidLa[1], 2) + pow(cidLg[0] - cidLg[1], 2));
    int pMaiorI = 0;
    int pMaiorJ = 1;
    int pMenorI = 0;
    int pMenorJ = 1;
    int cont = 0;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            grafo[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
            if(grafo[i*N + j] != 0){
                cont++;
            
            Dtotal += grafo[i*N +j]; //a minha ideia seria que a distancia total fosse somada dessa forma. A cada resultado, fosse sendo atribuido ao resultado anterior na variavel
            }
            if (grafo[i*N+j] > maior){
                maior = grafo[i*N+j]; //Dessa maneira eu poderia encontrar a maior distancia entre cidades
                pMaiorI = i;
                pMaiorJ = j;
            }
            if (grafo[i*N+j] < menor && grafo[i*N+j] != 0){
                menor = grafo[i*N+j]; //Dessa maneira eu poderia encontrar a menor distancia entre cidades
                pMenorI = i;
                pMenorJ = j;
            }
            
            
        }
    }
    //conferindo:
    //float distMaiorVin =sqrt(pow(cidLa[0] - cidLa[4660],2) + pow(cidLg[0] - cidLg[pMaiorJ],2));

    float distMaior =sqrt(pow(cidLa[pMaiorI] - cidLa[pMaiorJ],2) + pow(cidLg[pMaiorI] - cidLg[pMaiorJ],2));
    float distMenor =sqrt(pow(cidLa[pMenorI] - cidLa[pMenorJ],2) + pow(cidLg[pMenorI] - cidLg[pMenorJ],2));
    //media = Dtotal / ((float) (N*(N-1))/2); //Ja a media, seria a distancia total dividida pelo numedo de cidades
    media = (float) Dtotal / (float) cont; //Ja a media, 
    //rotas();
    float m = grafo[pMaiorI*N + pMaiorJ];
    printf("A distancia total eh: %2.f \n", Dtotal);
    printf("A maior total eh: %2.f \n", maior);
    printf("A media total eh: %2.f \n", media);
    printf("A menor total eh: %2.f \n", menor);
    

}
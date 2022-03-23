//QUESTÃO 1:

#include <stdio.h>
#include <time.h>
#include <math.h>

int algoritmoDemorado ( int n) {
 int soma = 0;
   for (int i = 0; i < n ; i ++) {
     for ( int j = 0; j < n; j ++) {
       for ( int k = 0; k < n; k ++) {
         for ( int l = 0; l < n; l ++) {
           soma = i + j + k + l ;
        }
       }
      }
     }
     return soma ;
 }
 
 int main(){
	 clock t start = clock();
	 
	 algoritmoDemorado(10);
	 
	 clock_t end = clock();
	 double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	 printf("demorou %f segundos para executar \n", cpu_time_used);
	 //algoritmoDemorado(100);
	 //algoritmoDemorado(1000);
	 //algoritmoDemorado(10000);
 }
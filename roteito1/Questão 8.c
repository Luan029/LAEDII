//QUESTÃO 8:

#include <stdio.h>
#include <math.h>

int fatorial(int n){
    int i, res = 1;
    for(i = n; i>0; i--){
        res *= i;
    }
    return res;
}
int fatorial_calda(int num){
    if (num == 1){
       return num; 
    }
    else{
       return num * fatorial_calda(num - 1); 
    }
 
}
int main(){
    int n;
    printf("Digite um numero ");
    scanf("%d", &n);
    printf("%d \n", fatorial(n));
    printf("%d \n", fatorial_calda(n));
}
#include <stdio.h>
#include <math.h>

float raizAproximada(x, x0, e){
    float quadradoX0 = pow(x0, 2);
    if(( quadradoX0 - 2) <= e){
        return x0 = 0;
    }else{
        float raiz1, raiz2, raiz3;
        raiz1 = sqrt(x);
        raiz2 = sqrt((quadradoX0 + x)/ 2 * x0);
        raiz3 = sqrt(e);
        return (raiz1, raiz2, raiz3);
    }
}
int main(){
    float res = raizAproximada(13, 3.5, 0.001);

    printf("%f", res);
}
//QUESTÃO 3:

#include <stdio.h>
#include <string.h>

_Bool stringsIguais(char s1[], char s2[]){
	int i = 0;
	while(s1[i] == s2[i] && s1[1] != '\0' && s2[i] != '\0'){
		i++;
	}
	if(s1[i]== '\0' && s2[i] == '\0' ){
		return 1;
	} 
	else return 0; 
}
int main(void) {
    
    printf("Digite uma palavra ");
    char original[50];
    scanf("%s", original);
    char copia[50];
    strcpy(copia, original);
    printf("%s\n", copia);
    size_t size = strlen(original);
    for(int i = 0; i < size / 2; i++) {
       char tmp = original[i]; //armazena o character inicial
       original[i] = original[size - i - 1]; //Troca o character da ponta oposta
       original[size - i - 1] = tmp; //Armazena o character inicial
    }
    printf("%s\n", original);

    _Bool stringsIguais(char s1[], char s2[]);
	
	if(stringsIguais(original, copia)){
		printf("E palindromo\n");
	} else {
		printf("Nao e palindromo\n");
	}
	return 0;
}
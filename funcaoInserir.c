#include <stdio.h>
#include <stdlib.h>
typedef struct aluno{
    int id;
    char *nome;
    float nota;
}*Aluno;
typedef struct node {
    Aluno A;
    struct node* esq;
    struct node* dir;
}*No;
Aluno criarAluno(int a, char* b, unsigned short c){
    Aluno A =(Aluno) malloc(sizeof(struct aluno));
    A->id = a;
    A->nome = b;
    A->nota = c;
    return A;
    /*Como essa funçao esta criando espaço na memoria para o aluno, nossa ideia seria que a função inserir, fosse adicionando o aluno na esqueda ou na direita*/
}
typedef No noRaiz;
noRaiz criarArvore();
int inserir(noRaiz, Aluno); /*o compilador da erro nos parametros*/
int inserirEmLote(noRaiz, noRaiz);
int main(){
	
    Aluno K = criarAluno(10, "Kennedy Lopes\0", 9.);
    No raiz = malloc(sizeof(struct node));
    raiz->esq = 0;
    raiz->dir = 0;
    raiz->A = K;
	printf("%d %s %2.f", raiz->A->id, raiz->A->nome, raiz->A->nota);

	int a = inserir(raiz, raiz->A); /*colocamos a raiz e a raiz que aponta para A*/
	printf("%d", a);
   
}
int inserir(noRaiz, Aluno){
    /*Aui verifico se a raiz esta vazia*/
	if(noRaiz != NULL){
        /*se a condição acima for verdadeira, verifico se o aluno->id é menor que a raiz*/
		if(Aluno->id < noRaiz){
            /*se for ele vai pra esquerda*/
			noRaiz(No)->esq = Aluno->;
			return noRaiz->esq;
		}else if(Aluno->id > noRaiz){
            /*se for maior, ele vai pra direita*/
			noRaiz(No)->dir = Aluno;
			return noRaiz->dir;
		}
	}
}


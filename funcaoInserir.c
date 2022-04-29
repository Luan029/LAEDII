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
}
typedef No noRaiz;
noRaiz criarArvore(noRaiz No,Aluno x){
    
  if(x != NULL){
     if(x->id < No->A->id){
        No->esq->A = x;
    }else if(x->id > No->A->id){
        No->dir->A = x;
    }
  }
  return 0;
}

int inserir(noRaiz No, Aluno x);
int main(){
	int id;
	char nome[10];
	float nota;
	printf("Digite o ID, o nome e a nota do aluno: ");
	scanf("%d %s %f", &id, nome, &nota);
    Aluno K = criarAluno(id, nome, nota);
    No raiz = malloc(sizeof(struct node));
    raiz->esq = 0;
    raiz->dir = 0;
    raiz->A = K;
	printf("%d %s %2.f", raiz->A->id, raiz->A->nome, raiz->A->nota);
	inserir(raiz, K);
	
	return 0;
	
   
}
int inserir(noRaiz No, Aluno x){
    if(No == NULL){
        No = criarArvore(No, x);
    }
    
   return 0;
}

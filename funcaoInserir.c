#include <stdio.h>
#include <stdlib.h>
/*Professor, infelizmente não tivemos criatividade para resolver essa atividade. Mas tentarei explicar o que queriamos fazer.*/
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
noRaiz criarArvore(noRaiz No){
    printf("%d %s %2.f \n", No->A->id, No->A->nome, No->A->nota);
  return No;
  /*retornava o No do noRaiz*/
}

int inserir(noRaiz No, Aluno x);
int inserirEmLote(noRaiz No, Aluno*, int n);
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
	noRaiz No = criarArvore(raiz);
    /*aqui passaria o primeiro aluno como a raiz da arvore*/
	
	printf("Digite o ID, o nome e a nota do aluno: ");
	scanf("%d %s %f", &id, nome, &nota);
    Aluno L = criarAluno(id, nome, nota);
    /*decidi criar dois alunos. Um seria a raiz e o outro seria comparado a ele*/
    
	inserir(No, L);
	inserirEmLote(No, &No->A , 5);
	return 0;
	
   
}
int inserir(noRaiz No, Aluno x){
	printf("Raiz id: %d\n", No->A->id);
	printf("Aluno id: %d\n", x->id);
    /*Aqui encontramos um erro que nao conseguimos corrigir. Acima eu imprimi os IDs do noRais(que veio da função criar arvore) e o do Aluno x(o segundo aluno digitado). A impressao da super certo, mas abaixo quando coloco eles nesses ifs, simplesmente nao da certo de jeito nenhum*/
    if(x->id < No->A->id){
		No->esq->A = x;
		printf("Esquerda\n");
        /*se o id do aluno x fosse menor que o da raiz, ele iria pra esquerda*/
    }else if(x->id > No->A->id){
        No->dir->A = x;
        printf("Direita\n");
        /*ja aqui se fosse maior, ele iria pra direita*/
    }
  
    
   return 0;
}
int inserirEmLote(noRaiz No, Aluno*, int n){
	int i, id;
	char nome[10];
	float nota;
	for(i = 0; i< n; i++){
		printf("Digite o ID, o nome e a nota do aluno: ");
		scanf("%d %s %f", &id, nome, &nota);
	    Aluno N = criarAluno(id, nome, nota);
	    inserir(No, N);
	}
    /*Ja nessa função, foi passado o noRaiz, a struct Aluno e a quantidade de alunos que seriam criados. A nossa ideia seria criar o for com essa quantidade e assim chamar a função criar aluno para reservar espaço na memoria pra eles e a função inserir pra ir inserindo eles.*/
    return 0;
}
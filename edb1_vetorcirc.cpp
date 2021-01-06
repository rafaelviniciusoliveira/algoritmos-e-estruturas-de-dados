/*
ARQUIVO DE SUPORTE AO CURSO DE ESTRUTURA DE DADOS BASICAS
INSTITUTO METROPOLE DIGITAL
UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE
PROFESSOR CESAR RENNO COSTA
cesar@imd.ufrn.br
*/

// Example program
#include <iostream>
#include <string>

// Estrutura para armazenar cabeçalho do vetor
typedef struct _vetorcircular{
    char *V;
    int N;
    int B;
    int N_max;
} vetorcircular;

// Imprime o conteúdo do vetor no console
void print_vetorcircular(vetorcircular *S, int label){
    std::cout << label << ": ";
    for (int ii=0; ii<S->N; ii++){
        std::cout << (int)S->V[(ii+S->B)%(S->N_max)];
        if(ii<(S->N-1))
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
}

// Inicializa um vetor vazio
void iniciar_vetorcircular(vetorcircular *S, int N_max){
  S->N = 0;
  S->B = 0;
  S->V = (char *)malloc(N_max * sizeof(char));
  S->N_max = N_max;
}

// Libera o espaço do vetor circular
void libera_vetorcircular(vetorcircular *S){
  free(S->V);
}

// Retorna o valor do vetor na posicao especificado
char acessar_vetorcircular(vetorcircular *S, int pos){
  return S->V[(pos+S->B)%(S->N_max)];
}

char acessar_vetorcircular_inicio(vetorcircular *S){
  return S->V[(S->B)%(S->N_max)];
}

char acessar_vetorcircular_fim(vetorcircular *S){
  return S->V[((S->N-1)+(S->B))%(S->N_max)];
}

// Inserir elemento na posição especificada
void inserir_vetorcircular(vetorcircular *S, int pos, char el){
  if(S->N>=S->N_max) return;
  for(int ii=S->N-1;ii>=pos;ii++) S->V[(ii+1+S->B)%S->N_max] = S->V[(ii+S->B)%S->N_max];
  S->V[(pos+S->B)%S->N_max] = el;
  S->N++;
}

void inserir_vetorcircular_inicio(vetorcircular *S, char el){
  if(S->N>=S->N_max) return;
  S->B--;
  S->N++;
  S->V[(S->B)%S->N_max] = el;
}

void inserir_vetorcircular_fim(vetorcircular *S, char el){
  if(S->N>=S->N_max) return;
  S->V[(S->N+S->B)%S->N_max] = el;
  S->N++;
}

// Remover elemento do vetor em uma posicao especifica
void remover_vetorcircular(vetorcircular *S, int pos){
  if(S->N==0) return;
  for(int ii=pos;ii<S->N;ii++) S->V[(ii+S->B)%S->N_max] = S->V[(ii+1+S->B)%S->N_max];
  S->N--;
}

void remover_vetorcircular_inicio(vetorcircular *S){
  if(S->N==0) return;
  S->B++;
  S->N--;
}

void remover_vetorcircular_fim(vetorcircular *S){
  if(S->N==0) return;
  S->N--;
}


int main(){

  vetorcircular S;
  iniciar_vetorcircular(&S,20);
  inserir_vetorcircular_inicio(&S,2);
  inserir_vetorcircular_inicio(&S,6);
  inserir_vetorcircular_fim(&S,9);
  print_vetorcircular(&S,0);
  libera_vetorcircular(&S);

}

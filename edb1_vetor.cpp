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
typedef struct _vetor{
    char *V;
    int N;
    int N_max;
} vetor;

// Imprime o conteúdo do vetor no console
void print_vetor(vetor *S, int label){
    std::cout << label << ": ";
    for (int ii=0; ii<S->N; ii++){
        std::cout << (int)S->V[ii];
        if(ii<(S->N-1))
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
}

// Inicializa um vetor vazio
void iniciar_vetor(vetor *S, int N_max){
  S->N = 0;
  S->V = (char *)malloc(N_max * sizeof(char));
  S->N_max = N_max;
}

// Libera o espaço do vetor
void libera_vetor(vetor *S){
  free(S->V);
}

// Retorna o valor do vetor na posicao especificado
char acessar_vetor(vetor *S, int pos){
  return S->V[pos];
}

char acessar_vetor_inicio(vetor *S){
  return S->V[0];
}

char acessar_vetor_fim(vetor *S){
  return S->V[S->N-1];
}

// Inserir elemento na posição especificada
void inserir_vetor(vetor *S, int pos, char el){
  if(S->N>=S->N_max) return;
  for(int ii=S->N-1;ii>=pos;ii++) S->V[ii+1] = S->V[ii];
  S->V[pos] = el;
  S->N++;
}

void inserir_vetor_inicio(vetor *S, char el){
  inserir_vetor(S,0,el);
}

void inserir_vetor_fim(vetor *S, char el){
  inserir_vetor(S,S->N,el);
}

// Remover elemento do vetor em uma posicao especifica
void remover_vetor(vetor *S, int pos){
  if(S->N==0) return;
  for(int ii=pos;ii<S->N;ii++) S->V[ii] = S->V[ii+1];
  S->N--;
}

void remover_vetor_inicio(vetor *S){
  remover_vetor(S,0);
}

void remover_vetor_fim(vetor *S){
  remover_vetor(S,S->N-1);
}



int main(){

  vetor S;
  iniciar_vetor(&S,20);
  inserir_vetor_inicio(&S,2);
  inserir_vetor_inicio(&S,6);
  inserir_vetor_fim(&S,9);
  inserir_vetor(&S,9,2);
  print_vetor(&S,0);
  libera_vetor(&S);

}

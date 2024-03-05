#ifndef HEAP_H
#define HEAP_H


//a partir de heap.txt
#include "libs.h"

struct processo
{
    int pid;   //Um identificador único para o processo.
    int prioridade; //Um valor inteiro que representa a prioridade de execução do processo. Valores mais altos indicam maior prioridade.
    int tempoEspera; // Um valor inteiro que representa o tempo que o processo está esperando para ser executado. Valores mais altos indicam um maior tempo de espera.
};
typedef struct processo Processo;

struct heap
{
    Processo* processos; //Um ponteiro para um array de processos.
    int tamanhoMaximo; //Um valor inteiro que representa o tamanho máximo do heap.
};

typedef struct heap Heap;


Processo* criarHeap(int tamanhoMaximo); //Cria um heap vazio com o tamanho máximo especificado.
//Implemente um Heap Máximo para organizar os processos por prioridade de execução.
void inserirProcesso(Processo* heap, int* tamanhoAtual, Processo novoProcesso); //maximo
//Implemente um Heap minimo para organizar os processos por tempo de espera.
void inserirProcessoPorTempoEspera(Processo* heap, int* tamanhoAtual, Processo novoProcesso); //minimo


void remocaominmax(Processo *heap, int *tamanhoAtual, Processo *heap2, int *tamanhoAtual2); //funcao para remover o minimo do heap minimo e o maximo do heap maximo
void removerProcessoTopoMax(Processo *heap, int *tamanhoAtual); //Remove o processo com maior prioridade ou menor tempo de espera do heap.
void removerProcessoTopoMin(Processo *heap, int *tamanhoAtual); //Remove o processo com maior prioridade ou menor tempo de espera do heap.
int heapVazio(int tamanhoAtual); //Retorna 1 se o heap estiver vazio, caso contrário retorna 0.
void imprimirProcessos(Processo* heap, int tamanho); // que imprime a lista de processos em cada heap, de acordo com sua prioridade ou tempo de espera.
//Implemente uma função que permita entrar com uma quantidade n de processos tanto para o Heap Máximo, quanto para o Heap Mínimo.
void entradaProcesso(Processo *heapMax, int* tamanhoAtualMax, Processo *heapMin, int* tamanhoAtualMin, int n); //a entrada que o usuario fornecer servirá tanto para heap minimo quanto para heap maximo
//funcao dot para gerar e vizualizar dot
void dot(Processo *heapMaximo, int tamanhoAtualMaximo, Processo *heapMinimo, int tamanhoAtualMinimo); //funcao para vizualizar dot

#endif // HEAP_H
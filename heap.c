#include "heap.h"

//criar heap
Processo *criarHeap(int tamanhoMaximo)
{
    Processo *heap;                         //ponteiro para um array de processos
    heap = (Processo *)malloc(tamanhoMaximo * sizeof(Processo));    //aloca memoria para o array de processos
    return heap;                        //retorna o ponteiro para o array de processos
}

//para heap maximo
void inserirProcesso(Processo *heap, int *tamanhoAtual, Processo novoProcesso)
{
    int i;              
    Processo temp;
    i = *tamanhoAtual;
    heap[i] = novoProcesso; //insere o novo processo na ultima posicao do heap
    while (i > 0 && heap[(i - 1) / 2].prioridade < heap[i].prioridade) //enquanto o pai do processo for menor que o processo
    {
        temp = heap[i];     //troca o processo com o pai
        heap[i] = heap[(i - 1) / 2];    //troca o processo com o pai
        heap[(i - 1) / 2] = temp;      //troca o processo com o pai
        i = (i - 1) / 2;                //atualiza o indice do processo
    }
    *tamanhoAtual = *tamanhoAtual + 1;      //atualiza o tamanho do heap
}

//para heap minimo
void inserirProcessoPorTempoEspera(Processo *heap, int *tamanhoAtual, Processo novoProcesso)
{
    int i;
    Processo temp;
    i = *tamanhoAtual;
    heap[i] = novoProcesso; //insere o novo processo na ultima posicao do heap
    while (i > 0 && heap[(i - 1) / 2].tempoEspera > heap[i].tempoEspera) //enquanto o pai do processo for maior que o processo
    {
        temp = heap[i];     //troca o processo com o pai
        heap[i] = heap[(i - 1) / 2];    //troca o processo com o pai
        heap[(i - 1) / 2] = temp;      //troca o processo com o pai
        i = (i - 1) / 2;                //atualiza o indice do processo
    }
    *tamanhoAtual = *tamanhoAtual + 1;      //atualiza o tamanho do heap
}

void removerProcessoTopoMax(Processo *heap, int *tamanhoAtual) //Remove o processo com maior prioridade ou menor tempo de espera do heap.
{
    int i, j;
    Processo temp;
    if (*tamanhoAtual > 0) //se o heap nao estiver vazio
    {
        heap[0] = heap[*tamanhoAtual - 1]; //o topo do heap recebe o ultimo processo
        *tamanhoAtual = *tamanhoAtual - 1; //atualiza o tamanho do heap
        i = 0;
        while (2 * i + 1 < *tamanhoAtual) //enquanto o indice do filho da esquerda for menor que o tamanho do heap
        {
            j = 2 * i + 1;
            if (j + 1 < *tamanhoAtual && heap[j].prioridade < heap[j + 1].prioridade) //se o filho da direita for maior que o filho da esquerda
            {
                j = j + 1; //atualiza o indice do filho
            }
            if (heap[i].prioridade < heap[j].prioridade) //se o pai for menor que o filho
            {
                temp = heap[i]; //troca o pai com o filho
                heap[i] = heap[j]; //troca o pai com o filho
                heap[j] = temp; //troca o pai com o filho
                i = j; //atualiza o indice do pai
            }
            else
            {
                break;
            }
        }
    }
}

void removerProcessoTopoMin(Processo *heap, int *tamanhoAtual) //Remove o processo com maior prioridade ou menor tempo de espera do heap.
{
    int i, j;
    Processo temp;
    if (*tamanhoAtual > 0) //se o heap nao estiver vazio
    {
        heap[0] = heap[*tamanhoAtual - 1]; //o topo do heap recebe o ultimo processo
        *tamanhoAtual = *tamanhoAtual - 1; //atualiza o tamanho do heap
        i = 0;
        while (2 * i + 1 < *tamanhoAtual) //enquanto o indice do filho da esquerda for menor que o tamanho do heap
        {
            j = 2 * i + 1;
            if (j + 1 < *tamanhoAtual && heap[j].tempoEspera > heap[j + 1].tempoEspera) //se o filho da direita for maior que o filho da esquerda
            {
                j = j + 1; //atualiza o indice do filho
            }
            if (heap[i].tempoEspera > heap[j].tempoEspera) //se o pai for menor que o filho
            {
                temp = heap[i]; //troca o pai com o filho
                heap[i] = heap[j]; //troca o pai com o filho
                heap[j] = temp; //troca o pai com o filho
                i = j; //atualiza o indice do pai
            }
            else
            {
                break;
            }
        }
    }
}

int heapVazio(int tamanhoAtual)
{
    if (tamanhoAtual == 0) //se o tamanho do heap for 0
    {
        return 1; //retorna 1
    }
    else
    {
        return 0; //retorna 0
    }
}

void imprimirProcessos(Processo *heap, int tamanho){ //imprime como vetor ordenado
    int i;
    for(i = 0; i < tamanho; i++){
        printf("PID: %d | Prioridade: %d | Tempo de Espera: %d\n", heap[i].pid, heap[i].prioridade, heap[i].tempoEspera);
    }

}

void entradaProcesso(Processo *heapMax, int* tamanhoAtualMax, Processo *heapMin, int* tamanhoAtualMin, int n) {
    int i;
    Processo novoProcesso;
    for (i = 0; i < n; i++) {
        printf("Entre com o pid do processo: ");
        scanf("%d", &novoProcesso.pid);
        printf("Entre com a prioridade do processo: ");
        scanf("%d", &novoProcesso.prioridade);
        printf("Entre com o tempo de espera do processo: ");
        scanf("%d", &novoProcesso.tempoEspera);

        // Cria cópias separadas para inserir em cada heap
        Processo novoProcessoMax = novoProcesso; 
        Processo novoProcessoMin = novoProcesso;

        inserirProcesso(heapMax, tamanhoAtualMax, novoProcessoMax); // Insere no heap máximo
        inserirProcessoPorTempoEspera(heapMin, tamanhoAtualMin, novoProcessoMin); // Insere no heap mínimo
    }
}

//funcao que remove ao mesmo tempo o topo de min e max
void remocaominmax(Processo *heap, int *tamanhoAtual, Processo *heap2, int *tamanhoAtual2){
    removerProcessoTopoMax(heap, tamanhoAtual);
    removerProcessoTopoMin(heap2, tamanhoAtual2);
}



void dot(Processo *heapMaximo, int tamanhoAtualMaximo, Processo *heapMinimo, int tamanhoAtualMinimo) {
    FILE *arquivo;
    int i;

    // Abrir o arquivo para escrita
    arquivo = fopen("heap.dot", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrever o cabeçalho do arquivo DOT
    fprintf(arquivo, "digraph G {\n");
    fprintf(arquivo, "node [shape=record];\n");
    fprintf(arquivo, "rankdir=LR;\n");

    // Escrever o cluster para o heap máximo
    fprintf(arquivo, "subgraph cluster_maximo {\n");
    fprintf(arquivo, "label = \"Heap Máximo\";\n");
    for (i = 0; i < tamanhoAtualMaximo; i++) {
        fprintf(arquivo, "node_maximo%d [label=\"PID: %d | Prioridade: %d | Tempo de Espera: %d\"];\n", i, heapMaximo[i].pid, heapMaximo[i].prioridade, heapMaximo[i].tempoEspera);
    }
    for (i = 0; i < tamanhoAtualMaximo; i++) {
        if (2 * i + 1 < tamanhoAtualMaximo) {
            fprintf(arquivo, "node_maximo%d -> node_maximo%d;\n", i, 2 * i + 1);
        }
        if (2 * i + 2 < tamanhoAtualMaximo) {
            fprintf(arquivo, "node_maximo%d -> node_maximo%d;\n", i, 2 * i + 2);
        }
    }
    fprintf(arquivo, "}\n");

    // Escrever o cluster para o heap mínimo
    fprintf(arquivo, "subgraph cluster_minimo {\n");
    fprintf(arquivo, "label = \"Heap Mínimo\";\n");
    for (i = 0; i < tamanhoAtualMinimo; i++) {
        fprintf(arquivo, "node_minimo%d [label=\"PID: %d | Prioridade: %d | Tempo de Espera: %d\"];\n", i, heapMinimo[i].pid, heapMinimo[i].prioridade, heapMinimo[i].tempoEspera);
    }
    for (i = 0; i < tamanhoAtualMinimo; i++) {
        if (2 * i + 1 < tamanhoAtualMinimo) {
            fprintf(arquivo, "node_minimo%d -> node_minimo%d;\n", i, 2 * i + 1);
        }
        if (2 * i + 2 < tamanhoAtualMinimo) {
            fprintf(arquivo, "node_minimo%d -> node_minimo%d;\n", i, 2 * i + 2);
        }
    }
    fprintf(arquivo, "}\n");

    // Escrever o fim do arquivo DOT
    fprintf(arquivo, "}\n");

    // Fechar o arquivo
    fclose(arquivo);

    // Executar o comando para gerar a imagem
    system("dot -Tpng heap.dot -o heap.png");
    // Abrir a imagem com o visualizador de imagens padrão do sistema
    system("eog heap.png");
}
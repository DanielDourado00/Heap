#include "libs.h"
#include "heap.h"
//para rodar no gcc é necessário compilar com o comando: gcc main.c heap.c -o main
int main(){


    printf(" \n----------------------------------\n");
    printf("|                                |\n");
    printf("|         Daniel Dourado         |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");



    int n; //para quantidade de processos
    Processo novoProcesso; //para inserir um novo processo
    Processo *heapMaximo; //para heap maximo
    Processo *heapMinimo; //para heap minimo
    int tamanhoAtualMaximo = 0; //tamanho atual do heap maximo
    int tamanhoAtualMinimo = 0; //tamanho atual do heap minimo
    int opcao; //opcao do menu
    do
    {
        printf("\nEntre com uma opcao:\n");
        printf("1- Criar heap maximo\n");
        printf("2- Criar heap minimo\n");
        printf("3- Inserir processo no heap maximo\n");
        printf("4- Inserir processo no heap minimo\n");
        printf("5- Remover processo do heap maximo (Prioridade)\n");
        printf("6- Remover processo do heap minimo (Tempo de espera)\n");
        printf("7- Imprimir processos do heap maximo\n");
        printf("8- Imprimir processos do heap minimo\n");
        printf("9- Entrada de processos\n");
        printf("10- Remover processo do heap\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        system("clear");
            printf("Entre com o tamanho maximo do heap maximo: ");
            scanf("%d", &n);
            heapMaximo = criarHeap(n);
            break;
        case 2:
        system("clear");
            printf("Entre com o tamanho maximo do heap minimo: ");
            scanf("%d", &n);
            heapMinimo = criarHeap(n);
            break;
        case 3:
        system("clear");
            printf("Entre com o pid do processo: ");
            scanf("%d", &novoProcesso.pid);
            printf("Entre com a prioridade do processo: "); //essa prioridade é para o heap maximo, ela pode ser: 1, 2, 3, 4, 5
            scanf("%d", &novoProcesso.prioridade);
            printf("Entre com o tempo de espera do processo: ");
            scanf("%d", &novoProcesso.tempoEspera);
            inserirProcesso(heapMaximo, &tamanhoAtualMaximo, novoProcesso);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 4:
        system("clear");
            printf("Entre com o pid do processo: ");
            scanf("%d", &novoProcesso.pid);
            printf("Entre com a prioridade do processo: ");
            scanf("%d", &novoProcesso.prioridade);
            printf("Entre com o tempo de espera do processo: "); //esse tempo de espera é para o heap minimo, ele pode ser: 1, 2, 3, 4, 5
            scanf("%d", &novoProcesso.tempoEspera);
            inserirProcessoPorTempoEspera(heapMinimo, &tamanhoAtualMinimo, novoProcesso);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 5:
        system("clear");
            removerProcessoTopoMax(heapMaximo, &tamanhoAtualMaximo);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 6:
        system("clear");
            removerProcessoTopoMin(heapMinimo, &tamanhoAtualMinimo);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 7: 
        system("clear");
            imprimirProcessos(heapMaximo, tamanhoAtualMaximo);
            break;
        case 8:
        system("clear");
            imprimirProcessos(heapMinimo, tamanhoAtualMinimo);
            break;
        case 9:
        system("clear");
            printf("Entre com a quantidade de processos: ");
            scanf("%d", &n);
            entradaProcesso(heapMaximo, &tamanhoAtualMaximo, heapMinimo, &tamanhoAtualMinimo, n);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 10:
        system("clear");
            remocaominmax(heapMaximo, &tamanhoAtualMaximo, heapMinimo, &tamanhoAtualMinimo);
            dot(heapMaximo, tamanhoAtualMaximo, heapMinimo, tamanhoAtualMinimo);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            break;
        }
    } while (opcao != 0);
    


}
// main.c
#include "erros.h"
#include <stdio.h>

int main() {
    int opcao;

    printf("Escolha o erro a executar:\n");
    printf("1 - Stack Overflow\n");
    printf("2 - Segmentation Fault\n");
    printf("3 - Buffer Overflow\n");
    printf("4 - Memory Leak\n");
    printf("5 - Condição de Corrida\n");
    printf("6 - Deadlock\n");

    scanf(" %d", &opcao);
   

    switch(opcao) {
        case 1:
            trigger_stackoverflow();
            break;
        case 2:
            trigger_segfault();
            break;
        case 3:
            trigger_buffer_overflow();
            break;
        case 4:
            trigger_memory_leak();
            break;
        case 5:
            trigger_race_condition();
            break;
        case 6:
            trigger_deadlock();
            break;
        default:
            printf("Opção inválida\n");
    }

    return 0;
}


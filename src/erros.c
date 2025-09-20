// erros.c
#include "erros.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>  // Para a função sleep()


// ==========================
// 1. STACK OVERFLOW
// ==========================
// Stack overflow ocorre quando a pilha de execução enche.
// Aqui simulamos isso com recursão infinita: cada chamada ocupa espaço na pilha
// até ela "explodir".


void trigger_stackoverflow() {
 printf("Stack overflow em andamento...\n");
 trigger_stackoverflow(); // recursão infinita até estourar a pilha 
 }

 // ==========================
// 2. SEGMENTATION FAULT
// ==========================
// Segfault ocorre quando acessamos memória inválida.
// Aqui tentamos acessar um ponteiro NULL (endereço 0x0).


void trigger_segfault() {
    int *p = NULL;
    printf("Antes do segfault\n");
    printf("Valor: %d\n", *p);
}


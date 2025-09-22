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

// ==========================
// 3. BUFFER OVERFLOW
// ==========================
// Buffer overflow ocorre quando escrevemos além do limite de um array.
// Aqui o buffer tem 5 posições, mas escrevemos 10.



void trigger_buffer_overflow() {
    char buffer[5];
    printf("Buffer overflow em andamento...\n");
    for (int i = 0; i < 10; i++) {  // escreve além do tamanho
        buffer[i] = 'A';
    }
}


// ==========================
// 4. MEMORY LEAK
// ==========================
// Memory leak ocorre quando alocamos memória e não liberamos.
// Aqui alocamos um vetor grande mas não chamamos free().

void trigger_memory_leak() {
    printf("Memory leak em andamento...\n");
    int *v = malloc(1000000 * sizeof(int));
    // não liberamos intencionalmente
}

// ==========================
// 5. RACE CONDITION
// ==========================
// Race condition ocorre quando duas threads acessam uma variável compartilhada
// ao mesmo tempo sem sincronização.
// Aqui incrementamos "counter" em duas threads, mas o valor final fica incorreto.


int counter = 0;

void *increment(void *arg) {
    for(int i = 0; i < 100000; i++) {
        counter++;  // acesso simultâneo
        
    // pausa artificial aumenta chance de colisão
    if (i % 100 == 0) { 
        usleep(1);  
        }
    }
    return NULL;
}

void trigger_race_condition() {
    printf("Condição de corrida em andamento...\n");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Valor final do contador: %d (deveria ser 200000)\n", counter);
}


// ==========================
// 6. DEADLOCK
// ==========================
// Deadlock ocorre quando duas threads ficam presas esperando uma à outra.
// Aqui t1 bloqueia m1 e espera m2, enquanto t2 bloqueia m2 e espera m1.

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void *lock1_then_lock2(void *arg) {
    pthread_mutex_lock(&m1);
    sleep(1);
    pthread_mutex_lock(&m2);
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m1);
    return NULL;
}

void *lock2_then_lock1(void *arg) {
    pthread_mutex_lock(&m2);
    sleep(1);
    pthread_mutex_lock(&m1);
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
    return NULL;
}

void trigger_deadlock() {
    printf("Deadlock em andamento...\n");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, lock1_then_lock2, NULL);
    pthread_create(&t2, NULL, lock2_then_lock1, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Deadlock terminou (ou não)\n");
}




/*
 * semaphore_fix.c — 세마포어로 임계구역 보호
 *
 * 컴파일: gcc semaphore_fix.c -o semaphore_fix -lpthread
 * 실행  : ./semaphore_fix
 *
 * 학습 포인트:
 *   - sem_init(&sem, 0, 1) → 초기값 1인 뮤텍스(세마포어 특수형)
 *   - sem_wait(&sem)  → P 연산 (자원 획득)
 *   - sem_post(&sem)  → V 연산 (자원 반납)
 *   - 이로써 counter++ 연산이 원자적으로 수행됨
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000

int counter = 0;
sem_t sem;  /* 세마포어 (자원 수 = 1, 뮤텍스로 동작) */

void *worker(void *arg) {
    long id = (long)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(&sem);   /* P() — 임계구역 진입 */
        counter++;        /* ── 임계구역 (보호됨) ── */
        sem_post(&sem);   /* V() — 임계구역 퇴출 */
    }
    printf("[Thread %ld] done\n", id);
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    sem_init(&sem, 0, 1);  /* 0=스레드간 공유, 1=초기값 (뮤텍스) */

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);

    printf("\n기대값: %d\n", NUM_THREADS * ITERATIONS);
    printf("실제값: %d\n", counter);
    printf("→ 세마포어로 보호하면 값이 일치합니다 ✅\n");

    return 0;
}

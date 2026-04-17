/*
 * thread_demo.c — pthread로 멀티스레드 구현
 *
 * 컴파일: gcc thread_demo.c -o thread_demo -lpthread
 * 실행  : ./thread_demo
 *
 * 학습 포인트:
 *  - 스레드는 같은 프로세스 내에서 Code/Data/Heap 영역을 공유
 *  - Stack은 스레드별로 분리됨
 *  - 여러 스레드가 하나의 전역 변수에 동시 접근하면 Race Condition 발생
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ITERATIONS 100000

int shared_counter = 0;  /* 전역 = Data 영역 → 모든 스레드 공유 */

void *increment(void *arg) {
    long id = (long)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        shared_counter++;  /* Race Condition 발생 지점 ⚠️ */
    }
    printf("[Thread %ld] 완료\n", id);
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n기대값: %d\n", NUM_THREADS * ITERATIONS);
    printf("실제값: %d\n", shared_counter);
    printf("→ 값이 다르다면 Race Condition 발생 (동기화 필요!)\n");

    return 0;
}

/*
 * race_condition.c — 임계구역 문제 재현 (동기화 없이)
 *
 * 컴파일: gcc race_condition.c -o race_condition -lpthread
 * 실행  : ./race_condition
 *
 * 현상:
 *   공유 변수 counter를 두 스레드가 동시에 증가시키면
 *   기대한 값보다 적게 나옴 → Race Condition
 *
 * 해결책은 semaphore_fix.c 파일 참고
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000

int counter = 0;  /* 공유 자원 (임계구역 대상) */

void *worker(void *arg) {
    long id = (long)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        /* ── 임계구역 (보호 안 됨) ──
         *   이 한 줄은 실제로 3단계 연산:
         *     1. counter 읽기
         *     2. 1 더하기
         *     3. counter에 저장
         *   스레드 스위칭이 중간에 끼면 값 손실 발생!
         */
        counter++;
    }
    printf("[Thread %ld] done\n", id);
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n기대값: %d\n", NUM_THREADS * ITERATIONS);
    printf("실제값: %d\n", counter);
    printf("→ 값이 다르면 Race Condition 발생!\n");

    return 0;
}

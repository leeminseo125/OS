/*
 * deadlock_demo.c — 교착상태 재현
 *
 * 컴파일: gcc deadlock_demo.c -o deadlock_demo -lpthread
 * 실행  : ./deadlock_demo
 *
 * 시나리오:
 *   Thread 1: Lock A → Lock B 순서
 *   Thread 2: Lock B → Lock A 순서
 *   → 서로 상대방이 가진 락 대기 → 교착상태!
 *
 * 해결법:
 *   모든 스레드가 같은 순서로 락을 획득하면 원형 대기가 깨짐
 *   → 4가지 필요조건 중 "원형 대기" 조건 제거
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_B = PTHREAD_MUTEX_INITIALIZER;

void *thread1_fn(void *arg) {
    pthread_mutex_lock(&lock_A);
    printf("[T1] 🔒 Lock A 획득\n");
    sleep(1);  /* 문맥 교환 유도 */

    printf("[T1] ⏳ Lock B 대기...\n");
    pthread_mutex_lock(&lock_B);
    printf("[T1] 🔒 Lock B 획득\n");

    pthread_mutex_unlock(&lock_B);
    pthread_mutex_unlock(&lock_A);
    return NULL;
}

void *thread2_fn(void *arg) {
    pthread_mutex_lock(&lock_B);
    printf("[T2] 🔒 Lock B 획득\n");
    sleep(1);

    printf("[T2] ⏳ Lock A 대기...\n");
    pthread_mutex_lock(&lock_A);
    printf("[T2] 🔒 Lock A 획득\n");

    pthread_mutex_unlock(&lock_A);
    pthread_mutex_unlock(&lock_B);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    printf("교착상태 재현 — Ctrl+C로 종료하세요\n\n");

    pthread_create(&t1, NULL, thread1_fn, NULL);
    pthread_create(&t2, NULL, thread2_fn, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /* 여기까지 도달하지 못함 (교착) */
    printf("종료\n");
    return 0;
}

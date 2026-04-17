/*
 * fork_demo.c — fork() 시스템 호출로 자식 프로세스 생성
 *
 * 컴파일: gcc fork_demo.c -o fork_demo
 * 실행  : ./fork_demo
 *
 * 학습 포인트:
 *  - fork()는 호출 시점에 프로세스를 복사하여 자식 프로세스 생성
 *  - fork()의 반환값:
 *      부모: 자식의 PID
 *      자식: 0
 *      실패: -1
 *  - 부모와 자식은 같은 코드를 공유하지만 데이터는 각자 독립
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int value = 100;
    pid_t pid;

    printf("[Before fork] PID = %d, PPID = %d, value = %d\n",
           getpid(), getppid(), value);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        /* 자식 프로세스 */
        value += 1;
        printf("[Child]  PID = %d, PPID = %d, value = %d\n",
               getpid(), getppid(), value);
    } else {
        /* 부모 프로세스 */
        value -= 1;
        printf("[Parent] PID = %d, CPID = %d, value = %d\n",
               getpid(), pid, value);
        wait(NULL);  /* 자식 종료 대기 (좀비 방지) */
        printf("[Parent] Child finished.\n");
    }

    return EXIT_SUCCESS;
}

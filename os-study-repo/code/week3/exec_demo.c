/*
 * exec_demo.c — exec() 계열 시스템 호출로 프로세스 이미지 교체
 *
 * 컴파일: gcc exec_demo.c -o exec_demo
 * 실행  : ./exec_demo
 *
 * 학습 포인트:
 *  - exec()는 현재 프로세스의 코드/데이터를 새 프로그램으로 덮어씀
 *  - 성공 시 이전 코드로 돌아오지 않음 (return 이후 코드는 실행 X)
 *  - PID는 유지, 메모리 이미지만 교체 → "전환"의 의미
 *  - fork() + exec() 조합이 전형적인 프로세스 생성 패턴
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("[Before exec] PID = %d\n", getpid());
    printf("[Before exec] 이 메시지는 보입니다.\n");

    pid_t pid = fork();

    if (pid == 0) {
        /* 자식: exec()로 ls 명령 실행 */
        printf("[Child] PID = %d, about to exec /bin/ls\n", getpid());
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        /* 여기 오면 exec 실패 */
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
        printf("[Parent] ls 실행이 끝났습니다. PID = %d\n", getpid());
    } else {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

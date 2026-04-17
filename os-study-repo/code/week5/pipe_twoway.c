/*
 * pipe_twoway.c — 양방향 파이프 IPC (단방향 2개로 구성)
 *
 * 컴파일: gcc pipe_twoway.c -o pipe_twoway
 * 실행  : ./pipe_twoway
 *
 * 구조:
 *   Parent ──→ PIPE1 ──→ Child
 *   Parent ←── PIPE2 ←── Child
 *
 * 포인트: 파이프 하나로 양방향 시도 시 데이터 충돌 발생 → 단방향 2개로 해결
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int pipe_p2c[2];  /* 부모 → 자식 */
    int pipe_c2p[2];  /* 자식 → 부모 */
    char buf[128];

    if (pipe(pipe_p2c) == -1 || pipe(pipe_c2p) == -1) {
        perror("pipe failed");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid == 0) {
        /* 자식 */
        close(pipe_p2c[1]);
        close(pipe_c2p[0]);

        /* 부모로부터 메시지 수신 */
        read(pipe_p2c[0], buf, sizeof(buf));
        printf("[Child] received: %s\n", buf);

        /* 답장 */
        const char *reply = "Hi parent, I got your message!";
        write(pipe_c2p[1], reply, strlen(reply) + 1);

        close(pipe_p2c[0]);
        close(pipe_c2p[1]);
    } else if (pid > 0) {
        /* 부모 */
        close(pipe_p2c[0]);
        close(pipe_c2p[1]);

        const char *msg = "Hello child!";
        write(pipe_p2c[1], msg, strlen(msg) + 1);
        printf("[Parent] sent: %s\n", msg);

        read(pipe_c2p[0], buf, sizeof(buf));
        printf("[Parent] received reply: %s\n", buf);

        close(pipe_p2c[1]);
        close(pipe_c2p[0]);
        wait(NULL);
    } else {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

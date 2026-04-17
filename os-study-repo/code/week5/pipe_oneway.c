/*
 * pipe_oneway.c — 단방향 파이프 IPC
 *
 * 컴파일: gcc pipe_oneway.c -o pipe_oneway
 * 실행  : ./pipe_oneway
 *
 * 구조:
 *   Parent (write) ──→ PIPE ──→ Child (read)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int pipe_fd[2];       /* [0] = read end, [1] = write end */
    char msg[] = "Hello from parent!";
    char buf[128];

    if (pipe(pipe_fd) == -1) {
        perror("pipe failed");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid == 0) {
        /* 자식: 읽기 */
        close(pipe_fd[1]);  /* 쓰기 끝단 닫음 */
        read(pipe_fd[0], buf, sizeof(buf));
        printf("[Child]  received: %s\n", buf);
        close(pipe_fd[0]);
    } else if (pid > 0) {
        /* 부모: 쓰기 */
        close(pipe_fd[0]);  /* 읽기 끝단 닫음 */
        write(pipe_fd[1], msg, strlen(msg) + 1);
        printf("[Parent] sent: %s\n", msg);
        close(pipe_fd[1]);
        wait(NULL);
    } else {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

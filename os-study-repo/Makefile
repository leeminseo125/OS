# Makefile — 실습 코드 전체 빌드
#
# 사용법:
#   make all      # 전체 빌드
#   make clean    # 빌드 결과물 제거
#   make week3    # 3주차만 빌드
#   make week5    # 5주차만 빌드
#   make week6    # 6주차만 빌드

CC      = gcc
CFLAGS  = -Wall -O2
LDFLAGS =
LDLIBS_PTHREAD = -lpthread

.PHONY: all clean week3 week5 week6

all: week3 week5 week6

week3: code/week3/fork_demo code/week3/exec_demo code/week3/thread_demo

week5: code/week5/pipe_oneway code/week5/pipe_twoway \
       code/week5/race_condition code/week5/semaphore_fix

week6: code/week6/deadlock_demo

# Week 3
code/week3/fork_demo: code/week3/fork_demo.c
	$(CC) $(CFLAGS) $< -o $@

code/week3/exec_demo: code/week3/exec_demo.c
	$(CC) $(CFLAGS) $< -o $@

code/week3/thread_demo: code/week3/thread_demo.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS_PTHREAD)

# Week 5
code/week5/pipe_oneway: code/week5/pipe_oneway.c
	$(CC) $(CFLAGS) $< -o $@

code/week5/pipe_twoway: code/week5/pipe_twoway.c
	$(CC) $(CFLAGS) $< -o $@

code/week5/race_condition: code/week5/race_condition.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS_PTHREAD)

code/week5/semaphore_fix: code/week5/semaphore_fix.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS_PTHREAD)

# Week 6
code/week6/deadlock_demo: code/week6/deadlock_demo.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS_PTHREAD)

clean:
	rm -f code/week3/fork_demo code/week3/exec_demo code/week3/thread_demo
	rm -f code/week5/pipe_oneway code/week5/pipe_twoway code/week5/race_condition code/week5/semaphore_fix
	rm -f code/week6/deadlock_demo

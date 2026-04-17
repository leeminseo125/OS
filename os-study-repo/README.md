# 🖥️ 운영체제 학습 노트 (Operating Systems Study Notes)

> 중간고사 대비 복습 자료 정리 (3~6주차)
>
> stamp.md 강의 요약 내용을 기반으로 재구성한 학습 레포지토리입니다.

## 📚 시험 범위

- **3주차** — 프로세스와 스레드
- **4주차** — CPU 스케줄링
- **5주차** — 프로세스 동기화 (IPC & 임계구역)
- **6주차** — 교착상태 (Deadlock)

> ⚠️ 1주차(운영체제 개요)와 2주차(컴퓨터시스템 구조)는 시험 범위에서 제외되었습니다.

## 🗂 레포 구조

```
os-study-repo/
├── README.md                    # 이 파일 (전체 학습 가이드)
├── docs/                        # 주차별 학습 노트 (Markdown)
│   ├── week3/                   # 프로세스와 스레드
│   ├── week4/                   # CPU 스케줄링
│   ├── week5/                   # 프로세스 동기화
│   └── week6/                   # 교착상태
├── slides/                      # 정제된 강의 슬라이드 PDF
├── code/                        # 실습 코드 예제
│   ├── week3/                   # fork, exec, thread
│   ├── week5/                   # pipe, semaphore, critical section
│   └── week6/                   # deadlock 실습
└── notion/                      # Notion 페이지 import용 마크다운
```

## 🎯 핵심 학습 목표

### 3주차 — 프로세스와 스레드
- [ ] 프로그램 vs 프로세스 vs 프로세서 차이 이해
- [ ] PCB(Process Control Block) 구성 요소 암기
- [ ] 프로세스 상태 다이어그램 (생성/준비/실행/대기/보류/종료)
- [ ] 문맥 교환(Context Switching) 메커니즘
- [ ] 프로세스 메모리 구조 (코드/데이터/힙/스택)
- [ ] fork() & exec() 시스템 호출
- [ ] 고아 프로세스 & 좀비 프로세스
- [ ] 스레드와 멀티스레드 모델 (1:1, N:1, N:M)

### 4주차 — CPU 스케줄링
- [ ] 선점형 vs 비선점형 스케줄링 비교
- [ ] 프로세스 우선순위 (커널 > 전면 > I/O 집중 > CPU 집중)
- [ ] 다중 큐 구조 (준비 상태 / 대기 상태)
- [ ] 스케줄링 알고리즘: **FCFS, SJF, HRN, RR, SRT, MLQ, MLFQ**
- [ ] 평균 대기시간 계산 연습
- [ ] 기아(아사) 현상 이해

### 5주차 — 프로세스 동기화
- [ ] IPC 기법 7종: 시그널, 인터럽트, 공유파일, 파이프, 메시지큐, 공유메모리, 소켓
- [ ] Interrupt vs Polling
- [ ] 임계구역(Critical Section)의 3가지 해결 조건: **상호배제, 한정대기, 진행의 융통성**
- [ ] 세마포어(Semaphore) — P/V 연산
- [ ] 뮤텍스(Mutex) vs 세마포어
- [ ] 모니터(Monitor)

### 6주차 — 교착상태
- [ ] 교착상태 4가지 필요조건: **상호배제, 비선점, 점유와 대기, 원형대기**
- [ ] 자원 할당 그래프 분석
- [ ] 식사하는 철학자 문제
- [ ] 교착상태 해결: **예방 / 회피 / 검출 & 회복 / 무시**
- [ ] 은행원 알고리즘 (Banker's Algorithm)

## 📖 학습 순서

1. [3주차 학습 노트](docs/week3/README.md) 부터 시작하세요.
2. 각 주차의 `README.md`에서 핵심 개념을 복습한 뒤,
3. `slides/`의 PDF 슬라이드로 그림과 함께 재학습하고,
4. `code/`의 실습 코드를 직접 돌려보세요.

## 🧪 실습 코드

| 주차 | 파일 | 주제 |
|------|------|------|
| 3주차 | `code/week3/fork_demo.c` | fork()로 자식 프로세스 생성 |
| 3주차 | `code/week3/exec_demo.c` | exec()로 프로세스 이미지 교체 |
| 3주차 | `code/week3/thread_demo.c` | pthread로 멀티스레드 |
| 5주차 | `code/week5/pipe_oneway.c` | 단방향 파이프 IPC |
| 5주차 | `code/week5/pipe_twoway.c` | 양방향 파이프 IPC |
| 5주차 | `code/week5/race_condition.c` | 임계구역 문제 재현 |
| 5주차 | `code/week5/semaphore_fix.c` | 세마포어로 문제 해결 |
| 6주차 | `code/week6/deadlock_demo.c` | 교착상태 재현 |

## 🔗 참고

- 강의 요약: `stamp.md` (원본 복습 자료)
- 정제된 슬라이드: `slides/` (3~6주차만)

---

> 💡 **Tip**: Notion으로 옮기려면 `notion/` 폴더의 마크다운 파일을 import하세요.

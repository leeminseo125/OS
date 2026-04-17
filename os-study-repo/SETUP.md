# 🚀 GitHub 레포지토리 업로드 가이드

이 폴더 전체를 GitHub 레포로 올리는 방법입니다.

## 1️⃣ GitHub에서 새 레포 생성

1. [github.com/new](https://github.com/new) 접속
2. Repository name: `os-study-notes` (원하는 이름)
3. Description: `운영체제 중간고사 대비 학습 노트 (3~6주차)`
4. **Public** 또는 **Private** 선택
5. ⚠️ `Initialize this repository with...` 옵션은 모두 **체크 해제**
6. `Create repository` 클릭

## 2️⃣ 로컬에서 업로드

터미널을 열고 이 폴더로 이동한 뒤:

```bash
cd os-study-repo

git init
git add .
git commit -m "Initial commit: 3~6주차 학습 노트"

git branch -M main
git remote add origin https://github.com/<YOUR-USERNAME>/os-study-notes.git
git push -u origin main
```

> `<YOUR-USERNAME>` 자리에 본인 GitHub 아이디를 넣으세요.

## 3️⃣ 확인

GitHub 페이지를 새로고침하면 파일들이 올라가 있습니다. `README.md`가 자동으로 표시됩니다.

## 📁 최종 레포 구조

```
os-study-repo/
├── README.md                    # 레포 메인 페이지
├── .gitignore
├── Makefile                     # 실습 코드 빌드용
├── docs/
│   ├── week3/README.md          # 프로세스와 스레드
│   ├── week4/README.md          # CPU 스케줄링
│   ├── week5/README.md          # 프로세스 동기화
│   └── week6/README.md          # 교착상태
├── slides/
│   ├── 3주차__프로세스와_스레드.pdf
│   ├── 4주차__CPU_스케줄링.pdf
│   ├── 5주차__프로세스_동기화.pdf    (25,26번 제외)
│   └── 6주차__교착상태.pdf
├── code/
│   ├── week3/
│   │   ├── fork_demo.c
│   │   ├── exec_demo.c
│   │   └── thread_demo.c
│   ├── week5/
│   │   ├── pipe_oneway.c
│   │   ├── pipe_twoway.c
│   │   ├── race_condition.c
│   │   └── semaphore_fix.c
│   └── week6/
│       └── deadlock_demo.c
└── notion/
    ├── README.md                  # Notion import 가이드
    ├── 00_index.md                # 루트 페이지
    ├── 01_week3_process_thread.md
    ├── 02_week4_cpu_scheduling.md
    ├── 03_week5_synchronization.md
    └── 04_week6_deadlock.md
```

## 🧪 코드 실행 방법

```bash
# 전체 빌드
make all

# 개별 실행
./code/week3/fork_demo
./code/week5/pipe_oneway
./code/week6/deadlock_demo   # Ctrl+C로 종료

# 정리
make clean
```

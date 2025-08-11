# Refactoring Test

## Build

```sh
make
```

## Run

```sh
make run
```

## Tests

```sh
make test
```

## Static Analysis

```sh
make lint
```

## 변경 사항 요약
- 전역 변수 제거 및 `ProgramData` 구조체 도입
- 안전한 문자열 처리 (`snprintf` 사용)로 버퍼 오버플로 제거
- 불필요한 동적 메모리 할당 제거로 메모리 누수 방지
- 깊게 중첩된 조건을 단일 조건식으로 평탄화
- 명확한 함수명과 정적 내부 링크로 가독성 향상
- `main` 함수를 `run_application`으로 리팩토링 및 `app_main.c`로 애플리케이션 진입점 분리

## 참고
- `make lint` 명령을 실행하려면 `clang-tidy`가 설치되어 있어야 합니다.

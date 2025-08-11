# Refactoring Test

## Build

```sh
cc -Wall -Wextra -O2 -o app bad_code.c
```

## Run

```sh
./app
```

## 변경 사항 요약
- 전역 변수 제거 및 `ProgramData` 구조체 도입
- 안전한 문자열 처리 (`snprintf` 사용)로 버퍼 오버플로 제거
- 불필요한 동적 메모리 할당 제거로 메모리 누수 방지
- 깊게 중첩된 조건을 단일 조건식으로 평탄화
- 명확한 함수명과 정적 내부 링크로 가독성 향상

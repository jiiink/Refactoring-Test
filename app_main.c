#include <stdio.h>

// bad_code.c에 정의된 애플리케이션 실행 함수 선언
extern int run_application(void);

int main(void) {
    printf("Starting application from app_main.c...\n");
    return run_application();
}

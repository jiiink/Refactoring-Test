#include <stdio.h>
#include <stdlib.h>

// 외부 함수 선언 (bad_code.c에 정의된 함수)
extern void process_items(const char *message, size_t count);
extern void print_program_data(const void *data);

// ProgramData 구조체 정의 (bad_code.c와 동일하게)
typedef struct {
    int a;
    int b;
    int c;
} ProgramData;

// 테스트 함수 매크로
#define TEST_ASSERT(condition, message) do { \
    if (!(condition)) { \
        fprintf(stderr, "Test failed: %s at %s:%d - %s\n", __func__, __FILE__, __LINE__, message); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

void test_process_items() {
    printf("Running test_process_items...\n");
    // 이 함수는 주로 출력을 생성하므로, 직접적인 반환값 테스트는 어려움.
    // 대신, 실행 시 크래시가 없음을 확인하는 방식으로 테스트.
    process_items("Test", 2); // Should not crash
    printf("test_process_items passed.\n");
}

void test_print_program_data() {
    printf("Running test_print_program_data...\n");
    ProgramData test_data = { .a = 1, .b = 2, .c = 3 };
    // 이 함수도 주로 출력을 생성하므로, 직접적인 반환값 테스트는 어려움.
    // Null 포인터 테스트
    print_program_data(NULL); // Should not crash
    print_program_data(&test_data); // Should not crash
    printf("test_print_program_data passed.\n");
}

int main() {
    printf("Starting tests...\n");
    test_process_items();
    test_print_program_data();
    printf("All tests passed!\n");
    return 0;
}

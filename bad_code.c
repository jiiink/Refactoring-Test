#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
} ProgramData;

void process_items(const char *message, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        printf("Processing: %s - %zu\n", message, i);
        if (i % 2 == 0) {
            printf("Even number!\n");
        } else {
            printf("Odd number!\n");
        }
        if (i > 5) {
            printf("Too big!\n");
        }
    }
}

void print_program_data(const ProgramData *data) {
    if (data == NULL) {
        return;
    }
    printf("a=%d, b=%d, c=%d\n", data->a, data->b, data->c);
}

int run_application(void) {
    // 안전한 문자열 처리: 버퍼 크기를 초과하지 않도록 보장
    char buffer[16];
    const char *source = "ThisIsTooLongForBuffer";
    // snprintf는 버퍼 크기를 넘기지 않으며, 항상 null-terminating을 보장
    snprintf(buffer, sizeof(buffer), "%s", source);

    ProgramData data = { .a = 10, .b = 20, .c = 30 };

    process_items("Hello", 3);
    process_items("World", 10);
    print_program_data(&data);

    // 불필요한 동적 할당을 피하고 누수 방지
    char message[] = "Memory leak example";
    printf("%s\n", message);

    if (data.a == 10 && data.b == 20 && data.c == 30) {
        printf("Flattened and readable condition!\n");
    }

    return 0;
}

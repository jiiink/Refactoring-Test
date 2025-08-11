#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 0, b = 0, c = 0; // 전역 변수

void doStuff(char *str, int num) {
    int i;
    for(i = 0; i < num; i++) {
        printf("Processing: %s - %d\n", str, i);
        if(i % 2 == 0) {
            printf("Even number!\n");
        }
        if(i % 2 == 1) {
            printf("Odd number!\n");
        }
        if(i > 5) {
            printf("Too big!\n");
        }
    }
}

void printData() {
    printf("a=%d, b=%d, c=%d\n", a, b, c);
}

int main() {
    char buffer[10]; // 버퍼 크기 작음 → 오버플로 가능성
    strcpy(buffer, "ThisIsTooLongForBuffer"); // 의도적 버그
    a = 10; b = 20; c = 30;

    doStuff("Hello", 3);
    doStuff("World", 10);
    printData();

    char *ptr = malloc(100); // 메모리 할당 후 해제 안 함
    strcpy(ptr, "Memory leak example");
    printf("%s\n", ptr);

    if(a == 10)
        if(b == 20)
            if(c == 30)
                printf("Nested ifs are hard to read!\n");

    return 0;
}

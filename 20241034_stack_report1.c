// 텍스트 반전

#include <stdio.h>
#include <string.h>

#define MAX 100

// stack 기능 코드

int main() {
    Stack s;
    char str[MAX];
    initStack(&s);
    
    printf("문자열 입력: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    for(int i=0; str[i] != '\0'; i++)   push(&s, str[i]);
    printf("거꾸로 된 문자열: ");
    while(!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
  
    return 0;
}

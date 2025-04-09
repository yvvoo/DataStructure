#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;  
}

int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);  

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // 피연산자 (숫자)
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        // 연산자
        else {
            int b = pop(&s);  
            int a = pop(&s); 
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator encountered.\n");
                    exit(1);
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

int infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j=0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 피연산자 (알파벳 또는 숫자)
        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        // 여는 괄호
        else if (ch == '(') {
            push(&s, ch);
        }
        // 닫는 괄호
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);  
            }
            pop(&s);  
        }
        // 연산자
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);  
            }
            push(&s, ch); 
        }
    }
    
    while (!isEmpty(&s))    postfix[j++] = pop(&s);
    postfix[j] = '\0';
    
    return evaluatePostfix(postfix);
}


int main()
{
    char infix[MAX];
    char postfix[MAX];
    int result;
    printf(":중위표기식 입력 : ");
    scanf("%s", infix);
    result = infixToPostfix(infix, postfix);
    printf("후위표기식 :%s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct {
    int data[SIZE];
    int rear;
    int front;
} LinearQueue;

void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;
}
bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;
}
bool isFull(LinearQueue *q) {
    return q->rear == SIZE -1;
}

//삽입 함수
bool enqueue(LinearQueue *q, int value) {
    if(isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    return true;
}
//삭제 함수
int dequeue(LinearQueue *q) {
    if(isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}
// //큐 초기화 함수
// void resetQueue() {
//     front = -1;
//     rear = -1;
// }

//큐 출력 함수
void printQueue(LinearQueue* q) {
    if(isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }    
    printf("큐의 데이터 : ");
    for(int i = q->front; i<= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}


int main() {
    LinearQueue q;
    initQueue(&q);
    int choice, value;
    
    while (true) {
        printf("------ 큐 프로그램 ------\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("삽입할 값 입력 : ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) printf("dequeue value : %d\n", value);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
    }
    return 0;
}

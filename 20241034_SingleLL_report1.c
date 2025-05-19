#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    return newNode;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(head == NULL) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;
    
    while (current != NULL) {
        if (current->data == targetValue) {
            
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    free(temp);
    
    return head;
}

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다. 삭제할 노드가 없습니다.\n");
    }
    
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    
    return head;
}

Node* deleteNode(Node* head, int targetValue) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
        return NULL;
    }
        if (head->data == targetValue) { 
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != targetValue) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
        return head;
    }

    Node* temp = current->next; 
    current->next = current->next->next; 
    free(temp);                 

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("모든 노드가 제거되었습니다.\n");
}

int searchValue1(Node* head, int val) {
    if(head == NULL){
        printf("Head Node가 NULL 입니다.\n");
        return -1;
    }
    Node* current = head;
    int pos = 0;
    while (current != NULL) {
        ++pos;
        if(current->data == val) return pos;
        else current = current->next;
    }
    printf("값이 없습니다.\n");
    return -1;
}

void searchValue2(Node* head, int val) {
    if (head == NULL) {
        printf("Head Node가 NULL입니다.\n");
        return;
    }
    if (head->data == val) {
        printf("%d의 이전값 : 없음\n", val);
        printf("%d의 다음값 : %d\n", val, head->next->data);
        return;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data != val) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("%d를 찾을 수 없습니다.\n", val);
        return;
    }
    printf("%d의 이전값 : %d\n", val, current->data);
    printf("%d의 다음값 : %d\n", val, current->next->next->data);
    
}

int main() {
    Node* head = NULL;
    int value = 0;
    for (int i=0;i<10;i++) {
        head = insertLast(head, i);
    }
    
    printList(head);
    searchValue2(head, 5);
    freeList(head);
    
    return 0;
    
}

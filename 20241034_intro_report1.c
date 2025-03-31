// 학생 성적 관리 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENTS 10

int main() {
    int scores[STUDENTS]; 
    int sum = 0; 
    double average; 

    srand(time(NULL)); 

    printf("학생 성적: ");
    for (int i = 0; i < STUDENTS; i++) {
        scores[i] = rand() % 101; 
        sum += scores[i];
        printf("%d ", scores[i]); 
    }

    average = (double)sum / STUDENTS;

    printf("\n전체 학생 평균 점수: %.2f\n", average);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int grades[5];
    float average;
} Student;

void calculateAverage(Student *student) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 5.0;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student *students = malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter 5 grades for %s: ", students[i].name);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].grades[j]);
        }
        calculateAverage(&students[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%s: Average = %.2f\n", students[i].name, students[i].average);
    }

    free(students);
    return 0;
}
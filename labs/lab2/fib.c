#include <stdio.h>

typedef struct student{
    int id;
    int age;
}student_t;

int main(){
    student_t s1;
    student_t s2;

    //let's assign some values to s1, s2

    s1.id = 1001;
    s1.age  = 23;

    s2.id = 1002;
    s2.age = 24;

    printf("Student ID: %d, Age: %d\n", s1.id, s1.age);
    printf("Student ID: %d, Age: %d\n", s2.id, s2.age);

    return 0;
}
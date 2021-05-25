#include <stdio.h>

typedef struct student{
    int id;
    int age;
}student_t;

void printStudent(student_t aStudent){
    printf("Student ID: %d, Age: %d\n",
           aStudent.id, aStudent.age);
}

int main(){
    student_t s1;
    student_t s2;

    //let's assign some values to s1, s2

    s1.id = 1001;
    s1.age  = 23;

    s2.id = 1002;
    s2.age = 24;

    printStudent(s1);
    printStudent(s2);
    s2.id = 1003;

    printStudent(s2);


    return 0;
}
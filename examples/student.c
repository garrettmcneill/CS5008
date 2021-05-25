#include <stdio.h>

typedef struct student{
    int id;
    int age;
}student_t;

void printStudent(student_t* aStudent){
    printf("Student ID: %d, Age: %d\n",
           aStudent->id, (*aStudent).age);
    // use the -> to dereference without needing a star and dot
}


void updateStudent(student_t* aStudent, int age, int id){
    (*aStudent).age = age;
    (*aStudent).id = id;
}

student_t* makeStudent(int age, int id){
    stuednt_t* p_aStudent =
            (student_t*)malloc(sizeof(student_t));
    student_t p_aStudent;
    p_aStudent.age = age;
    p_aStudent.id = id;
    return p_aStudent;
}


int main(){
    student_t* s1 = makeStudent(23, 1001);
    student_t* s2 = makeStudent(24, 1002);

    //let's assign some values to s1, s2

    updateStudent(s1, 23, 1001);
    updateStudent(s2, 24, 1002);

    printStudent(s1);
    printStudent(s2);

    updateStudent(s2, s2->age, 1003);

    printStudent(s2);


    return 0;
}
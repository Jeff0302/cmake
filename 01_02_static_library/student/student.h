#include<string>
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
private:
    std::string name;
    int age;
public:
    Student(char *name, int age);
    ~Student();
};

#endif
#include "student.h"
#include<iostream>

Student::Student(char* name, int age):name(name), age(age)
{
    std::cout << "Student�c�y���"<<std::endl;
}

Student::~Student()
{
}
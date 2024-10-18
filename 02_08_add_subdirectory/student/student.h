#include<string>
#ifndef STUDENT_H
#define STUDENT_H


#ifdef student_STATIC
    #define STUDENT_API 
#else
    #ifdef student_EXPORTS
        #define STUDENT_API __declspec(dllexport)
    #else   
        #define STUDENT_API __declspec(dllimport)  
    #endif

#endif
    

class STUDENT_API Student
{
private:
    std::string name;
    int age;
public:
    Student(char *name, int age);
    ~Student();
};

#endif
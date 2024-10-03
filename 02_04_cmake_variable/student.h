#include<string>
#ifndef STUDENT_H
#define STUDENT_H

#ifndef _WIN32
    //如果不是windows，則導出庫，不需要添加__declspec()宏
    #define STUDENT_API
#else
    #ifdef student_STATIC
        #define STUDENT_API 
    #else
        #ifdef student_EXPORTS
            #define STUDENT_API __declspec(dllexport)
        #else
            #define STUDENT_API __declspec(dllimport)
        #endif
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
#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    cout << "hello!" << endl;
    #ifdef PARA1
    cout << "PARA1=" << PARA1 << endl;
    #endif

    #ifdef PARA2
    cout << "PARA2=" << PARA2 << endl;
    #endif

    #ifdef PARA3
    cout << "PARA3=" << PARA2 << endl;
    #endif
    return 0;
}

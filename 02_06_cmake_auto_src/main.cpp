#include<iostream>
#include "xlog.h"
#include "xthread.hpp"
using namespace std;

int main(){
    cout << "auto source head" << endl;
    xlog();
    xthread();
    return 0;
}
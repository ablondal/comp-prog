#include <iostream> 
using namespace std; 
void f1(variable){if(variable ==false){variable = true; cout << variable; f2(variable);}} 
void f2(variable){if(variable ==true){variable = false; cout << variable; f1(variable);}}
int main(void){bool x = false; f1(x); return 0;}
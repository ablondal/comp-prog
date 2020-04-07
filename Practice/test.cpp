#include <iostream>
using namespace std;
typedef long double ld;

int main(){
	ld a = 100.0/100003.0;
	ld b = 10.0/10002.0;

	cout << a << "==" << b << "->" << (a==b) << endl; 
}
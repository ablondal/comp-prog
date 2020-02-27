#include <iostream>
using namespace std;


long long gcd( long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}


int main(){
    long long a, b;
    cin >> a >> b;
    long long c = gcd(a,b);
    if (a/c % 2 == 1 && b/c % 2 == 1) cout << c << endl;
    else cout << 0 << endl;
    //cout << gcd(a,b) << endl;
}
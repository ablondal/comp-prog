#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef long long ll;


int main(){
    int P, D;
    cin >> P >> D;
    vector <ll> D_A, D_B;
    ll w_a(0), w_b(0), v(0);
    D_A.resize(D+1,0);
    D_B.resize(D+1,0);
    ll a,b,wa,wb;
    int d;
    for(int i=0; i<P ;++i){
        cin >> d >> a >> b;
        D_A[d] += a;
        D_B[d] += b;
        v += a+b;
    }
    for(int i=1; i<=D; ++i){
        a = D_A[i];
        b = D_B[i];
        if(a > b){
            wa = a - floor((a+b)/2.0) - 1;
            wb = b;
            cout << "A " << wa << " " << wb << endl;
        }else{
            wb = b - floor((a+b)/2.0) - 1;
            wa = a;
            cout << "B " << wa << " " << wb << endl;
        }
        w_a += wa;
        w_b += wb;
    }
    printf("%0.8lf\n",double(abs(w_a-w_b))/v);
    //cout << setprecision(100) << double(abs(w_a-w_b))/v << endl;
}
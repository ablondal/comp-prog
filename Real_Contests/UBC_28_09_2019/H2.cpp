#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

ull suspect(ull b, ull t, ull u, ull n){
    ull prod=1;
    while(u)
    {
    if(u&1) prod=((prod*b)%n);
    b=((b*b)%n);
    u/=2;
    }
    if(prod == 1) return 1;
    for(ull i = 1; i <= t; i++)
    {
    if(prod == n-1) return 1;
    prod = (prod * prod) % n;
    }
    return 0;
}

ull isprime(ull n)
    {
    ull k = n - 1;
    ull t = 0;
    while(!(k%2)) { t++; k/=2; }
    if(n>2 && n%2==0) return 0;
    if(n>3 && n%3==0) return 0;
    if(n>5 && n%5==0) return 0;
    if(n>7 && n%7==0) return 0;
    if(suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n))
    return 1;
    return 0;
}

ull gcd( ull a, ull b ){
    if( b==0) return a;
    return gcd(b, a%b);
}

ull g( ull x, ull N, ull i ){
    x %= N;
    x = x*x % N;
    x += i;
    x %= N;
    return x;
}
void sieve_factor(ull C, vector <ull> &Res);

void rho_factor(ull C, vector <ull> &Res){
    if (C < 10e6){
        sieve_factor(C, Res);
        return;
    }
    if(isprime(C)){
        Res.push_back(C);
        return;
    }
    ull x_fixed, x, size, d, count, tim;
    tim = 1;
    x_fixed = 2;
    x = 2;
    size = 2;
    d=1;
    while(d==1)
    {
        count = size;
        while(count != 0 && d==1){
            x = g(x,C,tim);
            if(x>x_fixed) d = gcd(x-x_fixed, C);
            else d = gcd(x_fixed-x, C);
            count--;
        }
        size *= 2;
        x_fixed = x;
        if(d==C){
            tim++;
            x_fixed = 2;
            x = 2;
            size = 2;
            d = 1;
        }
    }
    
    rho_factor(C/d, Res);
    rho_factor(d, Res);
}

void sieve_factor(ull C, vector <ull> &Res){
    
    ull numofi = 0;
    while (C % 2 == 0){
        numofi++;
        C /= 2;
        //csqrt = sqrt(C);
    }
    if(numofi%2==1){
        Res.push_back(2);
    }
    numofi = 0;
    float csqrt = sqrt(C);
    for(ull i=3; i<csqrt; i+=2){
        if( C % i == 0){
            //cout << "Factor: " << i << endl;

            while (C % i == 0){
                numofi++;
                C /= i;
                csqrt = sqrt(C);
            }
            if(numofi%2==1){
                Res.push_back(i);
            }
            numofi = 0;
        }
    }
    if(C!=1) Res.push_back(C);
}


int main(){
    ull C;
    cin >> C;
    //scanf("%lli",&C);
    vector <ull> Res;
    sieve_factor(C, Res);
    sort(Res.begin(), Res.end());
    
    ull D = 1;
    bool rpt = 0;
    ull j;
    for(ull i=0; i < Res.size(); ){
        j = i+1;
        while(j!=Res.size() && Res[j] == Res[i]) ++j;
        if( (j-i) % 2 == 1 ) D *= Res[i];
        i = j;
    }
    cout << D << endl;
    return 0;
}
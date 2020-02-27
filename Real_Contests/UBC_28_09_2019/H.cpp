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

ull suspect(ull b, ull t, ull u, ull n)
{
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

void sieve_factor(ull C, vector <ull> &Res)
{
    
    ull numofi = 0;
    while (C % 2 == 0){
        numofi++;
        C /= 2;
        //csqrt = sqrt(C);
    }
    if(numofi%2==1){
        Res.push_back(2);
    }
    if (isprime(C)){
        Res.push_back(C);
        return;
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
            if (isprime(C)){
                Res.push_back(C);
                return;
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
    ull D = 1;
    for(ull i=0; i < Res.size(); ++i){
        D *= Res[i];
    }
    cout << D << endl;
    return 0;
}
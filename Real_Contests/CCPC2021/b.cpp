#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

ld n_days[307];

ld DP[307] = {0};

int main(){
    int n;
    long double x, y, z, c, r;
    scanf("%d %Lf %Lf %Lf %Lf %Lf", &n, &x, &y, &z, &c, &r);

    n_days[0] = 1;
    rep(i,1,n+1){
        n_days[i] = n_days[i-1]*(1 + r/100.0);
        // cout << n_days[i] << endl;
    }

    DP[0] = x;
    rep(i,0,n){
        rep(j,i+1,n+1){
            ld pay = (j-i)*y;
            ld credit = 0;
            // cout << pay << endl;
            if (pay > z){
                credit = (pay-z) * (c/100.0);
            }
            // cout << pay << endl;
            ld fin = DP[i] - pay + credit;
            // cout << fin << endl;
            fin *= n_days[j-i];
            // cout << fin << endl;
            // printf("%Ld to %Ld: left with %Lf\n", i, j, fin);
            DP[j] = max(DP[j], fin);
        }
    }
    printf("%0.10Lf\n", DP[n]);

    // long double total1 = x;
    // for (int i = 0; i < n; i++){
    //     total1 -= y;
    //     if(y > z){
    //         total1 += (y - z) * (c / 100);
    //     }
    //     total1 += total1 * (r/100);
    // }
    // long double total2 = x;
    // total2 -= y * n;
    // if(y*n > z){
    //     total2 += ((y * n) - z) * (c / 100);
    // }
    // for (int i = 0; i < n; i++){
    //     total2 += total2 * (r/100);
    // }

    // long double maxtot = 0;
    // // for(int i=1; i<)
    // printf("%0.10Lf\n", max(total1, total2));
}
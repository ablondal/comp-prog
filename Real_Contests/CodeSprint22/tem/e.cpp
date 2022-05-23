#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod=1e9+7;
ll f[3007][6007] = {{0}};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m, i, j, k, s, t, tt;
    string st;
    cin>>n;
    cin>>st;

    f[0][3002]=1;

    for(i=0;i<n;++i){
        if(st[i]=='F'){
            for(j=0;j<=6004;++j)f[i+1][j]+=f[i][j];
        }else if(st[i]=='A'){
            for(j=0;j<=6004;++j)f[i+1][j]+=f[i][j]*2;
            for(j=0;j<=6004;++j)f[i+1][j]+=f[i][j+1];
        }else{
            for(j=0;j<=6004;++j)f[i+1][j]+=f[i][j];
            for(j=0;j<=6004;++j)f[i+1][j]+=f[i][j+1];
            for(j=1;j<=6004;++j)f[i+1][j]+=f[i][j-1];
        }
    }   for(j=0;j<=6004;++j)f[i+1][j]%=mod;
    s=0;
    for(i=3003;i<=6004;++i){
        s+=f[n][i];
        s %= mod;
    }
    // s%=mod;
    cout<<s<<endl;
    return 0;
}
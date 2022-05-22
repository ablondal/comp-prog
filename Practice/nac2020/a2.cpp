#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e6+7;
const ll MOD = 998244353;
//phi
const int LIM=2000000;
int phi[LIM];
void calculatePhi(){
    rep(i,0,LIM)phi[i]=i&1?i:i/2;
    for(int i=3;i<LIM;i+=2)if(phi[i]==i)
        for(int j=i;j<LIM;j+=i)phi[j]-=phi[j]/i;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    calculatePhi(Q);
    ll m, k, s, t, i;
    cin >> m >> k;
    vector<ll>f(m+1);
    f[1]=3;
    s=0;
    for(i=1;i<=k;++i)s=(s+phi[i])%MOD;
    //cout<<s<<endl;
    f[2]=(((s*2-1)*2+1)*2+f[1])%MOD;
    for(i=3;i<=m;++i){
        f[i]=(((f[i-1]-f[i-2]+MOD)%MOD)*(k*2+1)+f[i-1])%MOD;
    }
    //for(i=1;i<=m;++i)cout<<i<<" "<<f[i]<<endl;
    cout<<f[m]<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

vector<vi> p[10];

void make_p(int k){
    int dir = -1;
    int pos = k-1;
    for(auto pi: p[k-1]){
        p[k].push_back(vi(all(pi)));
        p[k].back().insert(p[k].back().begin()+pos, k);
        while(pos+dir >= 0 && pos+dir < k){
            pos += dir;
            p[k].push_back(vi(all(pi)));
            p[k].back().insert(p[k].back().begin()+pos, k);
        }
        dir *= -1;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    p[1] = {{1}};
    rep(k,2,n+1){
        make_p(k);
    }
    for(auto &pi : p[n]){
        for(auto a: pi){
            cout << a << " ";
        }
        cout << endl;
    }

}
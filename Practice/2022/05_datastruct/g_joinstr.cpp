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
const int SQ = 1024;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> S(n);
	vector<int> NX(n,-1);
	vector<int> LX(n,-1);
	rep(i,0,n){
		cin >> S[i];
		LX[i] = i;
	}
	int li=0;
	rep(i,0,n-1){
		int a, b;
		cin >> a >> b;
		a--;b--;
		NX[LX[a]] = b;
		LX[a] = LX[b];
		li=a;
	}
	while(li!=-1){
		cout << S[li];
		li=NX[li];
	}
	cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, int> M = {{4,0},{8,1},{15,2},{16,3},{23,4},{42,5}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n){
		cin >> a[i];
	}

	int rm = 0;
	int num[6] = {0};
	rep(i,0,n){
		int b = M[a[i]];
		if (b==0 || num[b-1]>num[b]){
			num[b]++;
		} else {
			rm++;
		}
	}
	rep(i,0,6){
		rm += num[i] - num[5];
	}
	cout << rm << endl;
}
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

const double PI = acos(-1);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double A, N;
	cin >> A >> N;

	double r = N / (2*PI);
	double a = PI * r * r;
	if (a >= A){
		cout << "Diablo is happy!" << endl;
	} else {
		cout << "Need more materials!" << endl;
	}

}
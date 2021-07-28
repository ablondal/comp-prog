#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int t = 0;
	t += (n/100);
	n %= 100;
	t += (n/20);
	n %= 20;
	t += (n/10);
	n %= 10;
	t += n/5;
	n %= 5;
	t += n;
	cout << t << endl;
}
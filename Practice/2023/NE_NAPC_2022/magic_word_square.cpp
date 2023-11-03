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
const int NWD = 26*26*26;

vector<string> words;
vector<string> wa[26];
vector<string> wb[26][26];
char ex[26][26][26] = {0};
char used[26] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, n2;
	cin >> n;
	n2 = n;
	rep(i,0,n){
		string a;
		cin >> a;
		a[0]-='a'; a[1]-='a'; a[2]-='a';
		if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2] || ex[a[0]][a[1]][a[2]]){
			n2--;
			continue;
		}
		words.push_back(a);
		ex[a[0]][a[1]][a[2]] = true;
		wa[a[0]].push_back(a);
		wb[a[0]][a[1]].push_back(a);
	}
	n = n2;
	// string c1(3), c2(3), c3(3);
	int tot = 0;
	rep(i,0,n){
		string w = words[i];
		// c1[0] = w[0]; c2[0] = w[1]; c3[0] = w[2];
		if (wa[w[0]].empty() || wa[w[1]].empty() || wa[w[2]].empty()) {
			continue;
		}
		used[w[0]] = used[w[1]] = used[w[2]] = true;
		rep(j,0,n){
			if (i==j) continue;
			string w2 = words[j];
			if (wb[w[0]][w2[0]].empty() ||
				wb[w[1]][w2[1]].empty() ||
				wb[w[2]][w2[2]].empty() ||
				wb[w[0]][w2[1]].empty() ||
				wb[w[2]][w2[1]].empty() ||
				used[w2[0]] || used[w2[1]] || used[w2[2]]) {
				continue;
			}
			used[w2[0]] = used[w2[1]] = used[w2[2]] = true;
			rep(k,0,n){
				if (k==i || k==j) continue;
				string w3 = words[k];
				if (used[w3[0]] || used[w3[1]] || used[w3[2]]) {
					continue;
				}
				if (ex[w[0]][w2[0]][w3[0]] &&
					ex[w[1]][w2[1]][w3[1]] &&
					ex[w[2]][w2[2]][w3[2]] &&
					ex[w[0]][w2[1]][w3[2]] &&
					ex[w[2]][w2[1]][w3[0]]) {
					tot++;
				}
			}
			used[w2[0]] = used[w2[1]] = used[w2[2]] = false;
		}
		used[w[0]] = used[w[1]] = used[w[2]] = false;
	}
	cout << tot << endl;
}
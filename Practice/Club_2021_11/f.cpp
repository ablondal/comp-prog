#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n;
	// scanf("%d", &n);
	string s;
	cin >> s;
	int on = 0;
	vi a(sz(s)+1, 0);
	int op = 0;
	int cl = 0;
	int qq = 0;
	for(int i=sz(s)-1; i>=0; --i){
		if (s[i] == '(') op++;
		else if (s[i] == ')') cl++;
		else qq++;
	}
	bool g = true;
	if ((op+cl+qq)%2==1) g = false;

	if (op+qq < cl || cl+qq < op){
		g = false;
	}

	int nop = sz(s)/2 - op;

	for(int i=0; i<sz(s); ++i){
		char c = s[i];
		if (c == '(') on++;
		if (c == ')') on--;
		if (c == '?'){
			if (nop){
				on++;
				s[i] = '(';
				nop--;
			}else{
				on--;
				s[i] = ')';
			}
		}
		if (on < 0){
			g = false;
		}
	}
	if (!g || on!=0){
		cout << "Impossible" << endl;
	}else
		cout << s << endl;
}
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

map<char, string> A{
	{'a',"@"},
	{'b',"8"},
	{'c',"("},
	{'d',"|)"},
	{'e',"3"},
	{'f',"#"},
	{'g',"6"},
	{'h',"[-]"},
	{'i',"|"},
	{'j',"_|"},
	{'k',"|<"},
	{'l',"1"},
	{'m',"[]\\/[]"},
	{'n',"[]\\[]"},
	{'o',"0"},
	{'p',"|D"},
	{'q',"(,)"},
	{'r',"|Z"},
	{'s',"$"},
	{'t',"']['"},
	{'u',"|_|"},
	{'v',"\\/"},
	{'w',"\\/\\/"},
	{'x',"}{"},
	{'y',"`/"},
	{'z',"2"}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string a;
	getline(cin, s);
	for(auto c : s){
		if ('A' <= c && c <= 'Z') c += ('a'-'A');
		if ('a'<=c && c <= 'z') a += A[c];
		else a.push_back(c);
	}
	cout << a << endl;
}
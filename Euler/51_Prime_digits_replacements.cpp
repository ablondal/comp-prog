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

const int LIM = 1e7;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

int toint(string s){
	int i=0;
	for(auto c : s){
		i *= 10;
		i+= c-'0';
	}
	return i;
}

string tostring(int i){
	string res;
	do{
		res.push_back('0'+ (i%10));
		i /= 10;
	}while(i);
	reverse(all(res));
	return res;
}

bool check(string a){
	int ct = 0;
	rep(i,0,10){
		if (a[0] == '*' && i==0) continue;
		string b(a);
		for(auto &c : b){
			if (c == '*') c = '0'+i;
		}
		if (isPrime[toint(b)]) ct++;
	}
	if (ct == 8) {
		rep(i,0,10){
			if (a[0] == '*' && i==0) continue;
			string b(a);
			for(auto &c : b){
				if (c == '*') c = '0'+i;
			}
			if (isPrime[toint(b)]) cout << b << endl;
		}
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto p = eratosthenes();
	string a;
	int i = 1;
	while(true){
		a.clear();
		int b = i;
		while(b){
			a.push_back('0' + b % 11);
			if (a.back() == '0' + 10) a.back() = '*';
			b /= 11;
		}
		if (a.find('*') != string::npos) {
			cout << a << endl;
			if (check(a)){
				break;
			}
		}
		i++;
	}
}
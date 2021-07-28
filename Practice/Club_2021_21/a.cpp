#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<string> ones;
set<string> twos;
set<string> threes;

string test(){
	string s;
	rep(i,0,26){
		s.push_back('a'+i);
		if ( !ones.count(s)){
			return s;
		}
		s.pop_back();
	}

	rep(i,0,26){
		s.push_back('a'+i);
		rep(j,0,26){
			s.push_back('a'+j);
			if (!twos.count(s)){
				return s;
			}
			s.pop_back();
		}
		s.pop_back();
	}

	rep(i,0,26){
		s.push_back('a'+i);
		rep(j,0,26){
			s.push_back('a'+j);
			rep(k,0,26){
				s.push_back('a'+k);
				if(!threes.count(s)){
					return s;
				}
				s.pop_back();
			}
			s.pop_back();
		}
		s.pop_back();
	}
	return "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ones.clear();
		twos.clear();
		threes.clear();
		int n;
		cin >> n;
		string s;
		cin >> s;
		rep(i,0,sz(s)){
			ones.insert(s.substr(i,1));
			if (i>0) twos.insert(s.substr(i-1,2));
			if (i>1) threes.insert(s.substr(i-2,3));
		}
		cout << test() << endl;
	}
}
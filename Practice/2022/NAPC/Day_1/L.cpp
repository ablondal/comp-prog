#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;
int L[MX] = {0}, R[MX] = {0};

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vi val(n);
	rep(i,0,n) cin >> val[i];
	L[0] = R[n-1] = -1;
	rep(i,1,n){
		L[i] = i-1;
	}
	rep(i,0,n-1){
		R[i] = i+1;
	}

	set<int> tocheck;
	vi left(n);
	vector<int> Q;
	rep(i,0,n){
		tocheck.insert(i);
		left[i] = true;;
	}
	vector<vi> ans;

	while(true){
		Q.clear();
		Q.assign(all(tocheck));
		tocheck.clear();
		ans.emplace_back();

		vector<int> todel;
		for(auto i : Q){
			if (!left[i]) continue;
			bool del = false;
			if (L[i] != -1 && val[L[i]]>val[i]) del = true;
			if (R[i] != -1 && val[R[i]]>val[i]) del = true;

			if (del) {
				todel.push_back(i);
				left[i] = false;
			}
		}

		for(auto i : todel){
			tocheck.insert(L[i]);
			tocheck.insert(R[i]);
			R[L[i]] = R[i];
			L[R[i]] = L[i];
		}

		if (tocheck.empty()){
			rep(i,0,n){
				if (left[i]) ans.back().push_back(i);
			}
			// ans.back().assign(all(left));
			break;
		} else {
			ans.back().assign(all(todel));
		}
	}
	cout << sz(ans)-1 << endl;
	rep(i,0,sz(ans)){
		for(auto a : ans[i]){
			cout << val[a] << " ";
		}
		cout << endl;
	}
}
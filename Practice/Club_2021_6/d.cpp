#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e6+7;

int lp[MAXN] = {0};
vi pr;
int maxdiv = 0;
int seen[MAXN] = {0};
int curr = 0;

void getprimes(){
	for(int i=2; i<MAXN; ++i){
		if (lp[i]==0){
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<MAXN; ++j){
			lp[i*pr[j]] = pr[j];
		}
	}
}

void checkdivs(vector<pair<int, int>> &p_facs, int i, int n){
	// cout << i << ' ' << n << endl;
	if (i>=p_facs.size()){
		return;
	}
	rep(j,0,p_facs[i].second){
		n *= p_facs[i].first;
		if (n>maxdiv && seen[n] && seen[n]<curr) maxdiv = n;
		seen[n] = curr;
		if (i!=p_facs.size()-1)
			checkdivs(p_facs, i+1, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	getprimes();
	int n;
	cin >> n;
	rep(i,0,n){
		curr = i+1;
		int f;
		cin >> f;
		if (f==1) continue
		vector<pair<int, int>> p_facs(0);
		while(true){
			if (p_facs.size() && p_facs.back().first==lp[f]){
				p_facs.back().second++;
			}else{
				p_facs.push_back({lp[f], 1});
			}
			f /= lp[f];
			if (f==1) break;
		}
		// cout << "HI" << endl;
		rep(j,0,sz(p_facs)){
			// printf("%d: %d\n", p_facs[j].first, p_facs[j].second);
			checkdivs(p_facs, j, 1);
		}
	}
	if (maxdiv < 1) maxdiv = 1;
	cout << maxdiv << endl;
}
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#define max(a,b) ((a>b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int MAXN = 1e5;

vpii G[MAXN+1];

priority_queue <int, vector<int>, greater<int> > Q;

int DSU[1001] = {0};

int find(int v){
	return ( (v==DSU[v])? v : DSU[v] = find(DSU[v]) );
}

int main(){
	int n, m; // num nodes and num threads
	cin >> n >> m;

	int t1, t2;

	swap(t1, t2);

	// sort(all(v));

	vector<pii> E;
	vector<int> res(m);
	for(int i=0; i<m; ++i){
		cin >> t1 >> t2;
		E.push_back({t1,t2});
	}

	res[m-1] = n;
	for(int i=m-1; i>0; --i){
		int a = E[i].first;
		int b = E[i].second;
		a = find(a);
		b = find(b);
		if (a!=b){
			DSU[a] = b;
			res[i-1] = res[i]-1;
		}else{
			res[i-1] = res[i];
		}
	}
	for(int i=0; i<m; ++i){
		cout << res[i] << endl;
	}

	// G[a].push_back({b, w_a_b});

}
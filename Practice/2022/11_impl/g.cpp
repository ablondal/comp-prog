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

char grid[9][9] = {{0}};
int corners[9][9] = {{0}};
int nleft[9][9] = {{0}};
int n;

vector<pair<int, int>> UF_stack;

inline int ind(int i, int j){
	return i*9+j;
}

int UF[100];
int find(int i){
	return (UF[i] < 0) ? i : find(UF[i]);
}
void merge(int i, int j){
	i = find(i);
	j = find(j);
	if (i == j) {
		UF_stack.push_back({-1, -1});
	} else {
		if (UF[j] < UF[i]){
			swap(i,j);
		}
		UF_stack.push_back({j, UF[j]});
		UF[i] += UF[j];
		UF[j] = i;
	}
}
void unmerge(){
	auto p = UF_stack.back();
	UF_stack.pop_back();
	if (p.first == -1) {
		return;
	}
	UF[UF[p.first]] -= p.second;
	UF[p.first] = p.second;
}

inline bool isgood(int i, int j){
	return (
		corners[i][j] <= nleft[i][j] &&
		corners[i][j+1] <= nleft[i][j+1] &&
		corners[i+1][j] <= nleft[i+1][j] &&
		corners[i+1][j+1] <= nleft[i+1][j+1]
	);
}

bool dfs(int i, int j){
	if (i == n) {
		return 1;
	}
	if (find(ind(i, j)) != find(ind(i+1, j+1)) && corners[i][j] != 0 && corners[i+1][j+1] != 0) {
		corners[i][j]--;
		corners[i+1][j+1]--;
		nleft[i][j]--; nleft[i+1][j]--; nleft[i][j+1]--; nleft[i+1][j+1]--;
		if (isgood(i, j)) {
			merge(ind(i,j), ind(i+1,j+1));
			grid[i][j] = '\\';
			if (dfs(i+(j==n-1), (j+1)%n)) return 1;
			unmerge();
		}
		nleft[i][j]++; nleft[i+1][j]++; nleft[i][j+1]++; nleft[i+1][j+1]++;
		corners[i][j]++;
		corners[i+1][j+1]++;
	}
	if (find(ind(i+1, j)) != find(ind(i, j+1)) && corners[i+1][j] != 0 && corners[i][j+1] != 0) {
		corners[i+1][j]--;
		corners[i][j+1]--;
		nleft[i][j]--; nleft[i+1][j]--; nleft[i][j+1]--; nleft[i+1][j+1]--;
		if (isgood(i, j)) {
			merge(ind(i+1,j), ind(i,j+1));
			grid[i][j] = '/';
			if (dfs(i+(j==n-1), (j+1)%n)) return 1;
			unmerge();
		}
		nleft[i][j]++; nleft[i+1][j]++; nleft[i][j+1]++; nleft[i+1][j+1]++;
		corners[i+1][j]++;
		corners[i][j+1]++;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i,0,100) UF[i] = -1;
	rep(i,0,n+1) rep(j,0,n+1){
		char a;
		cin >> a;
		if (a == '+') corners[i][j] = -1;
		else corners[i][j] = a-'0';
		nleft[i][j] = 1 + (i != 0 && i != n) + (j != 0 && j != n) + (i != 0 && i != n && j != 0 && j != n);
	}
	bool r = dfs(0, 0);
	rep(i,0,n){
		rep(j,0,n){
			cout << grid[i][j];
		}
		cout << endl;
	}

}
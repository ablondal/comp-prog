#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	long long n;
	int m;
	cin >> n >> m;
	vector<bool> direction(m + 1);
	vector<long long> balls(m + 1, 0);
	vector<int> inDegree(m + 1, 0);
	balls[1] = n;
	vector<vector<int>> out(m + 1);
	for(int i = 1; i <= m; i++){
		string val;
		int u, v;
		cin >> val >> u >> v;
		direction[i] = val == "L";
		inDegree[u]++;
		inDegree[v]++;
		out[i].push_back(u);
		out[i].push_back(v);
	}
	// stack<int> cur, next;
	queue<int> Q;

	for(int i = 1; i <= m; i++){
		if(inDegree[i] == 0){
			// cur.push(i);
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int top = Q.front();
		Q.pop();
		if(top == 0){
			continue;
		}
		int left = out[top][0];
		int right = out[top][1];
		balls[left] += balls[top] / 2;
		balls[right] += balls[top] / 2;
		if(balls[top] % 2 == 1){
			if(direction[top]){
				balls[left]++;
			}else{
				balls[right]++;
			}
			direction[top] = !direction[top];
		}
		inDegree[left]--;
		if(inDegree[left] == 0){
			Q.push(left);
		}
		inDegree[right]--;
		if(inDegree[right] == 0){
			Q.push(right);
		}
	}
	for(int i = 1; i <= m; i++){
		if(direction[i]){
			cout << "L";
		}else{
			cout << "R";
		}
	}
	cout << endl;
}
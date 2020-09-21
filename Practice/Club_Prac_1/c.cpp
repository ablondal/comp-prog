#include <queue>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pt;
typedef pair<int, pt> pipt;
vector <pt> G[101];
int items[101];
int V[101] = {0};
int it[101] = {0};

priority_queue <pipt, vector<pipt>, greater<pipt> > PQ; // dist, -items, node

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> items[i];
	}
	int m;
	cin >> m;
	for(int i=0; i<m; ++i){
		int a, b, d;
		cin >> a >> b >> d;
		G[a].push_back({b,d});
		G[b].push_back({a,d});
	}
	PQ.push({0, {-1*items[1], 1}});
	while(!PQ.empty()){
		pair<int, pt> T = PQ.top();
		PQ.pop();
		int N = T.second.second;
		int it = -1*T.second.first;
		int dist = T.first;
		// cout << dist << " " << it << " " << N << endl;
		if (N==n){
			cout << dist << " " << it << endl;
			return 0;
		}
		if (V[N] && V[N]<dist) continue;
		if (items[N]>it) continue;
		V[N] = dist;
		items[N] = it;

		for(auto B: G[N]){
			if (!V[B.first])
				PQ.push({dist+B.second, { -it-items[B.first], B.first } });
		}
	}
	if (V[n]){
		cout << V[n] << " " << items[n] << endl;
	}else{
		cout << "impossible" << endl;
	}
}











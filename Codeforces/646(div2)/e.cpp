#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define fori(i, n) for(int i=0; i<n; ++i)
#define min(a,b) ((a<b)?a:b)
const int N = 200007;
typedef long long ll;
vector <int> T[N];

typedef struct{
	int n0s;
	int n1s;
	ll cost;
} t_node;

t_node nodes[N];

ll DFS(int V, int P, ll m_cost){
	m_cost = min(m_cost,nodes[V].cost);
	ll sum = 0;
	for(int C : T[V]){
		if(C!=P){
			sum += DFS(C, V, m_cost);
			nodes[V].n0s+=nodes[C].n0s;
			nodes[V].n1s+=nodes[C].n1s;	
		}
		
	}
	ll m = min(nodes[V].n0s, nodes[V].n1s);
	sum += m*2*m_cost;
	nodes[V].n0s -= m;
	nodes[V].n1s -= m;
	// cout << V << " " << sum << " " << nodes[V].n0s << ' ' << nodes[V].n1s << endl;
	return sum;
}

int main(){
	int n;
	cin >> n;
	int s, t;
	for(int i=1; i<=n; ++i){
		cin >> nodes[i].cost >> s >> t;
		nodes[i].n0s=nodes[i].n1s=0;
		if (s==0 && t==1){
			nodes[i].n0s=1;
		}else if(s==1 && t==0){
			nodes[i].n1s=1;
		}
	}
	int u, v;
	for(int i=0; i<n-1; ++i){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	ll sum = DFS(1, 0, 2e9);
	if (nodes[1].n0s != 0 || nodes[1].n1s != 0){
		cout << "-1" << endl;
	}else{
		cout << sum << endl;
	}
}
















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

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Ga, Gb, a, b, c;
	cin >> N >> Ga >> Gb >> a >> b >> c;
	vi a_group_id(N), b_group_id(N);
	rep(i,0,Ga){
		int group_size;
		cin >> group_size;
		rep(j,0,group_size){
			int student;
			cin >> student;
			a_group_id[student-1] = i; // Student is in group i for photographer A
		}
	}
	rep(i,0,Gb){
		int group_size;
		cin >> group_size;
		rep(j,0,group_size){
			int student;
			cin >> student;
			b_group_id[student-1] = i; // Student is in group i for photographer B
		}
	}

	// Build the graph!
	// Nodes are S = 0
	// G_ai nodes for each of photographer A's groups from 1 to Ga
	// G_bi nodes for each of photographer B's groups from Ga+1 to Ga+Gb
	// T = Ga+Gb+1
	PushRelabel graph(Ga+Gb+2);

	rep(i,1,Ga+1){
		graph.addEdge(0, i, a); // Edges from S to Gai with cap a
	}
	rep(i,Ga+1,Ga+Gb+1){
		graph.addEdge(i, Ga+Gb+1, b); // Edges from Gbi to T with cap b
	}
	rep(i,0,N){
		graph.addEdge(1+a_group_id[i],1+Ga+b_group_id[i],c);
		// Edge between the two groups for every student, with cap c
	}

	cout << graph.calc(0, Ga+Gb+1) << endl;
}
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef struct {
	int t;
	int o;
	int d;
} ins;

typedef struct {
	int s, i, t, o, d;
} inp;

unordered_map<int, int> state;

ins in[100][2];

vector<inp> vip; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int n_states;
	cin >> n_states;
	rep(j,0,n_states*2){
		int s,i,t,o,d;
		cin >> s >> i >> t >> o >> d;
		in[s][i].t = t;
		in[s][i].o = o;
		in[s][i].d = d;
	}
	int tape, state, head;
	bool halts = true;
	rep(M,0,(1<<20)){
		tape = M;
		state = 0;
		head = 0;
		int L = t;
		while(L){
			if (state==-1) break;
			int t,o,d;
			int i = (tape & (1<<head)) ? 1 : 0;
			t = in[state][i].t;
			o = in[state][i].o;
			d = in[state][i].d;
			if (o==0) tape = tape & (~(1<<head));
			if (o==1) tape = tape | (1<<head);
			head = head + (d?1:-1);
			head = max(head,0);
			state = t;
			L--;
		}
		if (state!=-1) halts = false;
	}
	if (halts){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
}
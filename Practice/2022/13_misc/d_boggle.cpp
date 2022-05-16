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

struct node{
	node* nxt[26] = {0};
	int num = 0;
	int cnum = 0;
	int leaf = 0;
	bool found = 0;
};

int scoring[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
vector<node*> nds;
vector<string> STS;

void add_word(node* root, string s, int e){
	node* curr = root;
	for(int i=0; i<sz(s); ++i){
		curr->num++;
		curr->cnum++;
		if (curr->nxt[s[i]-'A']){
			curr = curr->nxt[s[i]-'A'];
		} else {
			nds.push_back(new node);
			curr->nxt[s[i]-'A'] = nds.back();
			curr = nds.back();
		}
	}
	if (!curr->leaf){
		curr->num++;
		curr->cnum++;
		curr->leaf = e;
	}
}

bool vv[4][4] = {{0}};
char G[4][4];
int c_score = 0;
string l_word;
int dd[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int score(int x, int y, int dep, node* curr){
	if (curr->cnum <= 0) return 0;
	vv[x][y] = true;
	int tot = 0;
	if (curr->leaf && !curr->found){
		// cout << STS[curr->leaf] << endl;
		tot++;
		c_score += scoring[dep];
		if (dep > sz(l_word) || (dep == sz(l_word) && STS[curr->leaf] < l_word) ){
			l_word = STS[curr->leaf];
		}
		curr->found = true;
	}
	for(auto [dx, dy] : dd){
		if (x+dx < 0 || x+dx > 3 || y+dy < 0 || y+dy > 3 || vv[x+dx][y+dy]) continue;
		auto ptnxt = curr->nxt[G[x+dx][y+dy] - 'A'];
		if (ptnxt == nullptr) continue;
		tot += score(x+dx, y+dy, dep+1, ptnxt);
	}
	curr->cnum -= tot;
	vv[x][y] = false;
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	node* root = new node;
	nds.push_back(root);
	STS.push_back("a");
	while(t--){
		string s;
		cin >> s;
		STS.push_back(s);
		add_word(root, s, sz(STS)-1);
	}
	int n;
	cin >> n;
	rep(i,0,n){
		for(auto &a : nds){
			a->cnum = a->num;
			a->found = 0;
		}
		c_score = 0;
		l_word = "";
		int tot = 0;
		rep(j,0,4){
			string b;
			cin >> b;
			rep(k,0,4){
				G[j][k] = b[k];
			}
		}
		rep(j,0,4){
			rep(k,0,4){
				if (root->nxt[G[j][k]-'A'])
					tot += score(j, k, 1, root->nxt[G[j][k]-'A']);
			}
		}
		cout << c_score << " " << l_word << " " << tot << endl;

	}
}
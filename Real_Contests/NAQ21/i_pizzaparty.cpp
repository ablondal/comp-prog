#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, int> M;
int Mi = 0;
int ind(string s){
	auto it = M.find(s);
	if (it == M.end()){
		M[s] = Mi;
		return Mi++;
	}
	return it->second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> curr_ing;
	vector<pair<set<int>, int>> ands;
	vector<pair<set<int>, int>> ors;
	rep(line, 0, n){
		int cond = 0;
		set<int> b4;
		int af = -1;
		do{
			string a;
			cin >> a;
			if (a == "if") {
				cond = 1;
			} else if (a == "or") {
				cond = 1;
			} else if (a == "and") {
				cond = 2;
			} else if (a == "then") {
				cin >> a;
				af = ind(a);
				break;
			} else {
				b4.insert(ind(a));
			}
		}while((cin.peek() != EOF && cin.peek() != '\n'));
		if (cond == 0){
			curr_ing.insert(*b4.begin());
		} else if (cond == 1){
			ors.push_back({b4,af});
		} else {
			ands.push_back({b4,af});
		}
	}
	bool go = true;
	// cout << "hi" << endl;
	while(go){
		go = false;
		for(int i = ors.size()-1; i>=0; --i){
			// cout << ors[i].second << endl;
			if (curr_ing.count(ors[i].second)){
				ors.erase(ors.begin()+i);
				continue;
			}
			// cout << ors[i].second << endl;

			vector<int> v(500);
			auto it = set_intersection(all(ors[i].first), all(curr_ing), v.begin());
			// cout << it - v.begin() << endl;
			if (it != v.begin()) {
				curr_ing.insert(ors[i].second);
				ors.erase(ors.begin()+i);
				go = true;
			}
		}
		for(int i = ands.size()-1; i>=0; --i){
			if (curr_ing.count(ands[i].second)){
				ands.erase(ands.begin()+i);
				continue;
			}
			// cout << ands[i].second << endl;
			vector<int> v(500);
			auto it = set_intersection(all(ands[i].first), all(curr_ing), v.begin());
			if (it-v.begin() == sz(ands[i].first)) {
				curr_ing.insert(ands[i].second);
				ands.erase(ands.begin()+i);
				go = true;
			}
		}
	}
	cout << sz(curr_ing) << endl;
}
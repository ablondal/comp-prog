#include "../utilities/template.h"

#include "../../content/strings/SuffixAutomaton.h"

void print_sa(SuffixAutomaton &sa){
	rep(i,0,sa.ni){
		cout << i << ":";
		for(auto [c, e]:sa.nx[i]){
			cout << " (" << c << "," << e << ")";
		}
		cout << endl;
		// cout << "ct: " << sa.ct[i] << endl;
		cout << "link: " << sa.link[i] << endl;
	}
}

bool test(string s){
	SuffixAutomaton sa(s);
	rep(i,0,sz(s)){
		rep(j,i+1,sz(s)){
			string b = s.substr(i, j-i);
			int ct = 0;
			int pos = 0;
			while((pos = s.find(b, pos)) != string::npos){
				ct++; pos++;
			}
			int cur = 0;
			for(auto c : b){
				if (!sa.nx[cur].count(c)){
					cout << "no word " << b << endl;
					return false;
				}
				cur = sa.nx[cur][c];
			}
			if (ct != sa.ct[cur]){
				cout << "count wrong for " << b << endl;
				cout << "should be " << ct << " and was " << sa.ct[cur] << endl;
				cout << sa.link[cur] << " " << sa.len[cur] << endl;
				rep(k,0,sa.ni) if (sa.link[k] == cur) cout << k << " " << sa.len[k] << endl;
				print_sa(sa);
				return false;
			}
		}
	}
	return true;
}

bool stress(int a){
	int ll = 100;
	rep(i,0,100){
		string s = "fdwdwf";
		rep(j,0,ll){
			s.push_back('a'+(rand()%26));
		}
		if (!test(s)) {
			cout << "failed on " << s << endl;
			return 0;
		} else {
			cout << "ok" << endl;
		}
	}
	return 1;
}

int main() {
	if (stress(0))
		cout<<"Tests passed!"<<endl;
	// perf();
	// perf2();
}

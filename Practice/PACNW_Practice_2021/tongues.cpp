#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char d[256];

char vow[] = {'a', 'i', 'y', 'e', 'o', 'u'};

char cons[] = {'b', 'k', 'x', 'z','n','h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	rep(i,0,6){
        d[vow[i]] = vow[(i+3)%6];
        d[vow[i]-'a'+'A'] = vow[(i+3)%6]+'A'-'a';
    }
    rep(i,0,20){
        d[cons[i]] = cons[(i+10)%20];
        d[cons[i]+'A'-'a'] = d[cons[i]]+'A'-'a';
    }
    string s;
    while( getline(cin, s) ){
        // string ss(s);
        for(auto& c : s){
            if ( ('a'<=c && c<='z') || ('A'<=c && c<='Z') ){
                c = d[c];
            }
        }
        cout << s << endl;
    }
}
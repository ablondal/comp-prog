#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll state = 0;
		rep(i,0,sz(s)){
			state *= 8;
			state += (s[i]-'0');
		}
		vector<int> board(9, 0);
		int ct = 0;
		rep(i,0,9){
			board[i] += (state & 1);
			ct += (state & 1);
			state >>= 1;
		}
		rep(i,0,9){
			board[i] += (state & board[i]);
			state >>= 1;
		}
		int win = 0;
		rep(i,0,3){
			int m1 = 3;
			rep(j,0,3){
				m1 &= board[3*i+j];
			}
			int m2 = 3;
			rep(j,0,3){
				m2 &= board[3*j+i];
			}
			if ((m1 | m2) == 1){
				win = 1;
			} else if ((m1 | m2) == 2){
				win = 2;
			}
		}
		int m1 = 3, m2 = 3;
		rep(i,0,3){
			m1 &= board[3*i+i];
			m2 &= board[3*i + (2-i)];
		}
		if ((m1 | m2) == 1){
			win = 1;
		} else if ((m1 | m2) == 2){
			win = 2;
		}

		if (win == 1){
			cout << "O wins" << endl;
		} else if (win == 2){
			cout << "X wins" << endl;
		} else if (ct == 9){
			cout << "Cat's" << endl;
		} else {
			cout << "In progress" << endl;
		}
	}
}
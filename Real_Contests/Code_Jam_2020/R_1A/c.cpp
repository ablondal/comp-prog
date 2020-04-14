#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE, a nice implementation using pointers for whatever awful reason

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair<int, int> pii;
int H,W;

struct dancer{
	dancer *U,*D,*L,*R;
	int S; // skill
	int N; // Neighbour tot skill
	bool ded;
};


ll solve(){
	cin >> H >> W;

	//vector <vector <dancer> > C(W,vector<dancer>(H));
	dancer C[W][H];

	set <dancer*> to_test;
	vector <dancer*> to_del;

	ll curr_int = 0;

	// cout << 1 << endl;
	for(int y=0; y<H; ++y){
		for(int x=0; x<W; ++x){
			to_test.insert(&C[x][y]);
			C[x][y].L = C[x][y].R = C[x][y].U = C[x][y].D = NULL;

			if(x!=0) C[x][y].L = &C[x-1][y];

			if(x!=W-1) C[x][y].R = &C[x+1][y];

			if(y!=0) C[x][y].U = &C[x][y-1];

			if(y!=H-1) C[x][y].D = &C[x][y+1];

			cin >> C[x][y].S;
			curr_int += C[x][y].S;

			C[x][y].N = 0;
			C[x][y].ded = false;
		}
	}
	// cout << 2 << endl;
	ll tot_int = 0;
	int n_rd = 0;

	while(true){
		n_rd++;
		// cout << "Round " << n_rd << ": " << to_test.size() << " elements to test" << endl;
		tot_int += curr_int;

		to_del.clear();

		for(auto c: to_test){
			if (c->ded) continue;
			//c->N = 0;
			int n = 0;
			int N = 0;
			if (c->U){
				//if (c->U->S==0) cout << "uh oh" << endl;
				N += c->U->S;
				n++;
			}
			if (c->D){
				N += c->D->S;
				n++;
			}
			if (c->L){
				N += c->L->S;
				n++;
			}
			if (c->R){
				N += c->R->S;
				n++;
			}
			if ( N > n * (c->S) ){
				to_del.push_back(c);
			}
		}

		to_test.clear();
		// cout << "totest size: " << to_test.size() << endl;

		if (to_del.empty()){
			//cout << "exiting this way" << endl;
			break;
		}

		for(auto c: to_del){
			//if (c->ded){cout << "Already dead :/" << endl;}
			c->ded = true;
			curr_int -= c->S;
			c->S = 0;
			if (c->U){
				c->U->D = c->D;
				to_test.insert(c->U);
			}
			if (c->D){
				c->D->U = c->U;
				to_test.insert(c->D);
			}
			if (c->R){
				c->R->L = c->L;
				to_test.insert(c->R);
			}
			if (c->L){
				c->L->R = c->R;
				to_test.insert(c->L);
			}

		}
		
	}
	return tot_int;

}


int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;++t){
		ll a = solve();
		cout << "Case #" << t << ": " << a << endl;
		// solve();
	}
	return 0;
}




















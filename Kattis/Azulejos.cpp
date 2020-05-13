#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef pair<int, int> pii;

// DONE, finally

typedef struct _tile{
	int p, h, i;
}tile;
typedef vector<tile> vt;
typedef vector<int> vi;
typedef set<tile> st;

bool operator<(tile a, tile b){
	if (a.p!=b.p) return a.p < b.p;
	if (a.h!=b.h) return a.h > b.h;
	return a.i < b.i;
}

bool solve(int n, vt &F, vt &B, vi &ff, vi &bb){
	st Fset, Bset;
	int Fp=0, Bp=0;
	tile Ftile, Btile;
	st::iterator it;
	for(int i=0; i<n; ++i){
		if (Fset.empty()){
			Fp = F[i].p;
			for(int j=i; j<n && F[j].p == Fp; ++j){
				Fset.insert(F[j]);
			}
		}
		if (Bset.empty()){
			Bp = B[i].p;
			for(int j=i; j<n && B[j].p == Bp; ++j){
				Bset.insert(B[j]);
			}
		}
		if (Fset.size()<=Bset.size()){
			Ftile = *( --Fset.end() );
			Fset.erase( --Fset.end() );
			ff[i] = Ftile.i;

			Ftile.p = Bp;
			Ftile.i = 0;
			it = Bset.lower_bound( Ftile );
			if (it!=Bset.begin()){
				it--;
				bb[i] = it->i;
				Bset.erase(it);
			}else{
				return 0;
			}
		}else{
			Btile = *( Bset.begin() );
			Bset.erase( Bset.begin() );
			bb[i] = Btile.i;

			Btile.p = Fp;
			Btile.i = n+1;
			it = Fset.upper_bound( Btile );
			if (it!=Bset.end()){
				ff[i] = it->i;
				Fset.erase(it);
			}else{
				return 0;
			}
		}
		// cout << Btile.h << " " << Ftile.h << " " << Btile.i << " " << Btile.i << endl;
		
	}
	// assert(Fset.empty());
	// assert(Bset.empty());
	return 1;
}

int main(){
	vector <tile> F,B;
	int n;
	cin >> n;
	F.resize(n);
	B.resize(n);
	for( int i=0; i<n; ++i){
		cin >> B[i].p;
		B[i].i = i+1;
	}
	for( int i=0; i<n; ++i){
		cin >> B[i].h;
	}
	for( int i=0; i<n; ++i){
		cin >> F[i].p;
		F[i].i = i+1;
	}
	for( int i=0; i<n; ++i){
		cin >> F[i].h;
	}

	sort(F.begin(),F.end());
	sort(B.begin(),B.end());

	// for(auto f: F){
	// 	cout << f.i << endl;
	// }

	
	vector <int> ff(n), bb(n);
	if (!solve(n,F,B,ff,bb)){
		cout << "impossible" << endl;
		return 0;
	}

	for(int i=0; i<n; ++i){
		cout << bb[i];
		if (i!=n-1) cout << " ";
	}
	cout << endl;
	for(int i=0; i<n; ++i){
		cout << ff[i];
		if (i!=n-1) cout << " ";
	}
	cout << endl;

}















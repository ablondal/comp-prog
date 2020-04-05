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
typedef vector<int> vi;
typedef vector<vi> vvi;

// DONE

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		int n, trace=0, r=0, c=0;
		cin >> n;
		vvi M(n,vi(n));
		//cout << M.size() << " " << M[0].size() << endl;
		vi N;
		for(int y=0; y<n; ++y){
			for(int x=0; x<n; ++x){
				cin >> M[x][y];
				if(x==y){
					trace += M[x][y];
				}
			}
		}
		for(int y=0; y<n; ++y){
			N.clear();
			N.resize(n+1,0);
			bool hasrep = false;
			for(int x=0; x<n; ++x){
				N[M[x][y]]++;
				if (N[M[x][y]]>1){
					hasrep=true;
					break;
				}
			}
			if(hasrep){
				r++;
			}
		}
		for(int x=0; x<n; ++x){
			N.clear();
			N.resize(n+1,0);
			bool hasrep = false;
			for(int y=0; y<n; ++y){
				N[M[x][y]]++;
				if (N[M[x][y]]>1){
					hasrep=true;
					break;
				}
			}
			if(hasrep){
				c++;
			}
		}
		cout << "Case #" << t << ": " << trace << " " << r << " " << c << endl;
	}
}
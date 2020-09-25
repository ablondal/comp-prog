#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[81][81];

char word[81];
int wl;

int main() {
	scanf(" %s", word);
	wl=0;
	while(word[wl]) wl++;
	while(word[0]!='*'){
		rep(i,0,wl){
			DP[i][i+1] = 1;
			rep(j,i+2,wl+1) DP[i][j] = 1000;
		}
		rep(siz,2,wl+1){
			vector<int> facs;
			rep(i, 1, siz){
				if (siz % i == 0) facs.push_back(i);
			}
			// for(auto f: facs) printf("%d ", f);
			// 	printf("\n");
			rep(i, 0, wl-siz+1){
				rep(j, i+1, i+siz){
					DP[i][i+siz] = min(
						DP[i][i+siz], DP[i][j]+DP[j][i+siz]);
				}
				for(auto f:facs){
					bool works = true;
					for(int nf = 1; nf < (siz/f); ++nf){
						for(int p=0; p<f; ++p){
							if (word[i+p] != word[i+p + nf*f]){
								works = false;
								break;
							}
						}
					}
					if (works) DP[i][i+siz] = min(
						DP[i][i+siz], DP[i][i+f]);
				}
				// printf("%d %d: %d\n", i, i+siz, DP[i][i+siz]);
			}
		}
		printf("%d\n", DP[0][wl]);

		scanf(" %s", word);
		wl=0;
		while(word[wl]) wl++;
	}
}












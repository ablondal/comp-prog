#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll p = 101;
const ll p2 = 31;
const ll p3 = 37;
const ll M = 1e9+9;

int N;
char P[151][71];
int szP[151];
char S[(int)1e6+7];
ll pn[(int)1e6+7];
ll pn2[(int)1e6+7];
ll pn3[(int)1e6+7];
ll h[(int)1e6+7];
ll h2[(int)1e6+7];
ll h3[(int)1e6+7];

int main(){
	scanf("%d", &N);
	pn[0] = 1;
	for(int i=0; i<1e6+7; ++i){
		pn[i+1] = (pn[i]*p) % M;
	}
	pn2[0] = 1;
	for(int i=0; i<1e6+7; ++i){
		pn2[i+1] = (pn2[i]*p2) % M;
	}
	pn3[0] = 1;
	for(int i=0; i<1e6+7; ++i){
		pn3[i+1] = (pn3[i]*p3) % M;
	}
	while(N){
		vector<ll> PHash(N, 0);
		vector<ll> PHash2(N, 0);
		vector<ll> PHash3(N, 0);
		vector<int> num(N, 0);
		rep(i,0,N){
			scanf("%s", P[i]);
			rep(j,0,72){
				if (P[i][j]==0){
					szP[i] = j;
					break;
				}
				PHash[i] = (PHash[i] + (P[i][j]-'a'+1)*pn[j]) % M;
				PHash2[i] = (PHash2[i] + (P[i][j]-'a'+1)*pn2[j]) % M;
				PHash3[i] = (PHash3[i] + (P[i][j]-'a'+1)*pn3[j]) % M;
			}
		}
		scanf("%s", S);
		// printf("%s\n", S);
		int szS = 0;
		h[0] = 0;
		h2[0] = 0;
		h3[0] = 0;
		for(szS = 0; S[szS]; ++szS){
			h[szS+1] = (h[szS] + (S[szS]-'a'+1)*pn[szS] ) % M;
			h2[szS+1] = (h2[szS] + (S[szS]-'a'+1)*pn2[szS] ) % M;
			h3[szS+1] = (h3[szS] + (S[szS]-'a'+1)*pn3[szS] ) % M;
		}
		rep(i,0,N){
			rep(j,0,szS-szP[i]+1){
				ll cur_h = (h[j+szP[i]] + M - h[j]) % M;
				ll cur_h2 = (h2[j+szP[i]] + M - h2[j]) % M;
				ll cur_h3 = (h3[j+szP[i]] + M - h3[j]) % M;
				if (
					cur_h == PHash[i] * pn[j] % M &&
					cur_h2 == PHash2[i] * pn2[j] % M &&
					cur_h3 == PHash3[i] * pn3[j] % M
					) num[i]++;
			}	
		}
		int ms = 0;
		rep(i,0,N){
			ms = max(ms, num[i]);
		}
		printf("%d\n", ms);
		rep(i,0,N){
			if (ms==num[i]) printf("%s\n", P[i]);
		}
		scanf("%d", &N);
	}

}





















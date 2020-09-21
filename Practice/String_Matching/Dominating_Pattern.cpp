#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll p1 = 37;
const ll M = 54873000000000011;
const ll p2 = 29;
const ll p3 = 101;

int N;
char P[151][71];
int szP[141];
char S[(int)1e6+7];
ll pn1[75];
ll pn2[75];
ll pn3[75];

int main(){
	scanf(" %d", &N);
	pn1[0] = 1;
	for(int i=0; i<72; ++i){
		pn1[i+1] = (pn1[i]*p1) % M;
	}
	pn2[0] = 1;
	for(int i=0; i<72; ++i){
		pn2[i+1] = (pn2[i]*p2) % M;
	}
	pn3[0] = 1;
	for(int i=0; i<72; ++i){
		pn3[i+1] = (pn3[i]*p3) % M;
	}
	while(N){
		vector<ll> PHash1(N, 0);
		vector<ll> PHash2(N, 0);
		vector<ll> PHash3(N, 0);
		vector<int> num(N, 0);
		vector<ll> CHash(72, 0);
		rep(i,0,N){
			scanf(" %s", P[i]);
			rep(j,0,72){
				if (P[i][j]==0){
					szP[i] = j;
					break;
				}
				PHash1[i] = (p1 * PHash1[i] + P[i][j] - 'a') % M;
				// PHash2[i] = (p2 * PHash2[i] + P[i][j] - 'a') % M;
				// PHash3[i] = (p3 * PHash3[i] + P[i][j] - 'a') % M;
			}
		}
		ll C1, C2, C3;
		scanf(" %s", S);

		int szS = 0;
		for(;S[szS];szS++);
		rep(i,0,N){
			int sP = szP[i];
			if (sP > szS) continue;
			C1 = C2 = C3 = 0;
			rep(j,0,sP){
				C1 = (p1*C1) + S[j]-'a';
				C1 %= M;
				// C2 = (p2*C2) + S[j]-'a';
				// C2 %= M;
				// C3 = (p3*C3) + S[j]-'a';
				// C3 %= M;
			}
			rep(j, sP, szS){
				// printf("%lli %lli\n", C, PHash[i]);
				if (C1 == PHash1[i]) num[i]++;
				C1 += M - ((pn1[sP-1] * (S[j-sP]-'a')) % M);
				C1 %= M;
				C1 *= p1;
				C1 += S[j]-'a';
				C1 %= M;
				// C2 += M - ((pn2[sP-1] * (S[j-sP]-'a')) % M);
				// C2 %= M;
				// C2 *= p2;
				// C2 += S[j]-'a';
				// C2 %= M;
				// C3 += M - ((pn3[sP-1] * (S[j-sP]-'a')) % M);
				// C3 %= M;
				// C3 *= p3;
				// C3 += S[j]-'a';
				// C3 %= M;
			}
			if (C1 == PHash1[i]) num[i]++;
		}
		int ms = 0;
		rep(i,0,N){
			ms = max(ms, num[i]);
		}
		printf("%d\n", ms);
		rep(i,0,N){
			if (ms==num[i]) printf("%s\n", P[i]);
		}
		scanf(" %d", &N);
	}

}





















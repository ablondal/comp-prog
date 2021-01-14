#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char V[1207] = {0};

int main() {
	while(true){
		int N;
		cin >> N;
		if(N<1) break;
		N *= 2;

		vector<ll> pk(N);
		rep(i,0,N) cin >> pk[i];
		sort(all(pk));
		ll sm = -1;
		
		rep(j,1,N){
			memset(V,0,1207);
			ll g = pk[j]-pk[0];
			// if(g==0)continue;
			int i2 = j;
			int i = 0;
			int m = 0;
			while(m<N/2){
				while(V[i]) i++;
				i2 = max(i2, i+1);
				while(i2<N && pk[i2]<pk[i]+g){
					i2++;
				}
				if(i2<N && pk[i2]-pk[i]==g){
					V[i2]=V[i]=true;
					m++;
					i2++;
					i++;
				}else{
					m = 700;
				}
			}
			if(m==N/2){
				sm = g;
				break;
			}

		}

		if (sm > -1){
			printf("%lld\n", sm);
		}else{
			printf("Unreliable Network\n");
		}
	}
}





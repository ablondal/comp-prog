#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll gcd(ll a, ll b){
	if (b==0) return a;
	return gcd(b, a%b);
}

vi factor(ll n){
	vi res;
	for(ll i=2;i*i<n;++i){
		if (n%i==0){
			res.push_back(0);
			while(n%i==0){
				res[sz(res)-1]++;
				n/=i;
			}
		}
	}
	if (n>1){
		res.push_back(1);
	}
	return res;
}

vi factor2(ll n){
	vi res;
	ll i;
	for(i=2;i*i<n;++i){
		if (n%i==0){
			res.push_back(i);
			res.push_back(n/i);
		}
	}
	if (i*i==n) res.push_back(i);
	res.push_back(n);
	return res;
}

vi fs;
int M[(int)2e5];
char V[(int)2e5];
vi res;

bool DFS(int v, int dep){
	// printf("in %lli\n", fs[v]);
	if (dep==0){
		if (gcd(fs[v],fs[0])>1){
			res.push_back(v);
			return true;
		}
		// printf("out %lli\n", fs[v]);
		return false;
	}
	for(int i=0; i<sz(fs); ++i){
		if (v!=i && !V[i] && gcd(fs[v], fs[i])>1){
			V[i] = true;
			if (DFS(i, dep-1)){
				res.push_back(v);
				return true;
			}
			V[i] = false;
		}
	}
	// printf("out %lli\n", fs[v]);
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		scanf("%lli", &n);
		vi f_nums = factor(n);
		fs.clear();
		res.clear();
		fs = factor2(n);
		sort(all(f_nums));
		if (sz(f_nums)==1){
			rep(i,0,sz(fs)){
				if(i!=0)printf(" ");
				printf("%lli",fs[i]);
			}
			printf("\n%d\n", 0);
		}else if (sz(f_nums)==2 && f_nums[0]==1 && f_nums[1]==1){
			rep(i,0,sz(fs)){
				if(i!=0)printf(" ");
				printf("%lli",fs[i]);
			}
			printf("\n%d\n", 1);
		}else{
			memset(V,false,sz(fs));
			V[0] = 1;
			if (DFS(0,sz(fs)-1)){
				rep(i,0,sz(res)){
					if(i!=0)printf(" ");
					printf("%lli",fs[res[i]]);
				}
				printf("\n%d\n", 0);
			}else{
				return 1;
			}
		}
	}
}
































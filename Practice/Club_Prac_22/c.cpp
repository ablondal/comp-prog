#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
	ll a, b;
	scanf("%lld%lld", &a,&b);
	while(!(a==0 || b==0)){
		if (a>=2*b){
			a = a % (2*b);
		}else if(b>=2*a){
			b = b % (2*a);
		}else{
			break;
		}
	}
	printf("%lld %lld\n", a,b);
}
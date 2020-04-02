#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
// DONE
typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n,g,b;
		cin >> n >> g >> b;
		if (b<=g){
			cout << n << endl;
			continue;
		}
		ll num_g = (n+1)/2;
		ll num_cycles = num_g/g;
		ll leftover = num_g%g;
		ll ans = num_cycles*(b+g);
		if(leftover > 0)
			ans += leftover;
		else{
			ll n_b = (num_cycles-1)*b;
			if(n_b>=(n/2)){
				ans -= b;
			}else{
				ans -= b;
				ans += (n/2)-(n_b);
			}
		}
		//cout << "cycles:" << num_cycles << endl;
		cout << max(ans,n) << endl;
	}
}
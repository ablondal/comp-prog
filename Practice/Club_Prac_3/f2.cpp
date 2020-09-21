#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define inf 2e9

typedef long long ll;


int main(){
	int n;
	cin >> n;
	vector <ll> a(n+1);
	
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}

	ll sum = 0;
	ll g_odd = -inf;
	ll o_sum = 0;
	ll l_n_odd = -inf;

	for(int i=1; i<=n; ++i){
		if (a[i]%2 == 0){
			if (a[i]>0) sum += a[i];
		} else {
			if (a[i]<0) {
				g_odd = max(g_odd, a[i]);
				l_n_odd = max(l_n_odd, a[i]);
			}else{
				if (a[i] > g_odd) {
					if (g_odd > 0) {
						o_sum += g_odd;
						if (o_sum > g_odd){
							sum += o_sum;
							o_sum = 0;
						}
					}
					g_odd = a[i];
				} else {
					o_sum += a[i];
					if (o_sum > a[i]){
						sum += o_sum;
						o_sum = 0;
					}
				}
			}
		}
	}

	if (o_sum && o_sum + l_n_odd > 0){
		sum += o_sum + l_n_odd;
	}

	sum += g_odd;
	
	cout << sum << endl;
}















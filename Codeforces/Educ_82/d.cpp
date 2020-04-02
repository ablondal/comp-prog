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

int l2(ll a){
	int b = 0;
	while(a!=1){
		a = (a >> 1);
		b++;
	}
	return b;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll tot = 0;
		vector<ll> bx(m);
		ll twopow[64] = {0};
		for(int i=0; i<m; ++i){
			cin >> bx[i];
			tot += bx[i];
			twopow[l2(bx[i])]++;
		}
		if (tot < n){
			cout << -1 << endl;
			continue;
		}
		int b=0;
		int s=0;
		while(n>0){
			if (n & 1){
				if(twopow[b]){
					twopow[b]--;
				}else{
					int c;
					for(c=b+1; twopow[c]==0 && c<64; c++){;}
					if(c==64){
						s=-1;
						break;
					}
					twopow[c]--;
					for(c--; c>=b; c--){
						twopow[c]++;
						s++;
					}
				}
			}
			n = (n>>1);
			twopow[b+1]+= twopow[b]/2;
			b++;
		}
		cout << s << endl;
		
	}

}











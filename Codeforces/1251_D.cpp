#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
typedef long long ll;

// DONE

ll l[200001],r[200001];
ll m;

bool sorter(int a, int b){
	if (r[a]<m && r[b]<m){
		return l[a]<l[b];
	}else if(r[a]<m){
		return true;
	}else if(r[b]<m){
		return false;
	}else{
		return l[a]<l[b];
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n,s;
		cin >> n >> s;
		ll hi,lo;
		vector<int> sorted(n);
		for(int i=0; i<n; ++i){
			sorted[i] = i;
			cin >> l[i] >> r[i];
		}
		hi = s;
		lo = 1;
		while(hi!=lo){
			m = (hi+lo)/2 + 1;
			//cout << m << endl;
			sort(sorted.begin(),sorted.end(),sorter);
			
			// Test simple test cases
			if (l[sorted[n/2]]>m){
				lo = m+1;
				continue;
			}else if(r[sorted[n/2]]<m){
				hi = m-1;
				continue;
			}

			// Add up l for all below, and max(m,l) for all above
			ll left = s;
			for(int i=0; i<n/2; ++i){
				left -= l[sorted[i]];
			}
			for(int i=n/2+1; i<n; ++i){
				left -= max(l[sorted[i]],m);
			}
			if (left >= m){
				lo = m;
			}else{
				hi = m-1;
			}
		}
		cout << lo << endl;
	}
}













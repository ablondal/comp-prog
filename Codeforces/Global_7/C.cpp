#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef vector <int> vi;
typedef long long ll;
typedef vector <ll> vll;

// DONE

int main(){
	ll n, k;
	cin >> n >> k;
	// vi p(n),q(n+1);
	int tmp;
	vi pos;
	for(int i=0; i<n; ++i){
		cin >> tmp;
		if(tmp > n-k) pos.push_back(i);
	}
	ll max = n*(n+1) / 2 - (n-k)*(n-k+1)/2;
	// cout << max << endl;
	
	sort(pos.begin(),pos.end());

	ll tot = 1;
	for(int i=1; i<pos.size(); ++i){
		tot *= (pos[i]-pos[i-1]);
		tot = tot % (ll)998244353;
	}

	cout << max << " " << tot << endl;

}






























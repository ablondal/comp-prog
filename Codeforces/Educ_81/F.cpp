#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MOD 998244353
using namespace std;

// Done

typedef long long ll;

ll gcd(ll a, ll b){
	if(a==0) return b;
	return gcd(b%a, a);
}

ll ext_euc(ll a, ll b, ll &x, ll &y){
	// Return x, y, gcd(a,b) such that
	// xa + yb = gcd(a,b)
	ll tmp;
	ll xr = 0;
	ll yr = 1;
	x = 1;
	y = 0;
	while(a != 0){
		tmp = x;
		x = xr - (b/a)*x;
		xr = tmp;

		tmp = y;
		y = yr - (b/a)*y;
		yr = tmp;

		tmp = a;
		a = b % a;
		b = tmp;
	}
	x = xr;
	y = yr;
	return b;
}

// Based on ext_euc, we now make pow(-1) mod m :D
ll inv_mod(ll a, ll m){
	// Basically, do ext euc but we only care about x value
	ll tmp;
	ll xr = 0;
	ll x = 1;
	ll b = m;
	while(a != 0){
		tmp = x;
		x = xr - (b/a)*x;
		xr = tmp;

		tmp = a;
		a = b % a;
		b = tmp;
	}
	return (xr+m) % m;
}

// Now we need some fun functions like a choose n mod m
ll choose(ll a, ll n, ll m){
	if (a < n) return 0;
	if (a == n) return 1;

	ll top=1, bot=1;
	for(int i=0; i<n; ++i){
		top *= (a-i);
		top %= m;
		bot *= (i+1);
		bot %= m;
	}
	return (top * inv_mod(bot, m)) % m;
}


int main(){
	int n;
	cin >> n;
	vector <ll> Ls(n+1), Rs(n+1);
	map <int, ll> Loc;
	vector <int> in;

	Ls[0] = -1;
	Rs[0] = MOD;
	ll denominator = 1;

	for(int i=n; i>0; --i){
		cin >> Ls[i] >> Rs[i];
		Rs[i]++;
		
		in.push_back(i);
		in.push_back(-1*i);

		denominator *= Rs[i] - Ls[i];
		denominator %= MOD;
	}
	// cout << "denom is " << denominator << endl;
	

	for(int i=1; i<=n; ++i){
		if ( Ls[i] < Ls[i-1] ) Ls[i] = Ls[i-1];
		Loc[i] = Ls[i];
	}
	for(int i=n; i>=1; --i){
		if ( Rs[i] < Rs[i-1] ) Rs[i-1] = Rs[i];
		Loc[-1*i] = Rs[i];
	}

	sort(in.begin(),in.end(), [ &Loc]( int& a, int& b) { return Loc[a]<Loc[b]; } );
	
	//vector <bool> 

	ll range_low = Loc[in[0]];
	ll range_high = Loc[in[0]];

	// for(int i=0; i<2*n; ++i){
	// 	cout << in[i] << ":" << Loc[in[i]] << " ";
	// }
	// cout << endl;

	int low = 0;
	int high = 1;
	int lhigh = 1;
	
	/*ll num_ending_at[in.size()][n+1];
	num_ending_at[0][0] = 1;
	for(int i=1; i<n+1; ++i){
		num_ending_at[0][i] = 0;
	}*/

	vector <ll> end_at(n+2,0);
	end_at[0] = 1;
	vector <ll> cpy(n+2,0);

	int i=0;
	while( i<in.size()-1 && Loc[in[i+1]] == Loc[in[i]] ){
		++i;
		if (in[i]>0) high++;
		else low++;
	}
	++i;
	lhigh = high;
	
	while( i<in.size() ){
		if (in[i]>0) high++;
		else low++;
		while( i<in.size()-1 && Loc[in[i+1]] == Loc[in[i]] ){
			++i;
			if (in[i]>0) high++;
			else low++;
		}
		range_low = range_high;
		range_high = Loc[in[i]];
		// cout << range_low << " " << range_high << endl;
		// cout << low << " " << lhigh << endl;

		for(int j=low; j<=lhigh; ++j){
			for(int k=0; k<=j; ++k){
				cpy[j] += end_at[k]*choose(range_high-range_low+j-k-1, j-k, MOD);
				cpy[j] %= MOD;
			}
		}

		// for(int j=0;j<=n;++j){
		// 	cout << cpy[j] << " ";
		// }
		// cout << endl;

		// New high
		lhigh = high;

		// Copy the new array to the base
		// Empty the old
		for(int l=0;l<=n;++l){
			end_at[l] = cpy[l];
			cpy[l] = 0;
		}
		// Move forwards
		++i;
	}

	/*for(int i=1; i<in.size(); ++i){
		range_low = range_high;
		range_high = Loc[in[i]];
		if ( in[i] > 0 ){
			high++;
		}else{
			low++;
		}
		for(int j=low; j<=high; ++j){
			num_ending_at[i][j] = 0;
			for(int k=0; k<=j; ++k){
				if (num_ending_at[i-1][k])
				{
					num_ending_at[i][j] += 
						num_ending_at[i-1][k] * choose(range_high-range_low+j-k-1, j-k, MOD);
					num_ending_at[i][j] %= MOD;
				}
			}
		}
		for(int l=0;l<=n;++l){
			end_at[l] = cpy[l];
			cpy[l] = 0;
		}
	}*/

	ll nom = end_at[n];
	
	//ll g = gcd(nom, denominator);
	//nom /= g;
	//denominator /= g;

	denominator = inv_mod(denominator, MOD);
	cout << (nom*denominator) % MOD << endl;

}



















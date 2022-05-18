#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
const ll MOD = 1000000007;

template<class T>
T binpow(T a, ll n){
	T b(1);
	while(n){
		if (n & 1){
			b = (b*a);
		}
		n >>= 1;
		a = (a*a);
	}
	return b;
}

ll bp(ll a, ll n){
	ll b(1);
	while(n){
		if (n & 1){
			b = (b*a)%MOD;
		}
		n >>= 1;
		a = (a*a)%MOD;
	}
	return b;
}

struct Frac{
	ll top, bot;
	Frac(): top(0), bot(1) {}
	Frac(ll a, ll b): top(a), bot(b) {
		ll g = gcd(a, b);
		top/=g;
		bot/=g;
		top = (top%MOD + MOD) % MOD;
		bot = (bot%MOD + MOD) % MOD;
	}
	Frac(ll a): top(a), bot(a) {}
	Frac(const Frac& a): top(a.top), bot(a.bot) {}
	Frac operator*(Frac b){
		return Frac{top*b.top, bot*b.bot};
	}
	Frac operator+(Frac b){
		return Frac{top*b.bot + b.top*bot, bot*b.bot};
	}
	Frac operator-(Frac b){
		return Frac{top*b.bot + b.top*bot, bot*b.bot};
	}
	ll toll(){
		return (top * bp(bot, MOD-2));
	}
	void pr(){
		cout << top << " " << bot << endl;
	}
};

// struct mat2{
// 	Frac M[2][2];
// 	mat2() {
// 		M[0][0] = M[0][1] = M[1][0] = M[1][1] = Frac(1,1);
// 	}
// 	mat2(int a): M{{0}} {
// 		M[0][0] = M[1][1] = 1;
// 	}
// 	mat2 operator*(mat2 b){
// 		mat2 c;
// 		rep(i,0,2){
// 			rep(j,0,2){
// 				rep(k,0,2){
// 					c.M[i][j] = c.M[i][j] + (M[i][k]*b.M[k][j]);
// 				}
// 			}
// 		}
// 		return c;
// 	}
// };

struct mat2{
	ll M[2][2];
	mat2() {
		M[0][0] = M[0][1] = M[1][0] = M[1][1] = 0;
	}
	mat2(int a): M{{0}} {
		M[0][0] = M[1][1] = 1;
	}
	mat2 operator*(mat2 b){
		mat2 c;
		rep(i,0,2){
			rep(j,0,2){
				rep(k,0,2){
					c.M[i][j] = c.M[i][j] + (M[i][k]*b.M[k][j]);
					c.M[i][j] %= MOD;
				}
			}
		}
		return c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// (Frac(1,1)+Frac(1,MOD-1)).pr();
	// cout << (Frac(1,1)+Frac(1,MOD-1)).toll() << endl;

	ll a, b, n;
	cin >> a >> b >> n;

	ll invaabb = bp( (a*a+b*b)%MOD, MOD-2 );

	ll si = (((2*a*b)% MOD)*invaabb)%MOD;
	ll msi = MOD - si;

	ll co = (((a*a-b*b)%MOD)*invaabb)%MOD+MOD;
	co %= MOD;

	mat2 m;
	m.M[0][0] = m.M[1][1] = co;
	m.M[1][0] = msi;
	m.M[0][1] = si;

	auto res = binpow(m, n+1);
	cout << (MOD - res.M[0][0])%MOD << endl;

	// Frac si(2*a*b, a*a + b*b);
	// Frac msi(-2*a*b, a*a + b*b);
	// Frac co(a*a - b*b, a*a + b*b);
	// mat2 m;
	// m.M[0][0] = m.M[1][1] = co;
	// m.M[1][0] = msi;
	// m.M[0][1] = si;
	// mat2 res = binpow<mat2>(m, n+1);
	// auto x = res.M[0][0].toll();
	// res.M[0][0].pr();
	// // auto y = res.M[1][0].toll();
	// cout << x << endl;
}
















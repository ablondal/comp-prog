#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// char s[100007];
// unordered_map<int, int> first;

int main() {
	int xa, ya, xb, yb, xc, yc;
	int d, v;
	cin >> xa >> ya >> xb >> yb >> xc >> yc >> d >> v;
	int HH, MM, HH1, MM1;
	scanf(" %d:%d %d:%d", &HH, &MM, &HH1, &MM1);
	int w;
	cin >> w;
	double t1 = sqrt( (xa-xc)*(xa-xc) + (ya-yc)*(ya-yc) )/(double)v;
	t1 += (double)d/60;
	t1 += sqrt( (xb-xc)*(xb-xc) + (yb-yc)*(yb-yc) )/(double)v;

	double t2 = HH1 + HH - 9 + (double) (MM+MM1)/60.0;

	double t3 = sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) )/(double)w;
	int dx = xb-xa;
	int dy = yb-ya;
	int cx = xc-xa;
	int cy = yc-ya;
	if (dx/gcd(dx,dy) == cx/gcd(cx,cy) && dy/gcd(dx,dy) == cy/gcd(cx,cy)){
		t3 += (double)d/60;
	}
	if (t1<t2 && t1<t3){
		printf("Alex\n");
	}else if (t2<t1 && t2<t3){
		printf("Dmitry\n");
	}else{
		printf("Petr\n");
	}
}
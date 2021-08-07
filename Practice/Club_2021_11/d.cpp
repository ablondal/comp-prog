#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
const int INF = 1e9;

const ld rat = 0.5833333333333333;
const ld pi = 3.141592653589793;

vi adj[200007];
char V[200007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int xp, yp, xd, yd;
	scanf("%d%d%d%d", &xp, &yp, &xd, &yd);
	long double dist = sqrt( (xp-xd)*(xp-xd) + (yp-yd)*(yp-yd) );
	long double area = pi * (dist * rat) * (dist / 2.0);
	printf("%0.15Lf\n", area);
}
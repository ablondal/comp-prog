#include <vector>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int primes[] = {2,3,5,7,11,13,17,19,23};
// const int sump[] = {2,3,5,7,11,13,17,19,23,29};

int main() {
	int b1 = 0;
	int b2 = 0;
	int n;
	scanf("%d",  &n);
	vi a(n), b(n), c(n);
	rep(i,0,n){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		if (c[i] > a[i]) swap(c[i], a[i]);
		if (b[i] > a[i]) swap(b[i], a[i]);
		if (c[i] > b[i]) swap(c[i], b[i]);
		b1 = max(b1, b[i]);
		b2 = max(b2, c[i]);
	}
	int tot = 0;
	rep(i,0,n){
		if (a[i]>b1 && b[i]>b2){
			tot++;
		}
	}
	printf("%d\n", tot);
	bool f = false;
	rep(i,0,n){
		if (a[i]>b1 && b[i]>b2){
			if (f) printf(" ");
			else f = true;
			printf("%d", i+1);
		}
	}
	printf("\n");
}
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	int n;
	scanf("%d", &n);
	vi a(n);
	rep(i,0,n){scanf("%d",&a[i]);}
	sort(all(a));
	vi used(n,0);
	vi b;
	int pa=0, pb=sz(a)/2;
	while(pb<n){
		while(a[pb]==a[pa]){
			pb++;
			if (pb==n) break;
		}
		if (pb<n){
			b.push_back(a[pb++]);
			b.push_back(a[pa++]);
			used[pb-1]=1;
			used[pa-1]=1;
		}
	}
	rep(i,0,n){
		if (!used[i]){
			b.push_back(a[i]);
		}
	}
	int tot=0;
	rep(i,1,n-1){
		if (b[i-1]>b[i] && b[i+1]>b[i]) tot++;
	}

	printf("%d\n", tot );
	printf("%d",b[0]);
	rep(i,1,n) printf(" %d", b[i]);
	printf("\n");
}
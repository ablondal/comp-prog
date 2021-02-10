#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 5e4+7;

// const int primes[] = {2,3,5,7,11,13,17,19,23};
// const int sump[] = {2,3,5,7,11,13,17,19,23,29};
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pair<int, int>> pts;
	vector<pair<int, int>> seg(n+1);
	vector<bool> onseg(n+1, 0);
	vector<bool> removed(n+1, false);
	rep(i,1,n+1){
		int l,r;
		scanf("%d%d", &l, &r);
		pts.push_back({l, -i});
		pts.push_back({r, i});
		seg[i].first = l;
		seg[i].second = r;
	}
	sort(all(pts));
	int on = 0;
	int i=0;
	int rmd = 0;
	while(i<2*n){
		int x = pts[i].first;
		while(i<2*n && pts[i].first == x && pts[i].second < 0){
			// if (pts[i].second < 0){
			// 	onseg[-pts[i].second] = true;
			// 	on++;
			// }else{
				
			// 	if (onseg[pts[i].second]) on--;
			// 	onseg[pts[i].second] = false;
			// }
			// ++i;
			onseg[-pts[i].second] = true;
			on++;
			++i;
		}
		while(on>k){
			int last = -1;
			rep(i,1,n+1){
				if (onseg[i]) {
					// printf("%d %d\n", i, seg[i].second);
					if (last==-1 || seg[i].second > seg[last].second){
						last = i;
					}
				}
			}
			rmd++;
			removed[last] = true;
			onseg[last] = false;
			on--;
		}
		while(i<2*n && i<2*n && pts[i].first == x){
			if (onseg[pts[i].second]) on--;
			onseg[pts[i].second] = false;
			++i;
		}
	}
	printf("%d\n", rmd);
	bool f = false;
	rep(i,1,n+1){
		if (removed[i]) {
			if (f) printf(" ");
			else f = true;
			printf("%d", i);
		}
	}
	printf("\n");

}
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, m, t, N, M;
int main(){
	int c = 1;
	while(scanf("%lli%lli", &n, &m) != EOF){
		vector<ll> A(1,0);
		vector<ll> B(1,0);
		rep(i,0,n){
			scanf("%lli", &t);
			A.push_back(t);
		}
		rep(i,0,m){
			scanf("%lli", &t);
			B.push_back(t);
		}
		sort(all(A));
		sort(all(B));
		vector<ll> AA(all(A));
		vector<ll> BB(all(B));

		int ia=sz(A)-1, ib=sz(B)-1;
		int turn = 1;

		bool WA1 = false, WA2 = false;

		if (A[ia]>B[ib]){
			ib--;
			turn = 1;
			while(ia>0 && ib>0){
				if (turn % 2 == 0){
					if (A[ia]>B[ib]){
						ib--;
					}else{
						A[ia-1] += A[ia];
						ia--;
					}
				}else{
					if (A[ia]<B[ib]){
						ia--;
					}else{
						B[ib-1] += B[ib];
						ib--;
					}
				}
				turn++;
			}
			if (ia) WA1 = true;

			A.swap(AA);
			B.swap(BB);
		}

		ia=sz(A)-1;
		ib=sz(B)-1;
		turn = 1;

		A[ia-1] += A[ia];
		ia--;

		while(ia>0 && ib>0){
			if (turn % 2 == 0){
				if (A[ia]>B[ib]){
					ib--;
				}else{
					A[ia-1] += A[ia];
					ia--;
				}
			}else{
				if (A[ia]<B[ib]){
					ia--;
				}else{
					B[ib-1] += B[ib];
					ib--;
				}
			}
			turn++;
		}
		if (ia) WA2 = true;

		if (WA1 || WA2){
			printf("Case %d: Takeover Incorporated\n", c);
		}else{
			printf("Case %d: Buyout Limited\n", c);
		}
		c++;
	}

}

























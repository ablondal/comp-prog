#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef bitset<250> bs;

bs A[250] = {0};
bool b[250] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	// Populate the matrix
	rep(i,0,n){
		int c;
		scanf("%d", &c);
		while(c!=-1){
			A[c-1][i] = true;
			scanf("%d", &c);
		}
	}
	// Set up b vector, we want a solution to be all 1s
	rep(i,0,n) b[i] = true;

	// Do Gaussian elimination
	rep(i,0,n){
		// row
		// Pivot if needed
		if (A[i][i] == false){
			// find a j to replace
			rep(j,i+1,n){
				if (A[j][i] == true){
					swap(A[i], A[j]);
					// auto c = b[i];
					// b[i]=b[j];
					// b[j]=c;
					swap(b[i], b[j]);
					break;
				}
			}
		}

		rep(j,i+1,n){
			if (A[j][i]){
				A[j] ^= A[i];
				b[j] ^= b[i];
			}
		}
	}
	// We have rref form

	// Now eliminate up
	for(int i=n-1; i>0; --i){
		for(int j=i-1; j>=0; --j){
			if (A[j][i]){
				A[j] ^= A[i];
				b[j] ^= b[i];
			}
		}
	}
	
	rep(i,0,n){
		if (b[i]){
			printf("%d ", i+1);
		}
	}
	printf("\n");
}
#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int sm[500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,1,500){
		sm[i] = (i-1) + (i-1)*(i-2);
		// printf("%d: %d\n", i, sm[i]);
		if (sm[i]>1e5) break;
	}
	int t;
	cin >> t;
	if (t == 1){
		cout << "2 1" << endl << "1 2" << endl;
		return 0;
	} else if (t==2 || t==5){
		cout << "Impossible" << endl;
		return 0;
	} else if (t==0){
		cout << "1 0" << endl;
		return 0;
	}
	int hi = 0;
	while(sm[hi]<t){
		hi++;
	}
	printf("%d %d\n", hi, (hi-1) + (sm[hi] - t));
	rep(i,2,hi+1){
		printf("1 %d\n", i);
	}
	int rest = sm[hi]-t;
	rep(i,2,hi){
		rep(j,i+1,hi+1){
			if (rest){
				rest--;
				printf("%d %d\n", i, j);
			}
		}
	}
}
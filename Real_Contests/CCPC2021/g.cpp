#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int nums[10][10];
char star[10][10] = {{0}};

int ct_zone[10] = {0};
int ct_row[10] = {0};
int ct_col[10] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	rep(i,0,10){
		rep(j,0,10){
			scanf(" %1d", &nums[i][j]);
			// printf("%d ", nums[i][j]);
		}
		// printf("\n");
	}
	bool works = true;
	rep(i,0,10){
		rep(j,0,10){
			char a;
			scanf(" %c", &a);

			if (a=='*'){
				star[i][j] = 1;
				if ( (i && star[i-1][j]) || (j && star[i][j-1]) || (i && j && star[i-1][j-1]) || (i && (j!=9) && star[i-1][j+1])){
					works = false;
				}
				ct_zone[nums[i][j]]++;
				ct_row[i]++;
				ct_col[j]++;
			}
		}
	}
	rep(i,0,10){
		if (ct_zone[i]!=2 || ct_row[i]!=2 || ct_col[i]!=2){
			works = false;
		}
	}
	cout << (works ? "valid" : "invalid") << endl;
}
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	int mp;
	scanf("%d", &mp);
	hh += (mm + mp)/60;
	hh %= 24;
	mm += mp;
	mm %= 60;
	printf("%02d:%02d\n", hh, mm);

}
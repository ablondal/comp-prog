#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	int a;
	scanf("%d", &a);
	a %= (60*24);
	while(a>60){
		hh++;
		hh %= 24;
		a -= 60;
	}
	while(a){
		mm++;
		a--;
		if (mm==60){
			mm = 0;
			hh += 1;
			hh %= 24;
		}
	}
	printf("%0.2d:%0.2d\n", hh, mm);
}
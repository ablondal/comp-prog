#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int MAXN = 1000;

vi G[MAXN];

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int m = max(a, b);
	m = max(m, c);
	m = max(m, d);
	vi ans;
	if (m!=a) ans.push_back(m-a);
	if (m!=b) ans.push_back(m-b);
	if (m!=c) ans.push_back(m-c);
	if (m!=d) ans.push_back(m-d);
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}
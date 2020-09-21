#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
#define max(a,b) ((a>b)?a:b)
using namespace std;
typedef long long ll;

unordered_map <ll, ll> DP;
unordered_map <ll, ll>::iterator it;
vector<pair<ll, ll> > trees;

int main(){
	int t, T;
	scanf("%d", &T);
	for(t=1; t<=T; ++t){
		ll best = 0;
		int N;
		scanf("%d", &N);
		trees.clear();
		DP.clear();
		trees.resize(N);
		DP.reserve(2*N);
		for(int i=0; i<N; ++i){
			scanf("%lli%lli", &trees[i].first, &trees[i].second);
		}
		sort(trees.begin(), trees.end());
		for(int i=0; i<N; ++i){
			int a=0, b=0, c=0;
			it = DP.find(trees[i].first-trees[i].second);
			if (it != DP.end()){
				a = it->second;
			}
			it = DP.find(trees[i].first);
			if (it != DP.end()){
				b = it->second;
			}
			it = DP.find(trees[i].first+trees[i].second);
			if (it != DP.end()){
				c = it->second;
			}

			c = max(c, b+trees[i].second);
			b = max(b, a+trees[i].second);

			DP[trees[i].first] = b;
			DP[trees[i].first+trees[i].second] = c;

			best = max(best, b);
			best = max(best, c);
		}

		printf("Case #%d: %lli\n", t, best);
	}
}












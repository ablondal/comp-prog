#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool match(int v, vvi &adj, vi &V, vi &M){
	for(auto e: adj[v]){
		if (!V[e]){
			V[e] = 1;
			if (M[e] == -1 || match(M[e], adj, V, M)){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

bool match2(int v, vvi &adj, vvi &adj2, vi &V, vi &M){
	for(auto e: adj2[v]){
		if (!V[e]){
			V[e] = 1;
			if (M[e] == -1 || match(M[e], adj, V, M)){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

class ChessMatchup{
	public:
	static int maximumScore(vi us, vi them){
		vi M(them.size(), -1);
		vi Ma(us.size(), 0);
		vi V(them.size(), 0);
		vvi adj(us.size(), vi());
		vvi adj2(us.size(), vi());
		sort(us.begin(), us.end());
		sort(them.begin(), them.end());

		for(int i=0; i<us.size(); ++i){
			for(int j=0; j<them.size(); ++j){
				if(us[i] > them[j]){
					adj[i].push_back(j);
				}else if (us[i] == them[j]){
					adj2[i].push_back(j);
				}
			}
		}

		int tot = 0;
		for(int i=0; i<us.size(); ++i){
			V.clear();
			V.resize(them.size(), 0);
			if (match(i, adj, V, M)) {
				tot += 2;
				Ma[i] = 1;
			}
		}
		// for(int i=0; i<them.size(); ++i){
		// 	printf("%d ", M[i]);
		// }
		// printf("\n");

		for(int i=0; i<us.size(); ++i){
			if (Ma[i]) continue;
			V.clear();
			V.resize(them.size(), 0);
			if (match2(i, adj, adj2, V, M)) {
				tot += 1;
				Ma[i] = 1;
			}
		}

		// for(int i=0; i<them.size(); ++i){
		// 	printf("%d ", M[i]);
		// }
		// printf("\n");
		return tot;
	}
};

int main(){
	printf("%d\n", ChessMatchup::maximumScore({5, 8}, {7, 3}));

	printf("%d\n", ChessMatchup::maximumScore({7, 3}, {5, 8}));

	printf("%d\n", ChessMatchup::maximumScore({1, 5, 10}, {1, 5, 10}));

	printf("%d\n", ChessMatchup::maximumScore({1, 4, 7, 10}, {3, 7, 8, 15}));
}











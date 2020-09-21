#include <vector>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<bool> vb;

bool dfs(int v, vvi &adj, vi &M, vi &vis){
	for(int e: adj[v]){
		if (!vis[e]){
			vis[e] = true;
			if(M[e] == -1 || dfs(M[e], adj, M, vis)){
				M[e] = v;
				return true;
			}
		}
	}
	return false;
}

int maxMatch(vvi adj, int n, int m){
	vi M(m, -1);
	int tot=0;
	vi vis(m, 0);
	for(int i=0; i<n; ++i){
		if (dfs(i, adj, M, vis))
			tot++;
		vis.clear();
		vis.resize(m, 0);
	}
	return tot;
}

class PlayingCubes{
public:
	static vi composeWords(vector<string> cubes, vector<string> words){
		vi ans;
		for(int s=0; s<words.size(); ++s){
			string word = words[s];
			if (word.size() > cubes.size()) continue;
			vvi adj(word.size());
			for (int i=0; i<word.size(); ++i){
				for(int j=0; j<cubes.size(); ++j){
					for(int k=0; k<6; ++k){
						if (cubes[j][k] == word[i]){
							adj[i].push_back(j);
							break;
						}
					}
				}
			}
			if (maxMatch(adj, word.size(), cubes.size()) == word.size()){
				ans.push_back(s);
			}
		}
		return ans;
	}
};


int main(){
	vi r1 = PlayingCubes::composeWords(
		{"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "YYYYYY"},
		{"CAT", "DOG", "PIZZA"}
	);

	for(auto r: r1){
		cout << r << endl;
	}
	cout << endl;

	r1 = PlayingCubes::composeWords(
		{"ABCDEF", "DEFGHI", "OPQRST", "MNZLSA", "QEIOGH", "IARJGS"},
		{"DOG", "CAT", "MOUSE", "BIRD", "CHICKEN", "PIG", "ANIMAL"}
	);

	for(auto r: r1){
		cout << r << endl;
	}
	cout << endl;


	r1 = PlayingCubes::composeWords(
		{"AAAAAA", "AAAAAA", "AAAAAA", "AAAAAA"},
		{"AA", "AAA", "AAAA", "AAAAA", "AAAAAA"}
	);

	for(auto r: r1){
		cout << r << endl;
	}
	cout << endl;

	r1 = PlayingCubes::composeWords(
		{"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "ZZZZZZ"},
		{"CAT", "DOG", "PIZZA"}
	);

	for(auto r: r1){
		cout << r << endl;
	}
	cout << endl;
}










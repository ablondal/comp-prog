#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// incomplete
#define sz(x) (int)(x).size()

struct KMP_Failure_Function{
	string word;
	vector<int> table;
	int match(int state, char c) {
		while(state > 0 && word[state] != c)
			state = table[state-1];
		if (word[state] == c) return state+1;
		return 0;
	}
	KMP_Failure_Function(string s): word(s), table(sz(s), 0) {
		for(int i=1; i<sz(s); i++){
			table[i] = match(i-1, s[i]);
		}
	}
};

bool solve(){
	// Input //
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0) return 0;
	vector<pair<char, double>> keyboard(n);
	for(int i=0; i<n; i++){
		cin >> keyboard[i].first >> keyboard[i].second;
	}
	string word;
	cin >> word;

	// Create KMP function and DP table //
	KMP_Failure_Function kmp(word);
	vector<vector<double>> DP(m+1, vector<double>(sz(word)+1, 0));
	// DP[i][k] = probability of the KMP search function being at state
	// k after i characters. State k = sz(word) corresponds to the word
	// begin found already.
	DP[0][0] = 1;

	// Perform DP //
	for(int i=0; i<m; ++i){
		DP[i+1][sz(word)] += DP[i][sz(word)];
		// Probability of the word being found by now

		for(int state=0; state<sz(word); state++){
			for(int j=0; j<sz(keyboard); j++){
				char c = keyboard[j].first;
				double p = keyboard[j].second;

				// Use kmp.match to move between states
				DP[i+1][kmp.match(state, c)] += DP[i][state]*p;
			}
		}
	}
	printf("%0.2f%%\n", DP[m][sz(word)]*100);
	return 1;
}

int main() {
	// Can't use these cause I'm mixing cin and printf
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	while(solve());
}
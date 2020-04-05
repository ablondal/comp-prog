#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
typedef vector<int> vi;
typedef vector<vi> vvi;

// DONE

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		int N;
		cin >> N;
		vector <int> S(N);
		vector <int> E(N);
		vector <int> O(N);
		vector <char> which(N,'a');
		for(int i=0; i<N; ++i){
			cin >> S[i] >> E[i];
			O[i] = i;
		}
		sort(O.begin(),O.end(),[&S](int a, int b){return S[a]<S[b];});
		int Jend=0, Cend=0;
		bool doable = true;
		for(int i=0; i<N; ++i){
			int a = O[i];
			if (Jend<=S[a]){
				Jend = E[a];
				which[a]='J';
			}else if (Cend<=S[a]){
				Cend = E[a];
				which[a]='C';
			}else{
				doable = false;
				break;
			}
		}
		cout << "Case #"<<t<<": ";
		if(doable){
			for(int i=0; i<N;++i){
				cout << which[i];
			}
		}else{
			cout << "IMPOSSIBLE";
		}
		cout << endl;
	}
}
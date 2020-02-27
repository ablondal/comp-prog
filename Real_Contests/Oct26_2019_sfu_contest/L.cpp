#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);
const double EPS = 1e-9;
const double pi = acos(-1);
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main(){
	int T;
	for(cin >> T; T>0; --T){
		int N;
		cin >> N;
		vector <int> jars;
		jars.resize(N);
		for(int i=0; i<N; ++i){
			cin >> jars[i];
		}
		int M = N*(N-1);
		bool istrue = true;
		for(int j=0; j<N; ++j){
			if(1<=jars[j]%M && jars[j]%M <= N-1){
				continue;
			}else{
				istrue = false;
				break;
			}
		}
		if(istrue) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	return 0;
}
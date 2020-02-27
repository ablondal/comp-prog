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
	vector <set <char> > P;
	int T;

	char qi, ai;
	for(cin>>T; T>0; --T)
	{
		int Q,M;
		cin >> Q >> M;
		P.resize(Q);
		for(int i=0; i<Q; ++i)
		{
			P[i].insert('A');
			P[i].insert('D');
			P[i].insert('C');
			P[i].insert('B');
		}
		for(int j=0; j<M; ++j)
		{
			for(int i=0; i<Q; ++i)
			{
				cin >> qi >> ai;
				if(ai=='T')
				{
					P[i].clear();
					P[i].insert(qi);
				}else{
					P[i].erase(qi);
				}
			}
		}
		for(int i=0; i<Q; ++i)
		{
			if(P[i].size()==1)
			{
				cout << *P[i].begin();
			}else{
				cout << "?";
			}
			if(i!=Q-1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
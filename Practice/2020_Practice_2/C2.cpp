#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

int find_0(ll S){
	
	unordered_set <ll> found;
	queue <ll> Q;
	Q.push(S);
	Q.push(-1);
	found.insert(S);
	int steps = 0;
	ll C;
	while (Q.front()!=0){
		C = Q.front();
		// cout << C << endl;
		Q.pop();
		if ( C==-1 )
		{
			steps++;
			Q.push(-1);
		}
		else if ( C%2 == 0 )
		{
			//cout << "even" << endl;
			if ( found.find(C/2) == found.end() )
			{
				Q.push(C/2);
				found.insert(C/2);
			}
		}
		else
		{
			//cout << "odd" << endl;
			if ( found.find(C+1) == found.end() )
			{
				Q.push(C+1);
				found.insert(C+1);
			}
			if ( found.find(C-1) == found.end() )
			{
				Q.push(C-1);
				found.insert(C-1);
			}
		}
	}
	return steps;
}

int main(){
	ll S;
	while(cin>>S){
		cout << find_0(S) << endl;
	}
}
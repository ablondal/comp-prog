#include <iostream>
#include <vector>
using namespace std;
long long highscore[51];


int main(){
	int T;
	for(cin>>T;T>0;--T){
		int m,n,p;
		int pos;
		cin >> m>>n>>p;
		for(int i=0;i<51;++i){
			highscore[i] = -1;
		}
		pos = -1;
		for(int i=1;i<=m;++i){
			cin >> highscore[i];
			
		}
		for(int i=1;i<=p;++i){
			if(n>=highscore[i]){
				pos = i;
				break;
			}
		}
		if(m==p && n<=highscore[m]){
			pos = -1;
		}
		cout << pos << endl;
	}
}
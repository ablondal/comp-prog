#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Done

int bin_find( const vector <int> &L, int x ){
	int lo = 0;
	int hi = L.size();
	//cout << "hi is " << hi << endl;
	/*for(int i=0;i<L.size(); ++i){
		cout << L[i] << endl;
	}*/
	int mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		if(L[mid] < x){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
	if (hi==L.size()) return -1;
	return L[hi];
}

int main(){
	int T;
	for(cin>>T; T>0; --T){
		string S,T;
		cin >> S >> T;
		int z=0;
		int round=1;
		int r = 0;
		int x;
		vector <int> AT[26];
		for(int i=0; i<S.size(); ++i){
			AT[ S[i]-'a' ].push_back(i);
		}
		while(z<T.size() && round){
			round = 0;
			x = 0;
			int f;
			while ( z<T.size() ){
				f = bin_find( AT[T[z]-'a'] , x );
				//cout << f << endl;
				if (f==-1) break;

				round++;
				z++;
				x = f+1;
			}
			r++;
		}
		if (z==T.size()){
			cout << r << endl;
		}else{
			cout << -1 << endl;
		}
	}
}










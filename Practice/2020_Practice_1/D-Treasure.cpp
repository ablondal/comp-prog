#include <iostream>
#include <string>

using namespace std;

int main(){
	string S;
	cin >> S;
	int num_h = 0;
	int diff = 0;
	for(int i=0; i< S.size(); ++i){
		if (S[i]=='(') diff++;
		else if (S[i]==')') diff--;
		else num_h++;
	}
	if (num_h > diff) cout << -1 << endl;
	else{
		int n_diff = 0;
		int n_h = num_h;
		for(int i=0; i<S.size(); ++i){
			if (S[i]=='(') n_diff++;
			else if (S[i]==')') n_diff--;
			else{
				n_diff--;
				n_h--;
				if(n_h==0) n_diff -= diff-num_h;
			}
			if (n_diff<0){
				cout << -1 << endl;
				exit(0);
			}
		}
		for(int i=0; i<num_h; ++i){
			if(i==num_h-1) cout << diff-num_h+1 << endl;
			else cout << 1 << endl;
		}
	}
}
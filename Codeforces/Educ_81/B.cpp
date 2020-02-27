#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Done

int main(){
	int T;
	for(cin>>T; T>0; --T){
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		int minbal = 0;
		int maxbal = 0;
		int totbal = 0;
		for(int i=0; i<s.size(); ++i){
			if (s[i]=='0') totbal++;
			else totbal--;
			if (totbal<minbal) minbal = totbal;
			if (totbal>maxbal) maxbal = totbal;
		}

		vector <int> n_bal(200001,0);
		n_bal[100000]++; // balance of 0
		int bal = 0;

		for(int i=0; i<s.size()-1; ++i){
			if (s[i]=='0') bal++;
			else bal--;
			n_bal[bal+100000]++;
		}

		// x is desired balance

		if (totbal == 0){
			if (minbal<=x && maxbal>=x){
				cout << -1 << endl;
			}else{
				cout << 0 << endl;
			}
		}else if(totbal>0 && x<minbal){
			cout << 0 << endl;
		}else if(totbal<0 && x>maxbal){
			cout << 0 << endl;
		}else{
			long long numpref = 0;
			if(x>100000){
				x -= totbal*( (x-100000)/totbal );
				while (x > 100000) x -= totbal;
			}else if (x< -100000){
				x -= totbal*( (x+100000)/totbal );
				while (x < -100000) x -= totbal;
			}

			//assert(minbal<=x && maxbal>=x);

			while(x<=100000 && x>=-100000){
				numpref += n_bal[x+100000];
				x -= totbal;
			}
			cout << numpref << endl;
		}

	}
}












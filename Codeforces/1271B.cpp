#include <string>
#include <vector>
#include <iostream>
using namespace std;

//DONE

int main(){
	int n;
	cin >> n;
	vector <bool> B(n);
	vector <bool> W(n);
	vector <int> bl,wh;
	string inp;
	cin >> inp;
	for(int i=0; i<n; ++i){
		if (inp[i]=='W'){
			B[i] = 0;
			W[i] = 1;
		}else{
			B[i] = 1;
			W[i] = 0;
		}
	}
	for(int i=0; i<n-1; ++i){
		if(!B[i]){
			B[i] = !B[i];
			B[i+1] = !B[i+1];
			bl.push_back(i+1);
		}
		if(!W[i]){
			W[i] = !W[i];
			W[i+1] = !W[i+1];
			wh.push_back(i+1);
		}
	}
	if(W[n-1]){
		cout << wh.size() << endl;
		for(int i=0; i<wh.size(); ++i){
			cout << wh[i];
			if (i!=wh.size()-1){
				cout << " ";
			}
		}
		cout << endl;
	}else if(B[n-1]){
		cout << bl.size() << endl;
		for(int i=0; i<bl.size(); ++i){
			cout << bl[i];
			if (i!=bl.size()-1){
				cout << " ";
			}
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
}














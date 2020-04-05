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

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		string inp;
		cin >> inp;
		int n_d = 0;
		cout << "Case #" << t << ": ";
		for(int i=0; i<inp.size(); ++i){
			int d = inp[i]-'0';
			if (n_d < d){
				for(int j=0; j< d-n_d; ++j){
					cout << '(';
				}
				n_d = d;
			}else{
				for(int j=0; j<n_d-d; ++j){
					cout << ')';
				}
				n_d = d;
			}
			cout << d;
		}
		for(int j=0; j<n_d; ++j){
			cout << ')';
		}
		cout << endl;
	}
}
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

typedef vector <int> vi;
typedef long long ll;
typedef vector <ll> vll;

int main(){
	int t;
	for(cin >> t; t>0; --t){
		int s;
		cin >> s;
		if(s==1) cout << "-1" << endl;
		else{
			cout << "2";
			for(int i=1; i<s; ++i){
				cout << "3";
			}
			cout << endl;
		}
	}
}






























#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

int main(){
	int C;
	for(cin>>C;C>0;--C){
		int n;
		cin >> n;
		// if (n==2) cout << "3" << endl;
		vector <int> V(n,0);
		int k=2;
		// V[1] = ;
		// V[2] = true;
		int f1 = 2;
		int f2 = 1;
		int t;
		while(!V[f1]){
			V[f1] = k;
			t = f1;
			f1 = (f1+f2)%n;
			f2 = t;
			k++;
		}
		cout << V[f1] << endl;
	}
}
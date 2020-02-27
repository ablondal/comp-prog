#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// DONE

int main(){
	int t;
	for(cin>>t;t>0;--t){
		int n;
		cin>>n;
		if(n%2==1){
			n-=3;
			cout << "7";
		}
		while(n>0){
			cout << "1";
			n-=2;
		}
		cout << endl;
	}
}
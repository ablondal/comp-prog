#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int T;
	string test;
	int n1,n3,tot;
	for(cin >>T;T>0;--T){
		cin >> test;
		n1 = 0;
		n3 = 0;
		tot = test.size();
		for(int i=0;i<test.size();++i){
			if(test[i]=='3'){n3++;}
		}
		for(int i=0;i<=test.size();++i){
			if(i!=0){
				if(test[i-1]=='1'){
					n1++;
				}else{
					n3--;
				}
			}
			if(tot>n1+n3){
				tot=n1+n3;
			}
		}
		cout << tot << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	if(n%2 == 1){
		for(int i = 0; i < s1.size(); i++){
			if(s1[i] == '0'){
				s1[i] = '1';
			}else{
				s1[i] = '0';
			}
		}
	}
	if(s1 == s2){
		cout << "Deletion succeeded" << endl;
	}else{
		cout << "Deletion failed" << endl;
	}
}
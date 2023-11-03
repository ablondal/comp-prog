#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = min(s1.size(), s2.size());
	int prefix = 0;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]){
			break;
		}
		prefix++;
	}
	int suffix = 0;
	int s1End = s1.size() - 1, s2End = s2.size() - 1;
	for(int i = 0; i < n; i++){
		if(prefix + suffix == n){
			break;
		}
		if(s1[s1End - i] != s2[s2End - i]){
			break;
		}
		suffix++;
	}
	int answer = s2.size() - prefix - suffix;
	cout << max(answer, 0) << endl;
}
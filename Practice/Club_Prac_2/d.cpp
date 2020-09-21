#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i,k) for(int i=0; i<k; ++i)

void encrypt(string m){
	vector <char> nums(m.size()-2);
	for(int i=2; i<m.size(); ++i){
		if (m[i]==' ') nums[i-2] = 0;
		else nums[i-2] = m[i]+1-'a';
	}
	for(int i=0; i<nums.size(); ++i){
		if (i>0) nums[i] += nums[i-1];
		nums[i] %= 27;
		if (nums[i]==0) cout << ' ';
		else cout << (char)(nums[i]-1+'a');
	}
	cout << endl;
}

void decrypt(string m){
	vector <char> nums(m.size()-2);
	for(int i=2; i<m.size(); ++i){
		if (m[i]==' ') nums[i-2] = 0;
		else nums[i-2] = m[i]+1-'a';
	}
	for(int i=nums.size()-1; i>0; --i){
		if (i>0) nums[i] -= nums[i-1];
		nums[i] = (nums[i]+27) % 27;
	}
	
	for(int i=0; i<nums.size(); ++i){
		if (nums[i]==0) cout << ' ';
		else cout << (char)(nums[i]-1+'a');
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	string f;
	getline(cin, f);
	while(n--){
		string m;
		getline(cin, m);
		if(m[0]=='e'){
			encrypt(m);
		} else {
			decrypt(m);
		}
	}
}
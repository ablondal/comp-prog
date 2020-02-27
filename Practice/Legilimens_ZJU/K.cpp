#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	bool isg = false;
	int a=0,b=0;
	if(s[0]!=t[0]){
		cout << "No" << endl;
		return 0;
	}
	while(!(a==s.size() || b==t.size())){
		if(s[a]==t[b]){
			a++;b++;
		}else if(!isg && t[b]==s[0]){
			cout << "No" << endl;
			return 0;
		}else{
			b++;
		}
		if(!isg && t[b]!=s[0]){
			isg = true;
		}
	}
	if(a==s.size() && isg){
		cout << "Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}
	return 0;
}
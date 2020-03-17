#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

int main(){
	string code;
	string key;
	cin >> code >> key;
	string outp = "";
	for(int i=0; i<code.size(); ++i){
		if (i%2==0){
			outp += ( (code[i]-'A') - (key[i]-'A') + 26 )%26 + 'A';
		}else{
			outp += ( (code[i]-'A') + (key[i]-'A') + 26 )%26 + 'A';
		}
	}
	cout << outp << endl;
}
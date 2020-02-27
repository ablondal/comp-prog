#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int o = 0;
		vector <bool> bin;
		while(n>0){
			if(n%2 == 1){
				bin.push_back(1);
			}else{
				bin.push_back(0);
			}
			n/=2;
		}
		int leno = 0;
		for(int i=bin.size()-1; i>=0; --i){
			if(bin[i] == 1){
				leno++;
			}else{
				if (leno > 1){
					o += 2;
				}else{
					o += leno;
				}
				leno = 0;
			}
		}
		if (leno > 2){
			o += 3;
		}else{
			o += leno;
		}
		o += bin.size()-1;
		
		// Now o is the potential max

	}
}
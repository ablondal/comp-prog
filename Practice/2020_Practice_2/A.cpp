#include <iostream>

using namespace std;


int main(){
	int n, tmp;
	cin >> n;
	int pluscost = 0;
	bool istaken[6001] = {0};
	for(int i=0; i<n; ++i){
		cin >> tmp;
		while(istaken[tmp]){
			tmp++;
			pluscost++;
		}
		istaken[tmp] = true;
	}
	cout << pluscost << endl;
}
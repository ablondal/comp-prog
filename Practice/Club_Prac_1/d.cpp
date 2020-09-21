#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector <int> W(n);
	for(auto &w : W){
		cin >> w;
	}
	int totadd = 0;
	for(int i=1; i<n; ++i){
		if (k - W[i] - W[i-1] > 0){
			totadd += k - W[i] - W[i-1];
			W[i] = k - W[i-1];
		}
	}
	cout << totadd << endl;
	for(int i=0; i<n; ++i){
		if (i!=0) cout << " ";
		cout << W[i];
	}
	cout << endl;
}
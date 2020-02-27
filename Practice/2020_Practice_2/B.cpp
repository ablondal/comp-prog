#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0; i<n; ++i){
		if (i==n-1){
			cout << a[n/2] << endl;
		}
		else if(i % 2 == 0){
			cout << a[i/2] << " ";
		}else{
			cout << a[n- 1- (i/2)] << " ";
		}
	}
}
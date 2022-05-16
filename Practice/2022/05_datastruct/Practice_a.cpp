#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> days(n);
	for(int i=0; i<n; ++i){
		cin >> days[i];
	}

	int cleans = 0;
	int lastclean = -1;
	
	for (int i=0; i<days.size(); ++i){
		int dirty = 0;
		int day = days[i];
		for (int j=lastclean+1; j<=i; ++j){
			dirty = dirty + (day - days[j]);
		}
		if (dirty < 19) {
			continue;
		} else if (dirty == 19) {
			cleans++;
			lastclean = i;
		} else {
			cleans++;
			lastclean = i-1;
		}
	}

	if (lastclean < days.size()-1) {
		cleans++;
	}

	cout << cleans << endl;

}
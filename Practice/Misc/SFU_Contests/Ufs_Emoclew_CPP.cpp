#include <iostream> // For cin, cout, and getline
#include <string> // C++ string header
#include <vector> // To store the strings
#include <algorithm> // For reverse()
using namespace std;

int main(){
	int n;
	vector<string> names;

	cin >> n;

	names.resize(n);
	getline(cin, names[0]); // Clear the end of line

	for(int i=0; i<n; ++i){
		getline(cin, names[i]);
	}

	for(int i=0; i<n; ++i){
		int j=0, k=-1;
		do{
			j = k+1;
			k = names[i].find(' ', j);
			if (k == string::npos) k = names[i].size();
			reverse(names[i].begin()+j, names[i].begin()+k);
		} while ( k != names[i].size() );
		cout << names[i] << endl;
	}
}
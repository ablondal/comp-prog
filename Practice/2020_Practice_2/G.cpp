#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;

// Done and complete

class LineColoring{
public:
	int minCost( vector <int> );
};

int LineColoring::minCost( vector <int> x ){
	int n = x.size();
	
	// Try for 2-colouring
	int min0=0, min1=0;
	for(int i=0; i<n; ++i){
		if (i%2==0 and x[i] > min0)
			min0 = x[i];
		else if (i%2==1 and x[i] > min1)
			min1 = x[i];
	}
	int twocol = min0 + min1;

	// Now for 3-colouring
	set <int> y;
	for(int i=0; i<n; ++i) y.insert( x[i] );
	
	int min23 = 1e9;
	
	for( set <int>::iterator it = y.begin(); it != y.end(); ++it ){
		int max2 = *it;
		// cout << max2 << endl;
		int DP[n][3];
		DP[0][0] = 0;
		if ( x[0] <= max2 )
			DP[0][1] = 0;
		else
			DP[0][1] = 1e9;
		DP[0][2] = x[0];
		for(int i=1; i<n; ++i){

			DP[i][0] = min(DP[i-1][1], DP[i-1][2]);

			if ( x[i] <= max2 )
				DP[i][1] = min(DP[i-1][0], DP[i-1][2]);
			else
				DP[i][1] = 1e9;

			DP[i][2] = max( min(DP[i-1][1], DP[i-1][0]), x[i] );
			// DP[i][2] = max(DP[i][2], x[i]);
		}
		// cout << DP[n-1][2] << endl;
		int mres = min( DP[n-1][0], min( DP[n-1][1], DP[n-1][2] ) );
		min23 = min( min23, mres + max2 );
	}

	int threecol = min23 + max(min0, min1);
	// cout << threecol << endl;
	// cout << twocol << endl;

	return min(twocol, threecol);
}




int main(){
	// vector <int> arr(7+9+7+8, 0);
	int x[] = {1, 10, 1, 1, 1, 1, 10};
	vector <int> arr(sizeof(x)/sizeof(x[0]));
	// cout << arr.size() << endl;
	for (int i=0; i<arr.size(); ++i){
		arr[i] = x[i];
	}
	LineColoring L;
	cout << L.minCost( arr ) << endl;
}
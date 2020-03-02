#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;

// Done, using bitmasks
// Is a good example of how to use bitmasks

int main(){
	int R, C;
	while(true){

		cin >> R >> C;
		if (R == 0 && C == 0)
			break;
		int n = C;
		int beg[R];
	
		map <int, int> xor_with;
		// These are the ints to xor with to simulate pressing
		// the tile that is the index
	
		// Define those xor_withs
		for(int i=0; i<n; ++i){
			int a = 0;
			for(int j=-1; j<2; ++j){
				if (i+j>=0 && i+j<n){
					a |= ( 1 << (i+j) );
				}
			}
			xor_with[ ( 1 << i ) ] = a;
		}
	
		// Create the initial condition
		string tmp;
		for(int i=0; i<R; ++i){
			beg[i] = 0;
			cin >> tmp;
			for(int j=0; j<C; ++j){
				
				if(tmp[j]=='X'){
					// Add the bit to the bitmask for that row
					beg[i] |= ( 1 << j );
				}
			}
		}
	
		int curr[R+1];
		int TT = 1e9;
		// For each possible configuration of pressed tiles on the
		// first row:
		for(int i=0; i < ( 1 << n ); ++i){
			// bitmask of the pressed tiles
	
			// num of tiles needed
			int T = 0;
	
			for(int l = 0; l < R; ++l){
				// Copy the tiles
				curr[l] = beg[l];
			}
	
			// Flip pressed tiles and the ones below
			for(int j=0; j<n; ++j){
				if ( i & ( 1 << j ) ){
					T++;
					// Do some bitwise xors
					curr[0] ^= xor_with[ ( 1 << j ) ];
					curr[1] ^= ( 1 << j );
				}
			}
	
			// For each row, use the one below to cancel it out
			// Don't do that for the last row
			// We put an extra row onto curr so we don't get outofbounds
			// with curr[r+2]
			for ( int r = 0; r < R-1; ++r ){
				while ( curr[r] ){ // We haven't turned off all bits
					// Get the bitmask of the right-most bit turned on
					int L = curr[r] & (-curr[r]);
					
					T++;
					// Flip tiles
					curr[r] ^= L;
					curr[r+1] ^= xor_with[L];
					curr[r+2] ^= L;
				}
			}
			
			// Check if last row is empty and tiles tapped are small
			if ( curr[R-1] == 0 && T < TT ){
				TT = T;
			}
		}
	
		if (TT != 1e9){
			cout << "You have to tap " << TT << " tiles." << endl;
		}else{
			cout << "Damaged billboard." << endl;
		}
	}

}











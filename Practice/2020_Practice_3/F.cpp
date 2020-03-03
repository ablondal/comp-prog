#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

map <char, int> val;

// Done, some disgusting code, but pretty simple
// Super inefficient longest_inc_sub, but meh its of len 52

int longest_inc_sub( vector <int> A ){
	int L[A.size()];
	int m = 0;
	for(int i=0; i<A.size(); ++i){
		int M = 1;
		for(int j=i-1; j>=0; --j){
			if (A[i]>A[j])
				M = max(M,L[j]+1);
		}
		L[i] = M;
		m = max(m, M);
	}
	return A.size() - m;
}

int main(){
	val['2'] = 0;
	val['3'] = 1;
	val['4'] = 2;
	val['5'] = 3;
	val['6'] = 4;
	val['7'] = 5;
	val['8'] = 6;
	val['9'] = 7;
	val['T'] = 8;
	val['J'] = 9;
	val['Q'] = 10;
	val['K'] = 11;
	val['A'] = 12;

	int n;
	cin >> n;
	vector <string> cards(n);
	for(int i=0; i<n; ++i){
		cin >> cards[i];
		// cout << cards[i] << endl;
	}
	// For every single possible ordering -_-
	// There are 2^4 * 4! = 384
	bool ascH, ascS, ascD, ascC;
	int vH, vS, vD, vC;
	int minv = 53;
	for(int Ord = 0; Ord < 16; ++Ord){
		// cout << Ord << endl;
		int ord = Ord;
		ascH = ord%2; ord/=2;
		ascS = ord%2; ord/=2;
		ascD = ord%2; ord/=2;
		ascC = ord%2; ord/=2;
		int vals[] = {0, 1, 2, 3};
		do {
			vH = vals[0];
			vS = vals[1];
			vD = vals[2];
			vC = vals[3];
			vector <int> c(n,0);
			for(int i=0; i<n; ++i){
				if (cards[i][1]=='h'){
					c[i] += vH*13;
					if (ascH){
						c[i] += val[cards[i][0]];
					}else{
						c[i] += 12-val[cards[i][0]];
					}
				}else if (cards[i][1]=='s'){
					c[i] += vS*13;
					if (ascS){
						c[i] += val[cards[i][0]];
					}else{
						c[i] += 12-val[cards[i][0]];
					}
				}else if (cards[i][1]=='d'){
					c[i] += vD*13;
					if (ascD){
						c[i] += val[cards[i][0]];
					}else{
						c[i] += 12-val[cards[i][0]];
					}
				}else if (cards[i][1]=='c'){
					c[i] += vC*13;
					if (ascC){
						c[i] += val[cards[i][0]];
					}else{
						c[i] += 12-val[cards[i][0]];
					}
				}
			}
			int M = longest_inc_sub( c );
			minv = min(minv, M);
		}  while ( next_permutation(vals, vals+4) );
	}
	cout << minv << endl;
}

















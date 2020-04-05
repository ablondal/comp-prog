#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
typedef vector<int> vi;
typedef vector<vi> vvi;

// Think this is completely correct ? :P

void comp(vector<bool> &A){
	for(int i=0; i<A.size(); ++i){
		A[i] = !A[i];
	}
}

void flip(vector<bool> &A){
	bool tmp;
	for(int i=0; i<A.size()/2; ++i){
		tmp = A[i];
		A[i] = A[A.size()-1-i];
		A[A.size()-1-i] = tmp;
	}
}

void compflip(vector<bool> &A){
	comp(A);
	flip(A);
}

bool check_bit(int i){
	cout << i+1 << endl;
	bool e;
	cin >> e;
	return e;
}

bool answer(vector<bool> &A){
	for(int i=0; i<A.size(); ++i){
		cout << A[i];
	}
	cout << endl;
	char ans;
	cin >> ans;
	if(ans=='N'){
		exit(0);
	}
	return true;
}

int main(){
	int T, B;
	cin >> T >> B;
	vector<bool> A;
	for(int t=1;t<=T;++t){
		A.clear();
		A.resize(B,false);
		int smpair = -1;
		int oppair = -1;
		int l=0;
		for(int i=0; i<5; ++i){
			A[l] = check_bit(l);
			A[B-1-l] = check_bit(B-1-l);
			if (smpair==-1 && A[l]==A[B-1-l]){
				smpair = l;
			}else if(oppair==-1 && A[l]!=A[B-1-l]){
				oppair = l;
			}
			++l;
		}
		if (l>=(B+1)/2){
			answer(A);
			continue;
		}
		bool op,sm;
		for(int j=0; j<14; ++j){
			if(smpair==-1){
				op = check_bit(oppair);
				op = check_bit(oppair);
				if( op != A[oppair] ){
					comp(A);
				}
			}else if(oppair==-1){
				sm = check_bit(smpair);
				sm = check_bit(smpair);
				if( sm != A[smpair] ){
					comp(A);
				}
			}else{
				op = check_bit(oppair);
				sm = check_bit(smpair);
				op = (op == A[oppair]);
				sm = (sm == A[smpair]);
				if (op && sm){
					;
				}else if (!op && sm){
					flip(A);
				}else if (op && !sm){
					compflip(A);
				}else{
					comp(A);
				}
			}
			for(int i=0; i<4; ++i){
				A[l] = check_bit(l);
				A[B-1-l] = check_bit(B-1-l);
				if (smpair==-1 && A[l]==A[B-1-l]){
					smpair = l;
				}else if(oppair==-1 && A[l]!=A[B-1-l]){
					oppair = l;
				}
				++l;
			}
			if (l>B/2){
				answer(A);
				break;
			}
		}
	}
}




















#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

map <string,int> ntone = {
	{"C",0},
	{"C#",1},
	{"D",2},
	{"D#",3},
	{"E",4},
	{"F",5},
	{"F#",6},
	{"G",7},
	{"G#",8},
	{"A",9},
	{"A#",10},
	{"B",11}
};

int main(){
	int notes;
	cin >> notes;
	string no;
	vector <int> seq1(notes);
	vector <int> seq2(notes);
	for(int i=0; i<notes; ++i){
		cin >> no;
		seq1[i] = ntone[no];
	}
	for(int i=0; i<notes; ++i){
		cin >> no;
		seq2[i] = ntone[no];
	}
	// Test Transposition
	bool T = true;
	for(int i=0;i<12;++i){
		T = true;
		for(int j=0; j<notes; ++j){
			if( (seq1[j]+i)%12 != seq2[j] ){
				T = false;
				break;
			}
		}
		if (T){
			cout << "Transposition" << endl;
			return 0;
		}
	}

	// Test Retrograde
	bool R = true;
	for(int i=0; i<notes; ++i){
		if (seq1[i] != seq2[notes-1-i]){
			R = false;
			break;
		}
	}
	if (R){
		cout << "Retrograde" << endl;
		return 0;
	}

	// Test Inversion

	bool I = true;
	for(int i=0; i<notes; ++i){
		if ( (seq1[0]-seq1[i]+12)%12 != (seq2[i]-seq2[0]+12)%12 ){
			I = false;
			break;
		}
	}
	if (I){
		cout << "Inversion" << endl;
		return 0;
	}

	cout << "Nonsense" << endl;
}













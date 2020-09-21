#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>
using namespace std;
typedef vector<int> vi;

string ABO[9] = {"A", "AB", "A", "AB", "B", "B", "A", "B", "O"};
// ABOrh

string to_s(int bl){
	string S = ABO[bl / 4];
	if (bl % 4) S += "+";
	else S += "-";
	return S;
}

string set_to_s(set <string> n, string nn){
	if (nn != "?") return nn;
	if (n.size() == 0) return "IMPOSSIBLE";
	if (n.size() == 1) return *(n.begin());
	string S = "{";
	for(string s : n){
		S += s + ", ";
	}
	S = S.substr(0, S.size()-2) + "}";
	return S;
}

bool can_succeed(int a, int b, int c){
	int cr[2] = {c%2, (c/2)%2};
	int ca[2] = {(c/4)%3, (c/12)};

	int ar[2] = {a%2, (a/2)%2};
	int aa[2] = {(a/4)%3, (a/12)};

	int br[2] = {b%2, (b/2)%2};
	int ba[2] = {(b/4)%3, (b/12)};

	bool rG = false;
	bool aboG = false;
	for(int i=0; i<4; ++i){
		if ((ar[i%2] == cr[0] && br[i/2] == cr[1]) ||
			(ar[i%2] == cr[1] && br[i/2] == cr[0]) )
		{
			rG = true;
		}
		if ((aa[i%2] == ca[0] && ba[i/2] == ca[1]) ||
			(aa[i%2] == ca[1] && ba[i/2] == ca[0]) )
		{
			aboG = true;
		}
	}
	return aboG && rG;
}

int main(){
	string a, b, c;
	int C = 0;
	while(true){
		cin >> a >> b >> c;
		if (a == "E") break;
		C++;
		vi av, bv, cv;
		for(int i=0; i<4*9; ++i){
			if (a == "?" || to_s(i) == a) av.push_back(i);
			if (b == "?" || to_s(i) == b) bv.push_back(i);
			if (c == "?" || to_s(i) == c) cv.push_back(i);
		}
		set <string> as, bs, cs;
		for(int aa : av){
			for(int bb : bv){
				for(int cc : cv){
					if (can_succeed(aa, bb, cc)){
						as.insert(to_s(aa));
						bs.insert(to_s(bb));
						cs.insert(to_s(cc));
					}
				}
			}
		}
		cout << "Case " << C << ": " << set_to_s(as, a) << " " << set_to_s(bs, b) << " " << set_to_s(cs, c) << endl;
	}
}













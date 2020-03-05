#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

bool isSubSeq(string a, string b){
	// tests if b is a substring of a
	int ai = 0;
	int bi;
	for(bi=0; bi<b.size(); ++bi){
		while(a[ai]!=b[bi] && ai<a.size()){
			ai++;
		}
		if (ai==a.size()){
			 // cout << b << " is not a substr of " << a << endl;
			return false;
		}
		ai++;
	}

	// cout << b << " is a substr of " << a << endl;
	return true;
}


int main(){
	int n;
	string root;
	cin >> n;
	cin >> root;
	vector <string> seqs(n);
	for(int i=0; i<n; ++i){
		cin >> seqs[i];
	}
	sort(seqs.begin(), seqs.end(), [](string a, string b){return a.size()>b.size();});
	
	int state = 0;
	// 0 means working as usual with two ends
	// 1 means that there's a third loose end
	// add on to third loose end if possible
	vector <int> a, b, c;
	string A, B, C;
	A = root;
	B = root;
	string N;
	if (isSubSeq(root,seqs[0])){
		a.push_back(0);
		A = seqs[0];
	}else{
		cout << "impossible" << endl;
		return 0;
	}
	for(int i=1; i<n; ++i){
		N = seqs[i];
		// cout << N << " " << state << endl;
		if (state == 0){
			if (isSubSeq(A,N)){
				// N can go on the first end
				if (isSubSeq(B,N)){
					// Also on the second one
					state = 1;
					c.push_back(i);
					C = N;
				}else{
					a.push_back(i);
					A = N;
				}
			}else if (isSubSeq(B,N)){
				// N can go only on second end
				b.push_back(i);
				B = N;
			}else{
				cout << "impossible" << endl;
				return 0;
			}
		}else{
			// state is 1, test first for attachment to third end
			if (isSubSeq(C,N)){
				c.push_back(i);
				C = N;
			}else{
				if (isSubSeq(B,N)){
					state = 0;
					for(int j=0; j<c.size(); ++j){
						a.push_back(c[j]);
					}
					A = C;
					c.clear();
					b.push_back(i);
					B = N;
				}else if (isSubSeq(A,N)){
					state = 0;
					for(int j=0; j<c.size(); ++j){
						b.push_back(c[j]);
					}
					B = C;
					c.clear();
					a.push_back(i);
					A = N;
				}else{
					cout << "impossible" << endl;
					return 0;
				}
			}
		}
	}
	if (state==1){
		for(int j=0; j<c.size(); ++j){
			a.push_back(c[j]);
		}
	}
	cout << a.size() << " " << b.size() << endl;
	for(int i=a.size()-1; i>=0; --i){
		cout << seqs[a[i]] << endl;
	}
	for(int i=b.size()-1; i>=0; --i){
		cout << seqs[b[i]] << endl;
	}

}













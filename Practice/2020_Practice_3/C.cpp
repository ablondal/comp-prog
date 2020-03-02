#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// DFS and all loops is far too slow

int main(){
	int n;
	cin >> n;
	vector <string> file_names(n);
	map <string, int> file_indices;
	for(int i=0; i<n; ++i){
		cin >> file_names[i];
		file_indices[file_names[i]] = i;
	}

	vector <int> imps[n];

	int k;
	string tmp, tmp2;
	for(int i=0; i<n; ++i){
		cin >> tmp;

		for( cin >> k; k>0; --k){
			cin >> tmp;
			do{
				cin >> tmp;
				if (tmp[tmp.size()-1]==','){
					tmp2 = tmp.substr(0,tmp.size()-1);
				}else{
					tmp2 = tmp;
				}
				imps[i].push_back(file_indices[tmp2]);
			}while( tmp[tmp.size()-1] == ',' );
		}
	}
	// for(int i=0; i<n; ++i){
	// 	cout << file_names[i] << ":";
	// 	for(int j=0; j<imps[i].size(); ++j){
	// 		cout << " " << file_names[imps[i][j]];
	// 	}
	// 	cout << endl;
	// }

	// Now, detect cycles, and store the smallest
	int smallest_cycle = 1e9;
	vector <int> cyc;

	vector <bool> V(n,false);
	vector <bool> v(n,false);

	vector <int> dep(n,0);
	int S[n+2];
	int I[n+2];
	int ss=0;

	for(int i=0; i<n; ++i){
		if (V[i]) continue;
		V[i] = true;
		ss = 0;
		S[0] = i;
		I[0] = 0;
		v.clear();
		v.resize(n,false);
		v[i] = true;

		while(ss>-1){
			int curnode = S[ss];

			// for(int x=0; x<=ss; ++x){
			// 	cout << S[x] << " ";
			// }
			// cout << endl;
			
			if (imps[curnode].size() == I[ss]){
				v[curnode] = false;
				ss--;
			}else{
				S[ss+1] = imps[curnode][I[ss]];
				I[ss]++;
				I[ss+1] = 0;
				ss++;
				if (v[S[ss]]){
					// cout << "Found cycle" << endl;
					//int b = ss-1;
					int b = dep[S[ss]];
					// Get cycle len
					//while(S[b]!=S[ss]) b--;
					// If cycle len is min
					if (ss-b < smallest_cycle){
						smallest_cycle = ss-b;
						cyc.clear();
						while(b!=ss){
							cyc.push_back(S[b]);
							b++;
						}
					}
					ss--;
					// cout << "evaled cycle" << endl;
				}
				v[S[ss]] = true;
				dep[S[ss]] = ss;
			}
		}
	}

	if (smallest_cycle < 1e8){
		for(int i=0; i<cyc.size(); ++i){
			if (i!=0) cout << " ";
			cout << file_names[cyc[i]];
		}
		cout << endl;
	}else{
		cout << "SHIP IT" << endl;
	}


}














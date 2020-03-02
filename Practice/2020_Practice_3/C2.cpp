#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Trying C again but with depth-limited DFS

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

	// Now, detect cycles, and store the first we get

	vector <int> cyc;
	vector <bool> V(n, false);

	for(int M_dep = 1; M_dep <= n && cyc.size()==0; ++M_dep ){

		for(int i=0; i<n && cyc.size()==0; ++i){
			V.clear();
			V.resize(n, false);
			V[i] = true;
			int S[n+2];
			int I[n+2];
			int ss=0;

			S[ss] = i;
			I[ss] = 0;
			while(ss>-1){
				int C = S[ss];
				if ( imps[C].size() == I[ss] ){
					V[C] = false;
					ss--;
				}else{
					S[ss+1] = imps[C][I[ss]];
					I[ss]++;
					I[ss+1] = 0;
					ss++;
					if (S[0]==S[ss]){
						for(int i=0; i<ss; ++i){
							cyc.push_back(S[i]);
						}
						break;
					}
					if (ss==M_dep){
						ss--;
					}
					V[S[ss]] = true;
				}
			}


		}
	}

	if (cyc.size() != 0){
		for(int i=0; i<cyc.size(); ++i){
			if (i!=0) cout << " ";
			cout << file_names[cyc[i]];
		}
		cout << endl;
	}else{
		cout << "SHIP IT" << endl;
	}


}














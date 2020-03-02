#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Trying C again but with BFS
// Done, this time it worked

int main(){
	int n;
	cin >> n;
	vector <string> file_names(n);
	map <string, int> file_indices;
	for(int i=0; i<n; ++i){
		cin >> file_names[i];
		file_indices[file_names[i]] = i;
	}

	vector <int> G[n];

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
				G[i].push_back(file_indices[tmp2]);
			}while( tmp[tmp.size()-1] == ',' );
		}
	}

	// Now, detect cycles, and store the first we get

	vector <int> cyc(501,0);
	vector <int> tmpcyc;
	vector <bool> V(n, false);
	vector <int> parent(n);
	int Q[1001];
	int qa, qb; // qa is the top element
	// qb is the index of the next empty space

	for(int R=0; R<n; ++R){
		qa = qb = 0;
		Q[qb++] = R;
		V.clear();
		V.resize(n, false);
		V[R] = true;
		parent[R] = -1;
		tmpcyc.clear();

		while(qa!=qb){
			int C = Q[qa++];
			for(int i=0; i<G[C].size(); ++i){
				if ( !V[ G[C][i] ] ){
					// If not already visited
					parent[ G[C][i] ] = C;
					V[ G[C][i] ] = true;
					Q[qb++] = G[C][i];
				}else if ( G[C][i] == R ){
					parent[R] = C;
					qa = qb;
					break;
				}
			}
		}
		// cout << parent[R] << endl;
		if (parent[R] != -1){
			int P = parent[R];
			while(P!=R){
				tmpcyc.push_back(P);
				P = parent[P];
			}
			tmpcyc.push_back(R);
			if (tmpcyc.size() < cyc.size()){
				// cout << tmpcyc.size() << " is a size" << endl;
				cyc.clear();
				cyc.assign(tmpcyc.begin(), tmpcyc.end());
			}
		}

	}

	if (cyc.size() != 501){
		for(int i=cyc.size()-1; i>=0; --i){
			if (i!=cyc.size()-1) cout << " ";
			cout << file_names[cyc[i]];
		}
		cout << endl;
	}else{
		cout << "SHIP IT" << endl;
	}


}














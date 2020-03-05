#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// Done!
// Use 0 and 2 routes for restrictions
// Do bipartite checking, and make sure that there are no conflicting restrictions
// Then for each bipartite part of the graph, choose the side with lowest amount
// restriction checking makes this code long, with several failure cases

int main(){
	int n, m;
	int a, b, c;
	cin >> n >> m;
	vector <int> state (n+1, 0);
	vector <int> G[n+1];
	for(int i=0; i<m; ++i){
		cin >> a >> b >> c;
		if (c==2){
			if (state[a]!=-1 && state[b]!=-1){
				state[a] = 1;
				state[b] = 1;
			}
			else{
				cout << "impossible" << endl;
				return 0;
			}
		}else if (c==0){
			if (state[a]!= 1 && state[b]!= 1){
				state[a] = -1;
				state[b] = -1;
			}
			else{
				cout << "impossible" << endl;
				return 0;
			}
		}else{
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
	// for(int i=1; i<n+1;++i){
	// 	for(int j=0;j<G[i].size();++j){
	// 		cout << G[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	vector <bool> v(n+1);
	vector <bool> D(n+1,0);
	int n_lounge = 0;
	// Now do BFS on each connected component, checking if graph is bipartite
	// Failure if any graph isn't bipartite
	// Failure if a layer is assigned opposite values from state!
	for(int i=1; i<=n; ++i){
		// Don't revisit explored nodes
		if (v[i]) continue;
		// s is state, -1 if layer 1 is 0, 1 if layer1 is 1
		// l1 and l2 count num of 
		int s=0, l1=0, l2=0;
		
		// Create BFS queue:
		queue <int> Q;
		Q.push(i);
		Q.push(-1);

		int dep = 0;
		while(Q.size()>1){
			// Current node
			int C = Q.front();
			Q.pop();
			if (C==-1){
				dep++;
				dep %= 2;
				Q.push(-1);
			}else if ( !v[C] ){
				// Put all children on
				for(int j=0; j<G[C].size(); ++j){
					Q.push( G[C][j] );					
				}
				// Set self as visited
				v[C] = true;
				// Set self's depth
				D[C] = dep;
				// increment l1, l2
				if (dep==0) l1++;
				else l2++;
			}else{
				// Has been visited before, check that vars are ok
				// Bipartite check:
				if (D[C] != dep){
					cout << "impossible" << endl;
					return 0;
				}
			}

			// Now check that states are properly set
			// Skip if there is no restriction at this node
			if ( state[C]==0 ) continue;
			if ( s == 0 ){
				// If this is the first restricted node
				if ( dep == 0 ){
					s = state[C];
				}else{
					s = -1*state[C];
				}
			}else{
				int mult;
				if ( dep == 0 ){
					mult = 1;
				}else{
					mult = -1;
				}

				if ( mult*state[C] != s ){
					cout << "impossible" << endl;
					// cout << C << " " << dep << " " << s << endl;
					return 0;
				}
			}
		}

		if (s==0){
			n_lounge += min(l1, l2);
		}else if (s==1){
			n_lounge += l1;
		}else{
			n_lounge += l2;
		}
	}

	cout << n_lounge << endl;
}
























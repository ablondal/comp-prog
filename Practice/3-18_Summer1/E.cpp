#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <unordered_map>
using namespace std;
#define MAXS 100005
int A[MAXS];
int S[MAXS];
int SUM[MAXS];
/*
int add(vector<pair <int,int> > &addto,int x){
	
	int i = addto.size();
	if(i){
		i/=2;
	}else{
		addto.push_back(make_pair(x,1));
		return 1;
	}
	while(1){
		if(addto[i]!=)
	}
}*/

int main(){
	int n,m,q,g,x,y;
	char tmp;
	unordered_map <int,int> curradd;
	vector<vector <int> > LoV;//The lists of villas
	vector<vector <int> > VsL;//The lists each villa is in
	//vector <vector <pair <int,int> > > villagraph;
	unordered_map <int, vector< pair <int, int> > > already;
	unordered_map <int, vector< pair <int, int> > >::iterator it;
	ios::sync_with_stdio(false);
	vector <pair <int, int> > *poi;
	while(cin >> n){
		already.clear();
		VsL.resize(n+1);
		cin>>m>>q;
		LoV.resize(m+1);
		for(int i=1;i<=n;++i){
			cin >> A[i];

			VsL[i].clear();
		}
		for(int i=1;i<=m;++i){
			cin >> S[i];

			SUM[i]=0;
			LoV[i].resize(S[i]);
			for(int j=0;j<S[i];++j){
				cin >> LoV[i][j];

				SUM[i]+=A[LoV[i][j]];
				VsL[LoV[i][j]].push_back(i);
			}
		}

		for(int Q=0;Q<q;++Q){
			cin >> tmp;
			if(tmp=='?'){
				cin >> x;
				cout << SUM[x] <<endl;
			}else{
				cin >> x>>y;
				it = already.find(x);
				if(it!=already.end()){
					poi = &(it->second);
					for(int i=0;i<poi->size();++i){
						SUM[(*poi)[i].first]+= y * (*poi)[i].second;
					}
					continue;
				}
				poi = &(already[x]);
				curradd.clear();
				for(int i=0;i<S[x];++i){//for villa LoV[x][i]
					for(int j=0;j<VsL[LoV[x][i]].size();++j){//for villalist VsL[LoV[x][i]][j]
						int h = VsL[LoV[x][i]][j];
						SUM[h]+=y;//oh god pls work
						if(curradd.find(h)==curradd.end()) curradd[h]=0;
						curradd[h]++;
					}
				}
				for(unordered_map<int,int>::iterator ii=curradd.begin();ii!=curradd.end();++ii){
					poi->push_back(make_pair(ii->first,ii->second));
				}
			}
		}
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
	int f=0,l=0;
	int n,m,a,b;
	
	//bool nofoes = true;
	cin >> n >> m;
	long long totpairs=n;
	vector <int> perm;
	vector <int> passed;
	unordered_set <int> lookout;
	vector <unordered_set <int> > pairs;
	perm.resize(n);
	passed.resize(n,0);
	pairs.resize(n+1);
	//cout << "wtf"<<endl;
	for(int i=0;i<n;++i){
		cin >> perm[i];
	}
	for(int i=0;i<m;++i){
		cin >> a >> b;
		/*bool contains = false;
		for(int j=0;j<pairs[a].size();++j){
			if(pairs[a][j]==b){
				contains = true;
				break;
			}
		}*/
		//if(contains){continue;}
		pairs[a].insert(b);
		pairs[b].insert(a);
	}
	/*
	for(int i=0;i<pairs.size();++i){
		cout << i << ": ";
		for(int j=0;j<pairs[i].size();++j){
			cout << pairs[i][j] << ' ';
		}
		cout << endl;
	}*/
	bool done;
	while(l<n-1){
		//cout << "L is at "<<l<<endl;
		l++;
		//cout << f << ' ' << l <<endl;
		done = 0;
		unordered_set<int>::iterator it;
		it = lookout.find(perm[l]);
		if(it!=lookout.end()){
			//lookout.erase(it);
			//cout << "looking" <<endl;
			lookout.clear();
			a = perm[l];
			for(int j=l-1;j>=f;j--){
				if(pairs[a].find(perm[j])!=pairs[a].end()){
					f = j+1;
					break;
				}
				else{
					lookout.insert(pairs[perm[j]].begin(),pairs[perm[j]].end());
				}
				//if(done) break;
			}
		}
		lookout.insert(pairs[perm[l]].begin(),pairs[perm[l]].end());
		/*for(auto &x : lookout){
			cout << " " << x;
		}
		cout << endl;*/
		totpairs += l - f;
		
	}
	cout << totpairs << endl;
}
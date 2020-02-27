//FUCKING USE SETS
//AND FUCKING USE LONG LONG OH MY GOD 
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int main(){
	vector <int> sett;
	vector <long long> sum;
	vector <set <int> > elements;
	int n,m,a,b,c;
	int tb,tc;

	while(cin >> n){
		cin>>m;
		sett.clear();
		sum.clear();
		elements.clear();
		sett.resize(n+1);
		sum.resize(n+1);
		elements.resize(n+1);
		for(int i=1;i<=n;++i){
			sett[i]=i;
			sum[i]=i;
			elements[i].insert(i);
		}
		for(int j=0;j<m;++j){
			cin >> a;
			if(a==1){
				cin >> b >> c;
				if(sett[b]==sett[c]){
					continue;
				}
				if(elements[sett[b]].size() < elements[sett[c]].size()){
					tb = b;
					b = c;
					c = tb;
				}
				tb = sett[b];
				tc = sett[c];
				for(set<int>::iterator it=elements[tc].begin();it!=elements[tc].end();++it){
					sett[*it] = tb;
				}
				sum[tb]+=sum[tc];
				sum[tc]=0;
				elements[tb].insert(elements[tc].begin(),elements[tc].end());
				elements[tc].clear();
			}else if(a==2){
				cin >> b >> c;
				if(sett[b]==sett[c]){continue;}
				sum[sett[b]] -= b;
				/*for(int i=0;i<elements[sett[b]].size();++i){
					if(elements[sett[b]][i]==b){
						elements[sett[b]].erase(elements[sett[b]].begin()+i);
					}
				}*/
				elements[sett[b]].erase(b);
				elements[sett[c]].insert(b);
				sum[sett[c]]+=b;
				sett[b] = sett[c];
			}else{
				cin >> b;
				cout << elements[sett[b]].size() << ' ' << sum[sett[b]] << endl;
			}
		}
	}

	return 0;
}
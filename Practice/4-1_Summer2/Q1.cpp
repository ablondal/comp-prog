#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> numq; //number of questions at index i
vector <int> tolearn; //how much we should learn
vector <int> position; //position

bool lessthan(int i,int j) {
	return numq[i]<numq[j];
}



int main(){
	int T;
	
	for(cin>>T;T>0;T--){
		int k,n,tmp;
		cin >> k >>n;
		numq.clear();
		tolearn.clear();
		position.clear();
		numq.resize(n+1);
		position.resize(n+1);
		tolearn.resize(n+1,0);
		numq[0]=0;
		position[0]=0;
		for(int i=1;i<=n;++i){
			position[i]=i;
			cin >> numq[i];
		}
		sort(position.begin()+1,position.end(),lessthan);
		

		int i=1;
		while(k!=0){
			//cout << "k " << k<<endl;
			if(k>numq[position[i]]){
				k -= numq[position[i]];
				tolearn[position[i]] = numq[position[i]];
			}else{
				tolearn[position[i]] = k;
				k=0;
			}
			++i;
		}

		for(int j=1;j<=n;++j){
			if(j!=1) cout << ' ';
			cout << tolearn[j];
		}
		cout << endl;
	}
}








//rewriting cause wow I fucked it up first time LOL
//FUCKING USE SETS
//AND FUCKING USE LONG LONG OH MY GOD 
#include <iostream>
//#include <vector>
using namespace std;

//typedef vector <int> vi;

int tree[100001];
int leaf[100001];
long long sum[100001];
int num[100001];

int root(int x){
	if(tree[x]==x) return x;
	int y = root(tree[x]);
	tree[x] = y;
	return y;
}

int main(){
	int n,m,tmp,p,q,a,b;
	int currs;
	while (cin>>n>>m){
		//cin>>m;
		for(int i=1;i<n+1;++i){
			tree[i] = i;
			sum[i] = i;
			leaf[i] = i;
			num[i] = 1;
		}
		for(int M=0;M<m;++M){
			cin>>tmp;
			if(tmp==1){
				cin >>p>>q;
				if(p==q)continue;
				a = root(leaf[p]);
				b = root(leaf[q]);
				if(a==b)continue;
				tree[a] = b;
				sum[b]+=sum[a];
				num[b]+=num[a];
			}else if(tmp==2){
				cin >>p>>q;
				if(p==q)continue;
				a = root(leaf[p]);
				b = root(leaf[q]);
				if(a==b)continue;
				sum[a]-=p;
				num[a]--;
				leaf[p] = b;
				sum[b]+=p;
				num[b]++;
			}else{
				cin>>p;
				a = root(leaf[p]);
				cout << num[a] << ' '<<sum[a]<<endl;
			}
		}
	}
}
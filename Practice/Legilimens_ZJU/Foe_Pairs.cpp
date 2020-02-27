#include <iostream>
using namespace std;

int perm[300005];
int pos[300005];
int last[300005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long sum=0;
	int n,m,a,b,pa,pb;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin >> perm[i];
		pos[--perm[i]] = i;
		last[i]=n;
	}
	for(int i=0;i<m;++i){
		cin >> a>>b;
		pa = pos[a-1];pb = pos[b-1];
		if(pb<pa){
			if(last[pb]>pa){
				last[pb]=pa;
			}
		}else{
			if(last[pa]>pb){
				last[pa]=pb;
			}
		}
	}
	int left=n-1,right=n;
	for(left = n-1;left>-1;--left){
		if(right > last[left]){
			right = last[left];
		}
		sum += right-left;
	}
	cout << sum << endl;
}

//1 2 3 4 5 6 7 8 9
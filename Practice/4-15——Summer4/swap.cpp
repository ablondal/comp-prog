#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> num;
vector <int> swaps;

int findMax(){
	int m = 0;
	int max = 0;
	int t;
	for(int i=0;i<5;++i){
		max*=10;
		max+= num[i];
	}
	for(int i=0;i<5;i++){
		if(num[i]==0)
			continue;
		m = 0;
		for(int j=i+1;j<5;++j){
			if(num[j]>m)
				m=num[j];
		}
		if(m>num[i]+1){
			for(int j=i+1;j<5;++j){
				if(num[j]==m){
					t = num[j];
					num[j] = num[i];
					num[i] = t;
					t = swaps[j] + 1;
					swaps[j] = swaps[i] + 1;
					swaps[i] = t;
					t = findMax();
					if(t>max)
						max = t;
					t = num[j];
					num[j] = num[i];
					num[i] = t;
					t = swaps[j] - 1;
					swaps[j] = swaps[i] - 1;
					swaps[i] = t;
				}
			}
		}
	}
	return max;
}
/*
void findTwo(){
	int t,m;
	for(int i=0;i<5;i++){
		if(num[i]==0)
			continue;
		m = 0;
		int l = 0;
		for(int j=i+1;j<5;++j){
			if(num[j]>=m){
				m=num[j];
				l = j;
			}
		}
		if(m>num[i]+1){
			t = num[l];
			num[l] = num[i];
			num[i] = t;
			t = swaps[l] + 1;
			swaps[l] = swaps[i] + 1;
			swaps[i] = t;
		}
		if(m>num[i]+1){
			for(int j=i+1;j<5;++j){
				if(num[j]>1){
					t = num[j];
					num[j] = num[i];
					num[i] = t;
					t = swaps[j] + 1;
					swaps[j] = swaps[i] + 1;
					swaps[i] = t;
					t = findMax();
					if(t>max)
						max = t;
					t = num[j]+1;
					num[j] = num[i]+1;
					num[i] = t;
				}
			}
		}
	}
}
*/
int main(){
	int T;
	int n;
	//vector <int> num(5,0);
	for(cin>>T;T>0;--T){
		cin>>n;
		num.clear();
		num.resize(5,0);
		swaps.clear();
		swaps.resize(5,0);
		if(n==100000){
			cout << "100000"<<endl;
			continue;
		}
		int i=4;
		while(n>0){
			num[i] =  n%10;
			n/=10;
			i--;
		}
		//findTwo();
		bool canswap[5];
		for(int i=0;i<5;++i){
			if(swaps[i])
				canswap[i]=true;
		}
		sort(swaps.begin(),swaps.end());
		int max = findMax();
		for(int i=4;i>=0;++i){
			num[i] =  max%10;
			max/=10;
			//i--;
		}
		int j = 4;
		while(swaps[j]){
			for(int i=4;i>=0;--i){
				if(canswap[i] && num[i]>=swaps[j]){
					num[i]-=swaps[j];
					canswap[i] = false;
					break;
				}
			}
			j--;
		}
		max = 0;
		for(int i=0;i<5;++i){
			max*=10;
			max+= num[i];
		}
		cout << max << endl;
	}
}
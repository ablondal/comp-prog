#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

int main(){
	int s,t,n;
	cin >> s >> t >> n;

	int wt[n];
	int br[n];
	int in[n];
	int orwal;
	cin >> orwal;
	s += orwal;
	for(int i=0;i<n;++i){
		cin>>wt[i];
	}
	for(int i=0;i<n;++i){
		cin>>br[i];
	}
	for(int i=0;i<n;++i){
		cin>>in[i];
	}
	int c_time = s;
	for(int i=0;i<n;++i){
		c_time = ceil( (double)c_time/(double)in[i] )*in[i];
		c_time += br[i];
		c_time += wt[i];
	}
	if(c_time<=t) cout << "yes" << endl;
	else cout << "no" << endl;

}
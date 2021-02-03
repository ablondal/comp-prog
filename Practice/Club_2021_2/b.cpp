#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char a[1000], b[1000];
double prob[30];


int main() {
	scanf(" %s %s", a, b);
	rep(i,0,30) prob[i] = 0;
	prob[15] = 1;
	int p = 15;
	int i=0;
	while(a[i]){
		if (a[i]=='+') p++;
		else p--;
		if (b[i]=='+'){
			for(int j=29; j>0; --j){
				prob[j] = prob[j-1];
			}
		}else if (b[i]=='-'){
			for(int j=0; j<29; ++j){
				prob[j] = prob[j+1];
			}
		}else{
			double newprob[30] = {0};
			for(int j=1; j<29; ++j){
				newprob[j] = 0.5*prob[j-1] + 0.5*prob[j+1];
			}
			rep(j,0,30) prob[j] = newprob[j];
		}
		i++;
	}
	printf("%.12lf\n", prob[p]);
}
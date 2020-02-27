#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);
const double EPS = 1e-9;
const double pi = acos(-1);
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int min(int a, int b){
	return a<b ? a : b;
}

typedef struct tt{
	int two;
	int three;
	tt(): two(0), three(0){}
	void operator+=( struct tt a ){
		two += a.two;
		three += a.three;
	}
	void operator=( struct tt a ){
		two = a.two;
		three = a.three;
	}
} tt;

tt max( tt a, tt b, tt c, tt d, bool istwo){
	if(istwo){
		
	}
}

void factorize(int a, tt& b)
{
	while(a%2==0){
		a/=2;
		b.two++;
	}
	while(a%3==0){
		a/=3;
		b.three++;
	}
}

int main(){
	int T;
	for(cin>>T; T>0; --T)
	{
		int N,M, tmp;
		cin >> N >> M;
		tt a[N][M];
		tt b[N][M];
		tt tmp2, tmp3;
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				cin >> tmp;
				factorize(tmp, a[i][j]);
				factorize(tmp, b[i][j]);
				if(j==0 && i==0)
				if(j==0 && i!=0) a[i][j]+=a[i-1][j];
				else if(i==0 && j!=0)
				if(i>0) a[i][j]+=a[i-1][j];
			}
		}
		cout << min(a[N-1][M-1].two, a[N-1][M-1].three) << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b){
	return a<b ? a : b;
}

int max( int a, int b){
	return a>b ? a : b;
}

void factorize(int a, int& t2, int& t3)
{
	t2 = 0; t3 = 0;
	while(a%2==0){
		a/=2;
		t2++;
	}
	while(a%3==0){
		a/=3;
		t3++;
	}
}

int main(){
	int T;
	for(cin>>T; T>0; --T)
	{
		int N,M, tmp, tmp1, tmp2;
		cin >> N >> M;
		int a[N][M][2000];
		for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) for(int k=0; k<2000; ++k) a[i][j][k]=-1;
		
		int twos, threes;
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				cin >> tmp;
				factorize(tmp, twos, threes);
				if(i==0 && j==0){
					a[i][j][twos] = threes;
					continue;
				}
				for(int k=twos;k<2000;++k){
					if(i==0) tmp2 = -1;
					else tmp2 = a[i-1][j][k-twos];

					if(j==0) tmp1 = -1;
					else tmp1 = a[i][j-1][k-twos];
					
					//cout << i << j << k << ' ' << tmp1 << ' ' << tmp2 << endl;

					tmp = max (tmp1, tmp2);
					if(tmp!=-1) a[i][j][k] = tmp + threes;
					else a[i][j][k] = -1;
					//cout << i << j << k << ' ' << a[i][j][k] << endl;
				}
				
			}
		}
		int m = 0;
		for(int k=0; k<2000; ++k){
			m = max( m, min( k, a[N-1][M-1][k] ) );
			//cout << a[N-1][M-1][k] << endl;
		}
		cout << m << endl;
	}
	return 0;
}
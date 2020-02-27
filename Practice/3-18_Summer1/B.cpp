#include <iostream>

using namespace std;
typedef long long ll;

long long euclid(long long a,long long b){
	if(a==0){
		return b;
	}else{
		return euclid(b%a,a);
	}
}

long long subtract(ll a,ll b,ll x,ll y,ll &l,ll &m){
	l = a*y - b*x;
	m = b*y;
	long long e = euclid(l,m);
	l/=e;
	m/=e;
	return 0;
}

int main(){
	long long a,b,T,e;
	long long x,y,l,m;
	int n;
	for(cin>>T;T>0;--T){
		n = 0;
		cin>>a>>b;
		e = euclid(a,b);
		b/=e;
		a/=e;
		x = 1;
		y = 1;
		n = 1;
		int bb = b;
		while(bb%2==0){
			bb/=2;
			n++;
		}
		if(bb!=1){
			cout << "-1"<<endl;
			continue;
		}
		n = 0;
		while(n<41){
			n++;
			subtract(a,b,x,y,l,m);
			if(l<0 || l>m){
				y*=2;
				x*=2;
				
				if(a*y>b*x) x++;
				else x--;
				continue;
			}
			cout << n-1 << endl;
			break;
		}
	}
}
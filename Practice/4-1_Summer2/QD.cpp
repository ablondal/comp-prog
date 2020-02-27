#include <iostream>
#include <string>
#include <vector>
#include <string>
#define mod 10e9+7
using namespace std;
short digits[100005];
long long MOD;
long long numerator(int n, int k, int p) {
    long long l = 1;
    for(int j = k+1; j <= n; j++) {
        l = (l*j)%p;
    }
    return l;
}
long long denominator(int n, int k, int p) {
    long l = 1;
    for(int j = 2; j <= n-k; j++) {
        l = (l*j)%p;
    }
    return l;
}
long long pow(long long a, int k, int p) {
    if(k == 0) {
        return 1;
    }
    long long r = pow((a*a)%p,k>>0x01,p);
    if((k&0x01) == 0x01) {//odd number
        r = (r*a)%p;
    }
    return r;
}
long long N_choose_K(int n, int k, int p) {
    long long num = numerator(n,k,p);
    long long den = denominator(n,k,p);
    return (num*pow(den,p-2,p))%p;
}
/*
long long choose(int c, int n){
	
	long long tot = 1;
	for(int i=n+1;i<c+1;++i){
		tot*=i;
		tot%=MOD;
	}
	for(int i=1;i<c-n+1;++i){
		tot/=i;
	}
	return tot;
}*/

int main(){
	MOD = mod;
	vector <long long> last;
	string converter;
	long long lastest;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	long long sum;
	for(cin>>T;T>0;--T){
		int n,k;
		sum=0;
		cin >> n>>k;
		//digits.resize(n);
		last.clear();
		last.resize(n-k);
		cin >> converter;
		for(int i=0;i<n;++i){
			digits[i] = converter[i] - '0';
		}
		last[0] = N_choose_K(n-1,k,MOD);
		//cout << "here"<<endl;
		int l=0;
		int i=n-1;
		lastest=0;
		if(last[0]==1){
			lastest = 1;
		}	
		while(i!=-1){
			if(i==n-1){
				sum+= 1 * digits[i] * last[0];
			}else if(!lastest){
				//i = n-l-2
				//last[l+1] = N_choose_K(n-l-2,k,MOD);
				//last[l] = N_choose_K(n-l-2,k-1,MOD);
				last[l+1] = ((i-k+1)*last[l]*pow(i,MOD-2,MOD))%MOD;
				last[l] = (k*last[l]*pow(i,MOD-2,MOD))%MOD;
				l++;
				int t = 1;
				for(int j=0;j<=l;++j){
					sum += t * digits[i] * last[j];
					sum %= MOD;
					t*=10;
					t%=MOD;
				}
				if(last[l]<2){
					//last[l] = k*last[l]/n-l-2;
					int t = 1;
					for(int j=0;j<=l;++j){
						//t*=10;
						lastest+=t * last[j];
						lastest%=MOD;
						t*=10;
						t%=MOD;
					}
				}
			}else{
				sum += digits[i]*lastest;
				sum %=MOD;
			}
			//cout << i << ": sum: " << sum << " l: "<<l<<" last[l]: "<<last[l] << endl;
			i--;
		}
		cout << sum << endl;
	}
}


















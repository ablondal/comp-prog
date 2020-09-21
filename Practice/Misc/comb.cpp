#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 10000;
const int m = 1e9+7;

ll fac[N] = {0};
ll choose[N][N] = {{0}};


int main(){
	cout << "hi" << endl;
	fac[0] = 1;
	for(int i=1; i<N; ++i){
		fac[i] = (i * fac[i-1]) % m;
	}
	cout << fac[4] << endl;
	cout << fac[100] << endl;


	for(int i=0; i<N; ++i){
		choose[i][0] = choose[i][i] = 1;
		for(int j=1; j<i; ++j){
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
			choose[i][j] %= m;
		}
	}

	cout << choose[100][100] << endl;
	cout << choose[5][2] << endl;
	cout << choose[100][30] << endl;

	int n = N;
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	vector<int> primes;
	for (int i = 2; i <= n; i++) {
	    if (!is_prime[i]) continue;
	    primes.push_back(i);
	    if ((ll)i * i <= n) {
	        for (int j = i*i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}

	cout << primes[40] << endl;
	cout << (is_prime[4004] ? '1' : '0') << endl;
	cout << (is_prime[97] ? '1' : '0') << endl;

}
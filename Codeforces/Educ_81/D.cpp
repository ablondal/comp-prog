#include <iostream>
#include <vector>

using namespace std;

void Sieve(vector <long long> &primes, long long n){
	primes.clear();
	vector <bool> s(n+1);
	primes.push_back(2);
	for(long long i=3;i<n+1;i+=2){
		if( !s[i] ) continue;
		primes.push_back(i);
		for(long long j=3*i; j<n+1; j+=2*i ){
			s[i] = false;
		}
	}
}



int main(){
	vector <long long> primes;
	Sieve(primes, 10e10);
	cout << primes[primes.size()-1];
}
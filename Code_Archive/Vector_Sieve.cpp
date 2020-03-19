#include <iostream>
#include <vector>

using namespace std;

int main(){
	clock_t t;
	t = clock();
	vector <int> primes;
	primes.push_back(2);
	vector <bool> sieve(1e7);
	fill(sieve.begin(),sieve.end(),true);
	for(int i=3; i<1e7; ++i){
		if (sieve[i]) {
			primes.push_back(i);
			for(int j=2*i; j<1e7; j+=i){
				sieve[j] = false;
			}
		}
	}
	t = clock()-t;
	cout << primes.size() << " primes were found in " << t << " clocks" << endl;
}
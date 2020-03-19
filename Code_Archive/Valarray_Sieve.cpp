#include <valarray>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
	clock_t t;
	t = clock();
	vector <int> primes;
	primes.push_back(2);
	valarray <bool> sieve(true,1e7);
	for(int i=3; i<1e7; ++i){
		if (sieve[i]) {
			primes.push_back(i);
			sieve[ slice(2*i, 1e7/i -1, i) ] = false;
		}
	}
	t = clock()-t;
	cout << primes.size() << " primes were found in " << t << " clocks" << endl;
}
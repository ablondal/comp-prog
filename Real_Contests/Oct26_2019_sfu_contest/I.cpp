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


int hamming(int a, int b) {
	int hamming = a ^ b;
	int count = 0;
	while (hamming != 0) {
		if (hamming%2 == 1) count ++;
		hamming = (hamming>>1);
	}
	return count;
}

int main(){
	int T, N;
	int A[10000];
	cin >> T;
	for (int cases=0;cases<T;cases++){
		cin >> N;
		int maxhamming =0;
		for (int i=0; i<N; i++) {
			cin >> A[i];
		}
		for (int i=0;i<N;i++) {
			for (int j=i+1;j<N;j++) {
				maxhamming = max(maxhamming, hamming(A[i], A[j]));
			}
		}
		cout << maxhamming << endl;
	}

	return 0;
}
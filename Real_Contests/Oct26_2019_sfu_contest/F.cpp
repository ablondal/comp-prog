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

int main(){
	int T, w, h;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> w >> h;
		if (w==h) {
			cout << "Square" << endl;
		}
		else {
			cout << "Rectangle" << endl;
		}
	}


	return 0;
}
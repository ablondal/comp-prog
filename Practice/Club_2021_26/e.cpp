#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ans[500005] = {0};
// int a[500001] = {0};

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n+1);
	rep(i,0,n){
		int ai;
		cin >> ai;
		a[ai] ^= 1;
	}
	vector<cd> b(n+1);
	rep(i,0,n){
		b[i] = a[i];
	}
	int k = 1;
	while(k < b.size()) k <<= 1;
	b.resize(k);
	fft(b, 1);
	rep(i,0,n){
		cout << b[i] << endl;
	}
	int hi = 0;
	rep(i,1,n+1){
		if (a[i]) {
			hi ^= i;
			rep(j,2,n+2){
				ans[j] ^= (i % j);
			}
		}
	}
	rep(j,2,n+2){
		if (ans[j]) {
			cout << "Alice ";
		}else {
			cout << "Bob ";
		}
	}
	cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> COMPLEX;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

vector<vector<int>> convolve(vector<vector<cd>> &a, vector<vector<cd>> &b) {
   int n = 1, m = 1;
   while (n < a.size() + b.size()) {
      n <<= 1;
   }
   while (m < a[0].size() + b[0].size()) {
      m <<= 1;
   }
   a.resize(n);
   b.resize(n);
   rep(i,0,n){
      a[i].resize(m);
      b[i].resize(m);
      fft(a[i], false);
      fft(b[i], false);
   }
   rep(j,0,m){
      vector<cd> atmp(n);
      vector<cd> btmp(n);
      rep(i,0,n){
         atmp[i] = a[i][j];
         btmp[i] = b[i][j];
      }
      fft(atmp, false);
      fft(btmp, false);
      rep(i,0,n){
         a[i][j] = atmp[i];
         b[i][j] = btmp[i];
      }
   }
   rep(i,0,n){
      rep(j,0,m){
         a[i][j] *= b[i][j];
      }
   }
   rep(i,0,n){
      fft(a[i], true);
   }
   rep(j,0,m){
      vector<cd> atmp(n);
      rep(i,0,n){
         atmp[i] = a[i][j];
      }
      fft(atmp, true);
      rep(i,0,n){
         a[i][j] = atmp[i];
      }
   }

   vector<vector<int>> res(n, vi(m));
   rep(i,0,n){
      rep(j,0,m){
         res[i][j] = round(a[i][j].real());
      }
   }

   return res;
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int w1, w2, h1, h2;
   cin >> w1 >> h1;
   vector<vector<cd>> im1 (h1, vector<cd>(w1, 0));
   rep(i,0,h1){
      rep(j,0,w1){
         int a;
         cin >> a;
         if (a==1) im1[h1-i-1][w1-j-1] = 1;
         else im1[h1-i-1][w1-j-1] = -1;
      }
   }
   cin >> w2 >> h2;
   vector<vector<cd>> im2 (h2, vector<cd>(w2, 0));
   rep(i,0,h2){
      rep(j,0,w2){
         int a;
         cin >> a;
         if (a==1) im2[i][j] = 1;
         else im2[i][j] = -1;
      }
   }
   auto res = convolve(im1, im2);
   int m = -1e9;
   rep(i,0,sz(res)){
      rep(j,0,sz(res[0])){
         int x = (j-(w1-1));
         int y = (i-(h1-1));
         if (0<=x && x<=w2-w1 && 0<=y && y<=h2-h1){
            // cout << res[i][j] << " ";
            m = max(m, res[i][j]);
         }
      }
      // cout << endl;
   }

   vector<pair<int, int>> ans;

   rep(i,0,sz(res)){
      rep(j,0,sz(res[0])){
         if (res[i][j] == m){
            int x = (j-(w1-1));
            int y = (i-(h1-1));
            if (0<=x && x<=w2-w1 && 0<=y && y<=h2-h1){
               ans.push_back({x,y});
            }
         }
      }
   }
   sort(all(ans));
   for(auto a : ans){
      cout << a.first << " " << a.second << endl;
   }
}
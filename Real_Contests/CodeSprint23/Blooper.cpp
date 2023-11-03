#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int f(vector<double> &ar, int x, double p, vector<int> &br){
    int answer = 0;
    for(int index = 0; index < ar.size(); index++){
        int i = ar[index];
        if(i <= x){
            br.push_back(0);
        }else{
            int n = (int)ceil(log2((double)x/i) / log2(p) - 0.0000000000001);
            //cout << "x, i, p, n: " << x << " " << i << " " << p << " " << n << endl;
            answer += n;
            br.push_back(n);
        }
    }
    return answer;
}


int main() {
    int n, l;
    cin >> n >> l;
    double p;
    cin >> p;

    double low = 1;
    double high = 0;
    vector<double> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        high = max(high, (double)ar[i]);
    }

    int iit = 0;
    vector<int> bbr(n);
    for(int j = 0; j < 40; j++){
        double mid = (low + high) / 2;
        vector<int> br;
        int it = f(ar, mid, p, br);
        if(it <= l){
            high = mid;
            bbr = br;
            iit = it;
        }else{
            low = mid;
        }
    }


    l -= iit;
    for(int k = 0; k < n; k++){
        if(bbr[k] != 0){
            //double c = ;
            //double d = 
            //cout << c << d << endl;
            ar[k] = pow(ar[k],pow(p,bbr[k]));
        }
    }

    priority_queue<double> h;
    for(int i = 0; i < n; i++){
        h.push(ar[i]);
        //cout << ar[i] << " ";
    }
    //cout << endl;

    for(int j = 0; j < l; j++){
        double x = h.top();
        h.pop();
        h.push((double)pow(x, p));
    }

    double answer = 1;
    while(!h.empty()){
        
        answer /= h.top();
        h.pop();
    }
    cout << endl;
    printf("%.12lf\n", answer);
}
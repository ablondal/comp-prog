#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;
ld prob[101][101] = {0};

int main(){
    int N;
    cin >> N;
    vector <int> Probs(N);
    for(int i=0; i<N; ++i) cin >> Probs[i];
    sort(Probs.begin(), Probs.end());

    prob[0][0] = 1;
    for(int P = N-1; P>= 0; --P){
        int num = N - P;
        for(int a=0; a <= num; ++a ){
            if( a==0 ){
                prob[num][0] = prob[num-1][0] * ( double(100-Probs[P]) / 100.0 );
            }else{
                prob[num][a] = 
                    prob[num-1][a] * ( double(100-Probs[P]) / 100.0 ) +
                    prob[num-1][a-1] * ( double(Probs[P]) / 100.0 );
            }
            //cout << "Prob with " << num << " papers of " << a << " successes is " << prob[num][a] << endl;
        }
    }
    ld exp(0);
    ld maxexp(0);
    for(int P = N-1; P>= 0; --P){
        int num = N - P;
        exp = 0;
        for(int a=1; a <= num; ++a ){
            exp += prob[num][a] * ( pow( ld(a), ld(a) / ld(num) ) );
        }
        //cout << "With " << num << " papers, exp is " << exp << endl;
        if(exp > maxexp) maxexp = exp;
    }
    printf("%0.9Lf\n",maxexp);
}
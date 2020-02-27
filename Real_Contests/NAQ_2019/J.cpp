#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long best, curr;
    int l_best;
    long double ave;
    vector <int> cards(N);
    curr = 0;
    best = 0;
    l_best = 1;
    for(int i=0; i< N; ++i){
        cin >> cards[i];
    }
    for(int i=0; i< N; ++i){
        curr += cards[i];
        if( double(curr) / double(i+1) > double(best)/double(l_best) ){
            best = curr;
            l_best = i+1;
        }
    }
    curr = 0;
    for(int i=N-1; i>=0; --i){
        curr += cards[i];
        if( double(curr) / double(N-i) > double(best)/double(l_best) ){
            best = curr;
            l_best = N-i;
        }
    }
    printf("%0.8lf\n",double(best) / double(l_best));
    //cout << double(best) / double(l_best) << endl;
}
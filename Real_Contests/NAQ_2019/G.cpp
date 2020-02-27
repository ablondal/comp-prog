#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef long double ld;

vector <ld> papers;
vector <ld> qpers;
vector <ld> probofnpapers;

ld getexpec(int S){
    ld ave = 0;
    for(int a=0; a <= S; ++a){
        ld produc = pow(ld(a), ld(a)/ld(S));
        if(a == 0) produc = 0;
        ave += probofnpapers[a] * produc;
        //cout << a << ": " << probofnpapers[a] << " with research value " << produc << endl;
    }
    return ave;
}


int main(){
    int N;
    cin >> N;
    papers.resize(N);
    for(int i=0; i<N; ++i){
        cin >> papers[i];
        papers[i] /= 100.0;
    }
    sort(papers.begin(), papers.end());
    qpers.resize(N);
    for(int i=0; i<N; ++i){
        qpers[i] = 1-papers[i];
    }


    ld maxexpec;
    ld currexpec;
    probofnpapers.resize(N+1,0);
    probofnpapers[0] = 1;
    for(int i=N-1; i>=0; --i){
        int maxposs = N-i;
        for(int j=maxposs; j >= 0; --j){
            if(j==0)
                probofnpapers[j] = probofnpapers[j]*qpers[i];
            else 
                probofnpapers[j] = (
                probofnpapers[j]*qpers[i] +  // No success on the paper
                probofnpapers[j-1]*papers[i]); // Add a successful paper
        }
        
        currexpec = getexpec(maxposs);
        //cout << "With the " << maxposs << " top papers, expected val is " << currexpec << endl;
        if(currexpec > maxexpec) maxexpec = currexpec;
        //else break;
    }
    
    printf("%0.30Lf\n",maxexpec);
}
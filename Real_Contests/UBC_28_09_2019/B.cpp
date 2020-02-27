#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

vector <string> names;
vector <int> winners;
vector <int> HP, Att, Def;

int wins(int A, int B){
    int Adam = Att[A] - Def[B];
    int Bdam = Att[B] - Def[A];
    if( Adam<=0 ){
        if(Bdam<=0){
            return 0; // Stalemate
        }
        return 2; // B wins
    }else if( Bdam<=0 ){
        return 1; // A wins
    }
    int AtoKill = ceil( (float)HP[B] / (float)Adam );
    int BtoKill = ceil( (float)HP[A] / (float)Bdam );
    if (AtoKill < BtoKill) return 1; // A wins
    else if (AtoKill == BtoKill) return 0; // Tie
    else return 2; // B wins
}

int main(){
    int N;
    
    int A, B, C;
     
    cin >> N;
    names.resize(N);
    Att.resize(N);
    Def.resize(N);
    HP.resize(N);
    for(int i=0; i < N; ++i){
        cin >> names[i] >> HP[i] >> Att[i] >> Def[i];
    }
    for(int i=0; i < N-2; ++i){
        for(int j=i+1; j < N-1; ++j){
            for(int k=j+1; k<N; ++k){
                A = wins(i,j);
                B = wins(j,k);
                C = wins(k,i);
                if (A!=0 && A==B && B==C){
                    winners.push_back(i);
                    winners.push_back(j);
                    winners.push_back(k);
                }
            }
        }
    }
    cout << winners.size()/3 << endl;
    for(int i=0; i < winners.size()/3 ; ++i){
        cout << names[winners[3*i]] << ' ' << names[winners[3*i + 1]] << ' ' << names[winners[3*i + 2]] << endl;
    }

    return 0;
}
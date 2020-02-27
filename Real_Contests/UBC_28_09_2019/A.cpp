#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

// DONE //

int main(){
    char ED;
    cin >> ED;
    int shift;
    cin >> shift;
    char inp[100];
    char oup[100];
    cin >> inp;
    if(ED == 'D') shift *= -1;
    
    int i=0;
    for(; inp[i] != 0; ++i){
        oup[i] = (inp[i] - 'a' + shift + 26) % 26 + 'a';
    }
    oup[i] = 0;
    cout << oup << endl;
    return 0;
}
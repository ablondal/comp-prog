#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int ex = 0;
    int currmax = 0;
    vector <int> scenes;
    scenes.resize(N);
    for(int i=0; i < N; ++i){
        cin >> scenes[i];
    }
    sort(scenes.begin(), scenes.end());
    for(int i=0; i < K ;++i){
        ex += scenes[N-1-i];
    }
    cout << ex << endl;
    return 0;
}
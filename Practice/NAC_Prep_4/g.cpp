#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> sprinkled(10005, vector<bool>(10005));
    map<pair<int,int>, int> gobs;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        gobs[make_pair(x, y)]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y, r;
        cin >> x >> y >> r;
        int r2 = r * r;
        for(int j = x - r; j <= x + r; j++){
            for(int k = y - r; k <= y + r; k++){
                if(j < 0 || j > 10000 || k < 0 || k > 10000) {
                    continue;
                }
                int dist = pow(x - j, 2) + pow(y - k, 2) + 0.5;
                if(dist <= r2){
                    sprinkled[j][k] = true;
                }
            }
        }
    }
    int answer = n;
    for(int i = 0; i < 10005; i++){
        for(int j = 0; j < 10005; j++){
            if(sprinkled[i][j]){
                answer -= gobs[make_pair(i, j)];
            }
        }
    }
    cout << answer << endl;
}
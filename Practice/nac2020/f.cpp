#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> locs(k);
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            locs[val-1].push_back({i, j});
        }
    }
    bool possible = true;
    for(int i = 0; i < k; i++){
        if(locs[i].empty()){
            possible = false;
        }
    }
    if(possible){
        for(int i = 0; i < locs[0].size(); i++){
            int x = locs[0][i].first;
            int y = locs[0][i].second;
            dp[x][y] = 0;
        }
        for(int l = 1; l < k; l++){
            for(int i = 0; i < locs[l].size(); i++){
                for(int j = 0; j < locs[l-1].size(); j++){
                    auto next = locs[l][i];
                    auto prev = locs[l-1][j];
                    int dist = abs(next.first - prev.first) + abs(next.second - prev.second);
                    dp[next.first][next.second] = min(dp[next.first][next.second], dp[prev.first][prev.second] + dist);
                }
            }
        }
        int answer = 1e9;
        for(int i = 0; i < locs[k-1].size(); i++){
            auto cur = locs[k-1][i];
            answer = min(answer, dp[cur.first][cur.second]);
        }
        cout << answer << endl;
    }else{
        cout << -1 << endl;
    }

}
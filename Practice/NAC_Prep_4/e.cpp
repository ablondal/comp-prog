#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i].second >> times[i].first;
    }
    sort(times.begin(), times.end());
    int answer = 0;
    int rem = k;
    queue<int> remove;
    int j = 0;
    for(; j<min(rem, n); ++j){
        remove.push(times[j].first);
        answer++;
    }

    while(j < n){
        int c_t = remove.front();
        while(j < n && times[j].second < c_t) {
            ++j;
        }
        if (j==n) break;
        remove.pop();
        remove.push(times[j].first);
        answer++;
        j++;
    }

    // for(int i = 0; i < n; i++){
    //     while(!remove.empty() && remove.front() <= times[i].second) {
    //         remove.pop();
    //         rem++;
    //     }
    //     if(rem > 0){
    //         remove.push(times[i].first);
    //         answer++;
    //         rem--;
    //     }
    // }
    cout << answer << endl;
}
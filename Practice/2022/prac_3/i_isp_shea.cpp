#include <bits/stdc++.h>
using namespace std;

int n, m, k;
map<int, vector<int>> edges;
vector<int> sockets;
vector<bool> visited;
bool works = true;
bool hasCycle = false;
int howmany = 0;

pair<int, int> dfs(int curNode, int lastNode) {
    if(visited[curNode]){
        hasCycle = true;
        return {0, 0};
    }
    visited[curNode] = true;
    howmany++;
    int nsock=sockets[curNode], nedg = edges[curNode].size();
    // int val = 0;
    for(int i = 0; i < edges[curNode].size(); i++){
        if(edges[curNode][i] != lastNode) {
            auto [s, e] =dfs(edges[curNode][i], curNode);
            nsock+=s;
            nedg+=e;
            // val += dfs(edges[curNode][i], curNode);
        }
    }
    return {nsock, nedg};
}


priority_queue<pair<int, int>> Q;
int totcost = 0;

void pushtoQ(int freesock, int n_del){
    if (freesock >= 1){
        Q.push({freesock, n_del});
    } else if (n_del >= 1){
        Q.push({freesock+2, n_del-1});
        totcost++;
    } else {
        Q.push({1,0});
        Q.push({1,0});
        totcost++;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    sockets = vector<int>(n);
    visited = vector<bool>(n);
    int socketSum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &sockets[i]);
        socketSum += sockets[i];
    }
    if(socketSum < (2 * n - 2)) {
        works = false;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // vector<tuple<int, int, int>> comps;


    // vector<pair<int, bool>> extras;


    for(int i = 0; i < n; i++){
        if(!visited[i]){
            auto [nsock, nedg] = dfs(i, -1);

            int freesock = nsock - nedg;
            nedg /= 2;
            int n_deletions = nedg+1-howmany;
            howmany = 0;

            // cout << freesock << " " << n_deletions << endl;

            pushtoQ(freesock, n_deletions);
            // comps.push_back({nsock, nedg, howmany});

            // hasCycle = false;
            // int extrasFound = dfs(i, -1);
            // extras.push_back({extrasFound, hasCycle});
            //printf("cycle: %d\n", hasCycle);
        }
    }

    while(Q.size() > 1 && totcost <= k && works){
        auto [s1, e1] = Q.top();
        Q.pop();
        auto [s2, e2] = Q.top();
        Q.pop();
        totcost++;
        // cout << s1 << " " << s2 << endl;
        if (Q.empty()) break; 
        pushtoQ(s1+s2-2, e1+e2);
    }

    if (totcost<=k && works) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }



    // if(!works){
    //     printf("no\n");
    // }else if(extras.size() == 1){
    //     printf("yes\n");
    // }else{
    //     int answer = 0;
    //     int numComponents = 0;
    //     int numExtras = 0;
    //     for(int i = 0; i < extras.size(); i++){
    //         if(extras[i].first == 0){
    //             if(hasCycle){
    //                 answer += 1;
    //                 numComponents++;
    //                 numExtras += 2;
    //             }else{
    //                 answer += 1;
    //                 numComponents += 2;
    //                 numExtras += 2;
    //             }
    //         }else{
    //             numComponents++;
    //             numExtras += extras[i].first;
    //         }
    //     }
    //     printf("%d %d %d\n", answer ,numComponents, numExtras);
    //     if(numComponents * 2 - 2 > numExtras){
    //         answer += (numComponents * 2 - 1 - numExtras) / 2;
    //     }
    //     answer += numComponents - 1;
    //     if(answer <= k){
    //         printf("yes\n");
    //     }else{
    //         printf("no\n");
    //     }
    // }
}
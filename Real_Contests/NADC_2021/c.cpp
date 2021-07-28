#include <bits/stdc++.h>
using namespace std;

int groups[100][100];
bool visited[100][100];
int vals[100][100];


const int maxn = 10010, maxm = 10010;

int matching[10010];
bool visited2[10010] = {false};

bool dfs(int u, map<int, unordered_set<int>> &edges) {
  for(auto it = edges[u].begin(); it != edges[u].end(); it++){
    int v = *it;
    if (!visited2[v]) {
      visited2[v] = true;
      if (matching[v] == -1 || dfs(matching[v], edges)) {
        matching[v] = u;
        matching[u] = v;
        return true;
      }
    }
  }
  return false;
}

int hungarian(map<int, unordered_set<int>> &edges) {
	int ans = 0;
	memset(matching, -1, sizeof(matching));
  for(auto it = edges.begin(); it != edges.end(); it++){
    int u = it->first;
    if (matching[u] == -1) {
		  memset(visited2, false, sizeof(visited2));
		  if (dfs(u, edges)) ans++;
    }
  }
	return ans;
}


void fillGroup(int r, int c, int n, int m, int group, int last){
  if(r >= 0 && r < n && c >= 0 && c < m){
    if(!visited[r][c] && vals[r][c] == last){
      visited[r][c] = true;
      groups[r][c] = group;
      fillGroup(r-1, c, n, m, group, last);
      fillGroup(r+1, c, n, m, group, last);
      fillGroup(r, c-1, n, m, group, last);
      fillGroup(r, c+1, n, m, group, last);
    }
  }
}


int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  string row;
  for(int i = 0; i < n; i++){
    cin >> row;
    for(int j = 0; j < m; j++){
      if(row[j] == '1'){
        vals[i][j] = 1;
      }else{
        vals[i][j] = 0;
      }
      visited[i][j] = false;
      groups[i][j] = -1;
    }
  }
  unordered_set<int> groupsChose;
  int group = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!visited[i][j]){
        fillGroup(i, j, n, m, group, vals[i][j]);
        group++;
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 || j == 0 || i == n-1 || j == n-1){
        groupsChose.emplace(groups[i][j]);
      }
      printf("%d ", groups[i][j]);
    }
    printf("\n");
  }
  map<int, unordered_set<int>> edges;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(groupsChose.find(groups[i][j]) == groupsChose.end()){
        if(i > 0 && groups[i-1][j] != groups[i][j] && groupsChose.find(groups[i-1][j]) == groupsChose.end()){
          edges[groups[i][j]].emplace(groups[i-1][j]);
          edges[groups[i-1][j]].emplace(groups[i][j]);
        }
        if(i+1 < n && groups[i+1][j] != groups[i][j] && groupsChose.find(groups[i+1][j]) == groupsChose.end()){
          edges[groups[i][j]].emplace(groups[i+1][j]);
          edges[groups[i+1][j]].emplace(groups[i][j]);
        }
        if(j > 0 && groups[i][j-1] != groups[i][j] && groupsChose.find(groups[i][j-1]) == groupsChose.end()){
          edges[groups[i][j]].emplace(groups[i][j-1]);
          edges[groups[i][j-1]].emplace(groups[i][j]);
        }
        if(j+1 < m && groups[i][j+1] != groups[i][j] && groupsChose.find(groups[i][j+1]) == groupsChose.end()){
          edges[groups[i][j]].emplace(groups[i][j+1]);
          edges[groups[i][j+1]].emplace(groups[i][j]);
        }
      }
    }
  }
  for(auto it = edges.begin(); it != edges.end(); it++){
    int val = it->first;
    auto rest = it->second;
    printf("%d: ", val);
    for(auto it2 = rest.begin(); it2 != rest.end(); it2++){
      printf("%d ", *it2);
    }
    printf("\n");
  }
  int ans = hungarian(edges);
  cout << ans << endl;
}
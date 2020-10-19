#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int MAXN = 1e5+7;
const int M = 1e9+7;

int adj[MAXN][2];
int outp[MAXN];
ll num[MAXN][4] = {{0}}; // real 0, real 1, inc 0, inc 1
ll nur[MAXN][2] = {{0}};
int n, x, y;

void dfs(int v){
  if (v == 0){
    return;
  }
  int a = adj[v][0];
  int b = adj[v][1];
  dfs(a);
  dfs(b);

  num[v][0] = (
    num[a][1] * num[b][1]
  ) % M;
  
  num[v][1] = (
    num[a][0] * (num[b][0] + num[b][1] + num[b][2] + num[b][3])
  ) % M + (
    num[b][0] * (num[a][1] + num[a][2] + num[a][3])
  ) % M + (
    num[a][2] * num[b][3] + num[a][3] * num[b][2]
  ) % M;
  num[v][1] %= M;
  
  num[v][2] = (
    num[a][1] * num[b][3] +
    num[a][3] * num[b][1] +
    num[a][3] * num[b][3]
  ) % M;

  num[v][3] = (
    num[a][1] * num[b][2] +
    num[a][2] * num[b][1] +
    num[a][2] * num[b][2]
  ) % M;

  if (outp[v]==1){
    num[v][1] = (
      num[v][1] + num[v][3]
    ) % M;
    num[v][2] = (
      num[v][0] + num[v][2]
    ) % M;
    num[v][0] = 0;
    num[v][3] = 0;
  } else if (outp[v]==0){
    num[v][3] = (
      num[v][1] + num[v][3]
    ) % M;
    num[v][0] = (
      num[v][0] + num[v][2]
    ) % M;
    num[v][2] = 0;
    num[v][1] = 0;
  }
  // printf("%d: %lli %lli %lli %lli\n", v, num[v][0], num[v][1], num[v][2], num[v][3]);
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; ++i){
    scanf("%d%d%d", &adj[i][0], &adj[i][1], outp+i);
  }
  num[0][0] = num[0][1] = 1;
  dfs(1);
  printf("%lli\n", (num[1][2]+num[1][3])%M);
}
#include <bits/stdc++.h>
using namespace std;
typedef  pair<int, int> ii;
typedef vector<int> vi;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i);
#define max(a,b) ((a>b)?a:b)
const int MAXN = 1e5+1;

int n, l;
vector<ii> adj[MAXN];
char edg_used[MAXN*2] = {0};

struct union_find {
  vi p;
  union_find(int n) :p(n+1,-1){}
  int find(int x){return p[x]<0?x:p[x]=find(p[x]);}
  bool unite(int x, int y){
    int xp= find(x), yp = find(y);
    if (xp==yp) return false;
    if (p[xp] > p[yp])swap(xp,yp);
    p[xp] +=p[yp], p[yp]=xp;
    return true;
  }
  int size(int x) {return -p[find(x)];}
};

int mst(int n, vector<pair<int, ii> > &edges) {
  int i;
  union_find uf(n);
  int num_t = n;
  int tot_w = 0;
  for (int i=0;i<edges.size() && num_t > 1;i++) {
    int a, b;
    a = uf.find(edges[i].second.first);
    b = uf.find(edges[i].second.second);
    if (a!= b) {
      adj[edges[i].second.first].push_back({edges[i].second.second, edges[i].first});
      adj[edges[i].second.second].push_back({edges[i].second.first, edges[i].first});
      uf.unite(a, b);
      num_t--;
      tot_w += edges[i].first;
      edg_used[i] = 1;
    }
  }
  return tot_w;
}

// vector<pair<int, ii> > mst_uv(int n, vector<pair<int, ii> > edges, int u, int v) {
//   int i;
//   union_find uf(n);
//   uf.unite(u,v); //fix initial input
//   vector<pair<int, ii> > res;
//   for (int i=0;i<edges.size();i++) {
//     if ((edges[i].second.first ==u  && edges[i].second.second == v) || ((edges[i].second.first ==v  && edges[i].second.second == u))){
//       // add initial input to mst
//       res.push_back(edges[i]);
//     }
//     int a, b;
//     a = uf.find(edges[i].second.first);
//     b = uf.find(edges[i].second.second);
//     if (a!= b) {
//       res.push_back(edges[i]);
//       uf.unite(a, b);
//     }
//   }
//   return res;
// }


int timer;
int tin[MAXN], tout[MAXN];
int up[MAXN][18];
int big[MAXN][18];

void dfs(int v, int p, int cost)
{
  tin[v] = ++timer;
  up[v][0] = p;
  big[v][0] = cost;
  for(int i=1; i<= l; ++i){
    int u = up[v][i-1];
    up[v][i] = up[u][i-1];
    big[v][i] = max(big[v][i-1], big[u][i-1]);
  }
  for(auto u: adj[v]) {
    if (u.first != p){
      dfs(u.first, v, u.second);
    }
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
  return tin[u] < tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
  if (is_ancestor(u, v)){
    return u;
  }else if (is_ancestor(v, u)){
    return v;
  }
  for(int i=l; i>=0; --i){
    if (!is_ancestor(up[u][i], v)){
      u = up[u][i];
    }
  }
  return up[u][0];
}

int bigg(int u, int v, int a){
  int i=l;
  int b = 0;
  while(i>=0 && u != a){
    if(!is_ancestor(up[u][i], a)){
      b = max(b, big[u][i]);
      u = up[u][i];
    }
    --i;
  }
  i = l;
  while(i>=0 && v != a){
    if(!is_ancestor(up[v][i], a)){
      b = max(b, big[v][i]);
      v = up[v][i];
    }
    --i;
  }
  return b;
}

void preprocess(int root) {
  // tin.resize(n+1);
  // tout.resize(n+1);
  timer = 0;
  l = ceil(log2(n));
  // up.assign(n+1, vector<int>(l+1));
  // big.assign(n+1, vector<int>(l+1));
  // cout << "hi3.5" << endl;
  dfs(root, root, 0);
}

int main(){
  int r,a,b,c,u,v,q,min_cost;
  // cin >> n>> r;
  scanf("%d%d", &n, &r);
  vector<pair<int, ii> > edges(r);
  unordered_map<long long, int > edg_info;
  for (int i=0;i<r;i++) {
    // cin >> a >> b >>c;
    scanf("%d%d%d", &edges[i].second.first, &edges[i].second.second, &edges[i].first );
    // edges[i] = {c,{a,b}};
  }
  sort(edges.begin(),edges.end());
  for(int i=0; i<r; ++i){
    edg_info[(long long)edges[i].second.first*1000000+edges[i].second.second] = i;
  }
  //make mst 
  int main_mst_cost = mst(n,edges);

  // cout << "hi1" << endl;
  // cout << "hi2" << endl;
  // for (int j=0;j<q_mst.size();j++){
  //       main_mst_cost += q_mst[j].first;
  //       a = q_mst[j].second.first;
  //       b = q_mst[j].second.second;
  //       mst_edges.insert((long long)a*1000000+b);
  //       adj[a].push_back({b, q_mst[j].first});
  //       adj[b].push_back({a, q_mst[j].first});
  // }
  // cout << "hi3" << endl;
  preprocess(1);
  // cout << "hi4" << endl;

  // cin >> q;
  scanf("%d", &q);
  for (int i=0;i<q;i++) {
    scanf("%d%d", &u, &v);
    // cin >> u >> v;
    //query in mst
    // cout << "hi" << endl;
    
    // cout << "bye" << endl;
    min_cost =0;
    int e = edg_info[(long long) u*1000000+v];
    // cout << "ancestor: " << lca(u, v) << endl;
    if (edg_used[e]) {
      min_cost = main_mst_cost;
    }else{
      min_cost = main_mst_cost + edges[e].first - bigg(u, v, lca(u, v));
    }
    
    // cout << min_cost <<endl;
    printf("%d\n", min_cost);
    
  }
  return 0;
}

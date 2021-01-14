#include <vector>
#include <cstdio>
#include <utility>
#include <numeric>
#include <stack>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct inves{
  int a[2];
  int p;
  int r;
};

inves I[51];
int N;

vi adj[52];
int lo[52];
int ord[52];
char V[52];
char V2[52];
stack <int> S;
int tim;
int BV[3];

int DFS(int v){
  if(V[v]) return lo[v];
  ord[v] = lo[v] = tim++;
  V[v] = true;
  V2[v] = true;
  S.push(v);
  for(auto e : adj[v]){
    if (!V[e] || V2[e]){
      lo[v] = min(lo[v], DFS(e));
      // printf("%d found %d with lo %d\n",v,e,lo[v]);
    }
  }
  if (ord[v] == lo[v]) {
    int w;
    do{
      w = S.top();
      S.pop();
      V2[w] = false;
      ord[w] = v;
    }while(w != v);
  }
  return lo[v];
}

bool SAT(){
  rep(i,0,52){
    adj[i].clear();
    lo[i] = -1;
    ord[i] = -1;
    V[i] = false;
    V2[i] = false;
  }

  tim = 0;
  rep(i,0,N){
    auto V = I[i];
    int nv = 0;
    rep(j,0,2) rep(k,0,3) if (BV[k]==V.a[j]) nv++;
    if (2-nv < V.r) {
      return false;
    }
    int m = V.p==1 ? 0 : 1;
    if (V.r==2) {
      rep(j,0,2){
        int v = 2*V.a[j]+m;
        adj[v^1].push_back(v);
      }
    }else if (V.r==0){
      rep(j,0,2){
        int in = false;
        rep(k,0,3) if (BV[k]==V.a[j]) in = true;
        if (!in) {
          int v = 2*V.a[j]+m;
          adj[v].push_back(v^1);
        }
      }
    }else{
      if(nv){
        rep(j,0,2){
          int in = false;
          rep(k,0,3) if (BV[k]==V.a[j]) in = true;
          if (!in) {
            int v = 2*V.a[j]+m;
            adj[v^1].push_back(v);
          }
        }
      }else{
        int v0 = 2*V.a[0]+m;
        int v1 = 2*V.a[1]+m;
        adj[v0].push_back(v1^1);
        adj[v1^1].push_back(v0);
        adj[v1].push_back(v0^1);
        adj[v0^1].push_back(v1);
      }
    }
  }
  rep(i,0,52){
    DFS(i);
  }
  // rep(i,0,52){
  //   printf("%d: %d\n", i, ord[i]);
  //   for(auto e : adj[i]){
  //     printf("%d -> %d\n", i, e);
  //   }
  // }
  rep(i,0,26){
    if (ord[2*i]==ord[2*i+1]){
      // printf("%d %d %d: %d %d failed\n",BV[0],BV[1],BV[2], 2*i, 2*i+1);
      return false;
    }
  }

  return true;
}

int main() {
  scanf("%d", &N);
  rep(i,0,N){
    char a,b;
    scanf(" %c%c",&a,&b);
    scanf("%d %d", &I[i].p, &I[i].r);
    I[i].a[0] = a-'A';
    I[i].a[1] = b-'A';
  }
  int tot = 0;
  rep(a,0,24){
    BV[0]=a;
    rep(b,a+1,25){
      BV[1]=b;
      rep(c,b+1,26){
        BV[2]=c;
        // printf("\n%d %d %d\n-------\n",BV[0],BV[1],BV[2]);
        tot+=SAT();
      }
    }
  }
  printf("%d\n", tot);
}
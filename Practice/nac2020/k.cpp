#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//rmq
template<class T>
struct RMQ{
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V): jmp(1,V){
        for(int pw=1,k=1;pw*2<=sz(V);pw*=2,++k){
            jmp.emplace_back(sz(V)-pw*2+1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j]=min(jmp[k-1][j],jmp[k-1][j+pw]);
        }
    }
    T query(int a,int b){
        assert(a<b);
        int dep=31-__builtin_clz(b-a);
        return min(jmp[dep][a],jmp[dep][b-(1<<dep)]);
    }
};
//lca
vi depth;
struct LCA{
    int T=0;
    vi time,path,ret;
    RMQ<int>rmq;
    LCA(vector<vi>&C):time(sz(C)),rmq((dfs(C,0,-1),ret)){}
    void dfs(vector<vi>& C, int v, int par){
        time[v]=T++;
        for(int y: C[v])if(y!=par){
            path.push_back(v),ret.push_back(time[v]);
            dfs(C,y,v);
        }
    }
    int lca(int a,int b){
        if(a==b)return a;
        tie(a,b)=minmax(time[a],time[b]);
        return path[rmq.query(a,b)];
    }
    int dist(int a,int b){
        return depth[a]+depth[b]-2*depth[lca(a,b)];
    }
};
void ddfs(vector<vi>&C,vi&vit, int now,int nowD){
    depth[now]=nowD;
    vit[now]=1;
    for(auto v:C[now]){
        if(!vit[v]){
            ddfs(C,vit,v,nowD+1);
        }
    }
}
void getDepth(vector<vi>&C){
    depth.resize(C.size());
    vi vit(C.size(),0);
    ddfs(C,vit,0,0);

    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,q,i,j,k,s,t;
    cin>>n>>q;
    vector<vi>C(n);
    for(i=1;i<=n-1;++i){
        cin>>s>>t;
        s--;
        t--;
        C[s].push_back(t);
        C[t].push_back(s);
    }
    getDepth(C);
    LCA L(C);
    for(i=0;i<q;++i){
        cin>>s>>t;
        s--;
        t--;
        ll dis=L.dist(s,t);
        ll ans=n+dis*2-1+(dis-1)*(dis-2)/2;
        cout<<ans<<"\n";
    }
    return 0;
}

     
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class T>
struct RMQ{
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V):jmp(1,V){
		for(int pw=1,k=1;pw*2<=sz(V);pw*=2,++k){
			jmp.emplace_back(sz(V)-pw*2+1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j]=min(jmp[k-1][j],jmp[k-1][j+pw]);
		}
	}
	T query(int a, int b){
		assert(a<b);
		int dep=31-__builtin_clz(b-a);
		return min(jmp[dep][a],jmp[dep][b-(1<<dep)]);
	}
};

vi depth;
void getd(vector<vi>&C,vi& vit, int now, int d){
	//out<<now<<"!"<<endl;
	vit[now]=1;
	depth[now]=d;
	for(auto v:C[now]){
		if(!vit[v]){
			getd(C,vit,v,d+1);
		}
	}
}

struct LCA{
	int T=0;
	vi time,path,ret;
	RMQ<int>rmq;
	LCA(vector<vi>& C):time(sz(C)),rmq((dfs(C,0,-1),ret)){}
	void dfs(vector<vi>&C, int v, int par){
		time[v]=T++;
		for(int y:C[v])if(y!=par){
			path.push_back(v),ret.push_back(time[v]);
			dfs(C,y,v);
		}
	}

	int lca(int a,int b){
		if(a==b)return a;
		tie(a,b)=minmax(time[a],time[b]);
		return path[rmq.query(a,b)];
	}

	int dist(int a, int b){
		//cout<<a<<" "<<b<<" "<<depth[a]<<" "<<depth[b]<<" "<<lca(a,b)<<endl;
		return depth[a]+depth[b]-2*depth[lca(a,b)];
	}

};



int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	vector<vi>C;
	int n,m,i,j,k,s,t;
	cin>>n;

	C.resize(n);
	rep(i,0,n-1){
		cin>>s>>t;
		s--;
		t--;	
		C[s].push_back(t);
		C[t].push_back(s);
	}
	//cout<<1<<endl;
	LCA l(C);
	vi vit(n,0);
	depth.resize(n);
	//cout<<11<<endl;
	getd(C,vit,0,0);
	//cout<<2<<endl;
	ll ans=0;
	for(i=1;i<=n;++i){
		for(j=i*2;j<=n;j+=i){
			ans+=l.dist(i-1,j-1)+1;
			//cout<<i<<j<<l.dist(i-1,j-1)+1<<endl;
		}
	}
	cout<<ans<<endl;
}
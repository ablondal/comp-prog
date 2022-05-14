#include <bits/stdc++.h>
using namespace std;

double f[105],w[105];
vector<vector<string>>a;
vector<string>b;
vector<string>cur;
vector<pair<int,int>>len;
map<string,map<string,int>>mp;
int main(){
    //cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n,m,i,j,k,s,t,rt;
    cin>>rt>>n;
    a.resize(n);
    b.resize(n);
    len.resize(n);
    cur.resize(n);
    string st;
    for(i=0;i<n;++i){
        do{
            cin>>st;
            a[i].push_back(st);
            if(st[st.length()-1]=='?'){
                cin>>st;
                b[i]=st;
                break;
            }
        }while(1);
    }
    for(i=0;i<n;++i){
        len[i].first=a[i].size();
        len[i].second=i;
    }
    sort(len.begin(),len.end());
    int mlen=len[n-1].first;
    int l=0;
    map<string,int>mp0;
    for(auto st:b){
        ++mp0[st];
    }
    t=0;
    for(auto p:mp0){
        t=max(t,p.second);
    }
    memset(w,0,sizeof(w));
    w[1]=((double)t)/((double)n);
    s=0;t=0;
    for(i=0;i<n;++i){
        cur[i]="";
    }
    
    for(j=0;j<=rt;++j){
        mp.clear();
        for(i=l;i<n;++i){
            k=len[i].second;
            cur[i]+=a[k][j];
            ++mp[cur[i]][b[k]];
        }
        t=l;
        for(auto p:mp){
            int mx=0;
            for(auto q:p.second){
                mx=max(mx,q.second);
            }
            //cout<<p.first<<" "<<mx<<endl;
            t+=mx;
        }
        w[j+2]=((double)t)/((double)(n));
        for(i=0;i<l;++i){
            w[j+2]+=1.0/((double)n)*w[j+2-len[i].first-1];
            //cout<<j<<" "<<len[i].first<<" "<<1.0/((double)n)*w[j+2-len[i].first-1]<<endl;
        }
        while(len[l].first<=j+1&&l<n)++l;
    }
    
    memset(f,0,sizeof(f));
    for(i=1;i<=rt;++i){
        for(j=1;j<=i;++j){
            f[i]=max(f[i],f[i-j]+w[j]);
        }
    }
    for(i=1;i<=20;++i)cout<<i<<" "<<w[i]<<" "<<f[i]<<endl;
    cout<<setprecision(9)<<f[rt]<<"\n";
    return 0;
}
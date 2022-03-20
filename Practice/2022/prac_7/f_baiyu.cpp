#include <bits/stdc++.h>
using namespace std;
int n, m;
int nn;
struct mat{double a[75][75];};
mat mul(mat a,mat b)
{
    mat tt;
    int i,j,k;
    memset(tt.a,0,sizeof(tt.a));
    for(i=0;i<nn;i++)
        for(j=0;j<nn;j++)
            for(k=0;k<nn;k++)
                tt.a[i][j]+=a.a[i][k]*b.a[k][j];
    return tt;
}
mat matpow(mat a,long long b)
{
    mat s;
    memset(s.a,0,sizeof(s.a));
    for(int i=0;i<nn;i++)s.a[i][i]=1;
    while(b)
    {
        if(b&1LL)s=mul(s,a);
        a=mul(a,a);
        b=b>>1;
    }
    return s;
}
void output(mat tt)
{
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
            printf("%.2f ",tt.a[i][j]);
        printf("\n");
    }
}
struct state{
    vector<double>p;
    int v;
};
int mp[35][35];
int tr[35][35];
pair<int,int>rt[75];
pair<int,int>ss,st;
int dx[4][2];
vector<int> nxt[75];
bool vit[75];
double dis[75],disq[75];
int main()
{
    dx[0][0]=1;dx[0][1]=0;
    dx[1][0]=0;dx[1][1]=1;
    dx[2][0]=-1;dx[2][1]=0;
    dx[3][0]=0;dx[3][1]=-1;
    int i,j,l,w;
    double t,k;
    scanf("%d%d",&l,&w);
    memset(mp,0,sizeof(mp));
    n=0;
    char c;
    for(i=0;i<l;++i){
        getchar();
        for(j=0;j<w;++j){
            scanf("%c",&c);
            if(c=='E'){
                mp[i][j]=2;
                ss=make_pair(i,j);
            }else if(c=='D'){
                mp[i][j]=3;
                st=make_pair(i,j);
            }else if(c==' '){
                mp[i][j]=1;
                tr[i][j]=n;
                rt[n]=make_pair(i,j);
                n++;
            }
        }
    }


    mat matp,matq;
    memset(matp.a,0,sizeof(matp.a));
    memset(matq.a,0,sizeof(matq.a));
    for (i = 0; i < n; i++)
    {
        int x=rt[i].first,y=rt[i].second;
        matp.a[0][i]=(double)1.0/(double)n;
        for(j=0;j<4;++j){
            int nx=x+dx[j][0],ny=y+dx[j][1];
            if(nx>=0&&nx<l&&ny>=0&&ny<w){
                if(mp[nx][ny]==1){
                    nxt[i].push_back(tr[nx][ny]);
                }
            }
        }
        for(j=0;j<nxt[i].size();++j){
            matq.a[i][nxt[i][j]]=(double)1.0/(double)nxt[i].size();
        }
    }
    
    nn=n;
    //output(p);
    //output(q);
    matp=mul(matp,matpow(matq,99999999));
    matq=mul(matp,matq);
    //output(matp);
    //output(matq);
    vector<double>fp,fq;
    for(i=0;i<n;++i){
        fp.push_back(matp.a[0][i]);
        fq.push_back(matq.a[0][i]);
    }
    memset(dis,0,sizeof(dis));
    memset(vit,false,sizeof(vit));
    queue<state>q;
    for(j=0;j<4;++j){
        int nx=ss.first+dx[j][0],ny=ss.second+dx[j][1];
        if(nx>=0&&nx<l&&ny>=0&&ny<w){
            if(mp[nx][ny]==1){
                state s;
                s.v=tr[nx][ny];
                s.p=fp;
                k=1.0-fp[s.v];
                dis[s.v]=k;
                s.p[s.v]=0;
                for(i=0;i<n;++i){
                    s.p[i]/=k;
                }
                q.push(s);
                vit[s.v]=1;
            }
        }
    }   
    while(!q.empty()){
        state s=q.front();
        q.pop();
        vit[s.v]=0;
        //printf("%d %.8f\n",s.v,dis[s.v]);
        for(i=0;i<nxt[s.v].size();++i){
            int nv=nxt[s.v][i];
            if(dis[nv]<dis[s.v]*(1.0-s.p[nv])){
                dis[nv]=dis[s.v]*(1.0-s.p[nv]);
                //printf("%d %.8f\n",nv,dis[nv]);
                if(!vit[nv]){
                    state ns=s;
                    ns.v=nv;
                    k=1.0-ns.p[nv];
                    ns.p[nv]=0;
                    for(j=0;j<n;++j){
                        ns.p[j]/=k;
                    }
                    q.push(ns);
                    vit[nv]=1;
                }
            }
        }
    }

    memset(disq,0,sizeof(disq));
    memset(vit,false,sizeof(vit));
    for(j=0;j<4;++j){
        int nx=ss.first+dx[j][0],ny=ss.second+dx[j][1];
        if(nx>=0&&nx<l&&ny>=0&&ny<w){
            if(mp[nx][ny]==1){
                state s;
                s.v=tr[nx][ny];
                s.p=fq;
                k=1.0-fq[s.v];
                disq[s.v]=k;
                s.p[s.v]=0;
                for(i=0;i<n;++i){
                    s.p[i]/=k;
                }
                q.push(s);
                vit[s.v]=1;
            }
        }
    }   
    while(!q.empty()){
        state s=q.front();
        q.pop();
        vit[s.v]=0;
        //printf("%d %.8f\n",s.v,disq[s.v]);
        for(i=0;i<nxt[s.v].size();++i){
            int nv=nxt[s.v][i];
            if(disq[nv]<disq[s.v]*(1.0-s.p[nv])){
                disq[nv]=disq[s.v]*(1.0-s.p[nv]);
                //printf("%d %.8f\n",nv,disq[nv]);
                if(!vit[nv]){
                    state ns=s;
                    ns.v=nv;
                    k=1.0-ns.p[nv];
                    ns.p[nv]=0;
                    for(j=0;j<n;++j){
                        ns.p[j]/=k;
                    }
                    q.push(ns);
                    vit[nv]=1;
                }
            }
        }
    }
    
    
    
    
    
    
    k=0;


    for(j=0;j<4;++j){
        int nx=st.first+dx[j][0],ny=st.second+dx[j][1];
        if(nx>=0&&nx<l&&ny>=0&&ny<w){
            if(mp[nx][ny]==1){
                k=max(k,(dis[tr[nx][ny]]+disq[tr[nx][ny]])/2.0);
            }else if(mp[nx][ny]==2){
                k=1.0;
            }
        }
    }   
    printf("%.8f\n",1.0-k);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool vit[55][55];
int main()
{
    int n, m, i, j, k, s, t, tt;
    n=44;
    srand(int(time(0)));
    vector<int>a[55];
    
    printf("%d\n",n);
    bool ok=true;

    do{
        for(i=0;i<n;++i)a[i].clear();
        memset(vit,false,sizeof(vit));
        i=0;j=0;
        do{
            s=rand()%n;
            t=rand()%n;
            if(s!=t&&a[s].size()<3&&a[t].size()<3&&!vit[s][t]){
                a[s].push_back(t);
                a[t].push_back(s);
                vit[s][t]=vit[t][s]=true;
                i++;
                j=0;
            }
            j++;
        }while(i<n/2*3&&j<n*n);
        ok=true;
        //for(i=0;i<n;++i)printf("%d ",a[i].size());printf("\n");
        for(i=0;i<n;++i)if(a[i].size()!=3)ok=false;
    }while(!ok);
    for(i=0;i<n;++i){
        for(j=0;j<a[i].size();++j){
            if(a[i][j]>i){
                printf("%d %d\n",i,a[i][j]);
            }
        }
    }
    return 0;
}
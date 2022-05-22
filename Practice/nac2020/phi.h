const int LIM=5000000;
int phi[LIM];
void calculatePhi(){
    rep(i,0,LIM)phi[i]=i&1?i:i/2;
    for(int i=3;i<LIM;i+=2)if(phi[i]==i)
        for(int j=i;j<LIM;j+=i)phi[j]-=phi[j]/i;
}
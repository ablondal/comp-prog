#include <cstdio>
#include <vector>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;

bool chck(vector<int> &K){
  for(int i=1; i<K.size(); ++i){
    if (K[i] != K[1]) return false;
  }
  return true;
}

int main(){
  int k, n;
  scanf("%d%d", &k, &n);
  vector<int> K(k+1, 0);
  int t;
  for(int i=0; i<n; ++i){
    scanf("%d", &t);
    K[t]++;
  }
  int m = 1;
  int M = 1;
  for(int i=1; i<=k; ++i){
    if (K[i]<K[m]) m = i;
    if (K[i]>K[M]) M = i;
  }
  if (n % k == 1){
    K[M]--;
    if (chck(K)){
      printf("-%d\n", M);
      return 0;
    }
    K[M]++;
  }
  if (n % k == k-1){
    K[m]++;
    if (chck(K)){
      printf("+%d\n", m);
      return 0;
    }
    K[m]--;
  }
  if (n%k==0){
    K[M]--;
    K[m]++;
    if (chck(K)){
      printf("-%d +%d\n", M, m);
      return 0;
    }
  }
  printf("*\n");
}
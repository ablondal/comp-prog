#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;
const int MAXN = 1e5+7;
char works[MAXN] = {0};
string pond;
int n;
char tmp;

bool pondtry(int K){
  for(int i = 0; i<K; ++i){
    int j = i;
    bool w = true;
    do{
      if (pond[j]=='P'){
        w = false;
        break;
      }
      j = (j+K) % n;
    }while(j != i);
    if (w) return 1;
  }
  return 0;
}

int main(){
  cin >> pond;
  n = pond.size();
  int cnt = 0;
  for(int j=1; j<n; ++j){
    int g = gcd(j, n);
    if (g < j){
      if (works[g]){
        cnt++;
        works[j] = 1;
      }
    }else{
      works[j] = pondtry(j);
      cnt += works[j];
    }
  }
  
  cout << cnt << endl;
}
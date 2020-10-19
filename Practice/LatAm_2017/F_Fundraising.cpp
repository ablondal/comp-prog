#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
// DONE
int main(){
  int N;
  scanf("%d", &N);
  vector<pair<pii, ll>> Gs(N);
  for(int i=0; i<N; ++i){
    scanf("%d%d%lli", &Gs[i].first.first, &Gs[i].first.second, &Gs[i].second);
    Gs[i].first.second = -Gs[i].first.second;
  }
  sort(Gs.begin(), Gs.end());
  vector<pair<int, ll>> G;
  for(int i=0; i<N; ++i){
    if (i!=0 &&
        Gs[i].first.first == Gs[i-1].first.first &&
        Gs[i].first.second == Gs[i-1].first.second){
      G[G.size()-1].second += Gs[i].second;
    }else{
      G.push_back({-Gs[i].first.second, Gs[i].second});
    }
  }
  map<int, ll> max_val;
  max_val[0] = 0;
  map<int, ll>::iterator it, it2;
  ll n_val;
  // printf("hi2\n");
  for(int i=0; i<G.size(); ++i){
    it = max_val.lower_bound(G[i].first);
    it--;
    if (it == max_val.begin()){
      n_val = G[i].second;
    } else {
      n_val = G[i].second + it->second;
    }
    it++;
    // printf("fort:%d don:%lli tot:%lli\n", G[i].first, G[i].second, n_val);
    if (it == max_val.end() ||
        it->first > G[i].first ||
        it->second < n_val) {
      max_val[G[i].first] = n_val;
      it = max_val.find(G[i].first);
      it++;
      it2 = it;
      while(it2 != max_val.end() && it2->second <= n_val){
        it2++;
      }
      max_val.erase(it, it2);
    }
  }
  it = max_val.end();
  it--;
  printf("%lli\n", it->second);
}
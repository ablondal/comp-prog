#include <iostream>
#include <vector>
#include <algorithm>
//#include <string>
#include <cmath>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define forint(i, k) for(int i=0; i<int(k); ++i)
// #define pb push_back;
// #define mp make_pair;
typedef pair <int, int> pt;

// DONE
// Oh god oh fuck oh no I guess scanf and printf make more difference than the
// algorithm itself

const int M = 313;
const int N = 2000 * 1000 + 13;
int n, m, q, x, y, c, C;
int a[M][M];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector <pt> ins[N], del[N];
int diff[N];

int DSU[M*M], kr[M*M];
int find(int n){
	return (DSU[n]==n ? n : DSU[n]=find(DSU[n]));
}

int main(){
	// ios_base::sync_with_stdio(false);
 //    cin.tie(0), cout.tie(0);
	scanf("%d%d%d",&n,&m,&q);
	//cin >> n >> m >> q;
	forint(i, M) forint(j, M) a[i][j]=0;
	forint(i, q) diff[i]=0;
	// Make thing
	forint(i, q){
		scanf("%d%d%d",&x,&y,&c);
		//cin >> x >> y >> c;
		x--; y--;
		C = c+1;
		if(a[x][y]==c) continue;
		ins[c].push_back(make_pair(x+n*y, i));
		del[a[x][y]].push_back(make_pair(x+n*y, i));
		a[x][y]=c;
		// forint(yy, m){
		// 	forint(xx, n) cout << a[xx][yy] << " ";
		// 	cout << endl;
		// }
	}
	// Add the elements left on the table to dels
	forint(x,n) forint(y,m) del[a[x][y]].push_back(make_pair(x+n*y, q));
	// reverse order of dels
	forint(i,C) reverse(del[i].begin(), del[i].end());
	// Do each add
	forint(k,n) forint(j,m) a[k][j]=-1;
	forint(i,C){
		if (ins[i].empty()) continue;
		forint(j,m*n) DSU[j]=j;
		//forint(j,m*n) kr[j]=1;
		memset(kr, m*n, 1);
		//forint(k,n) forint(j,m) a[k][j]=0;
		for( pt p: ins[i] ){
			x = p.first % n;
			y = p.first / n;
			// assert(x<n);
			// assert(y<m);
			int d = 1, nx, ny;
			a[x][y] = i;
			forint(k,4){
				nx = x+dx[k];
				ny = y+dy[k];
				if(0<=nx && nx<n && 0<=ny && ny <m && a[nx][ny]==i){
					int p2=find(nx+n*ny);
					int p1=find(x+n*y);
					if(p1!=p2){
						if(kr[p2]>kr[p1]){
							DSU[p1]=p2;
							kr[p2] += kr[p1];
						}else{
							DSU[p2]=p1;
							kr[p1] += kr[p2];
						}
						// cout << "connected bby " << x << " " << y << " w "<<nx<<" "<<ny<<endl;
						d--;
					}
				}
			}
			// forint(xx, m){
			// 	forint(yy, n) cout << a[xx][yy] << " ";
			// 	cout << endl;
			// }
			// cout << endl;
			diff[p.second] += d;
		}
	}
	forint(k,n) forint(j,m) a[k][j]=-1;
	forint(i,C){
		if (del[i].empty()) continue;
		forint(j,m*n) DSU[j]=j;
		// forint(j,m*n) kr[j]=1;
		memset(kr, m*n, 1);
		//forint(k,n) forint(j,m) a[k][j]=0;
		for( pt p: del[i] ){
			x = p.first % n;
			y = p.first / n;
			// assert(x<n);
			// assert(y<m);
			int d = 1, nx, ny;
			a[x][y] = i;
			forint(k,4){
				nx = x+dx[k];
				ny = y+dy[k];
				if(0<=nx && nx<n && 0<=ny && ny <m && a[nx][ny]==i){
					int p2=find(nx+n*ny);
					int p1=find(x+n*y);
					if(p1!=p2){
						if(kr[p2]>kr[p1]){
							DSU[p1]=p2;
							kr[p2] += kr[p1];
						}else{
							DSU[p2]=p1;
							kr[p1] += kr[p2];
						}
						// cout << "connected bby " << x << " " << y << " w "<<nx<<" "<<ny<<endl;
						d--;
					}
				}
			}
			// forint(xx, m){
			// 	forint(yy, n) cout << a[xx][yy] << " ";
			// 	cout << endl;
			// }
			// cout << endl;
			diff[p.second] -= d;
		}
	}


	int t=1;
	forint(i, q){
		t += diff[i];
		// cout << t << endl;
		printf("%d\n",t);
	}

}















#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
string dirc[4] = {"n", "s", "e", "w"};
string dirC[4] = {"N", "S", "E", "W"};

bool maze[22][22] = {{0}};
map <pii, string> V;
int sx, sy, bx, by, tx, ty, r, c;
pii Q[10000];
int Qs, Qt;

string pS;

bool pathTo(int x, int y, int tox, int toy, int blockx, int blocky){
	// cout << "pathing" << endl;
	if (!maze[y][x]){
		return false;
	}else if (x == tox && y == toy){
		pS = "";
		return true;
	}
	map <int, string> V1;
	int Q1[1000];
	int Q1s=0, Q1t=0;
	Q1[Q1t++] = x + y*22;
	V1[x + y*22] = "";
	while(Q1s != Q1t){
		x = Q1[Q1s] % 22;
		y = Q1[Q1s] / 22;
		Q1s++;
		for(int i=0; i<4; ++i){
			int nx = x - dirs[i][1];
			int ny = y - dirs[i][0];
			if (maze[ny][nx] && !(nx==blockx && ny==blocky)){
				if (!V1.count(nx + 22*ny)){
					V1[nx + 22*ny] = V1[x + y*22] + dirc[i];
					if(nx == tox && ny == toy){
						pS = V1[nx + 22*ny];
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d", &r, &c);
	char tmp;
	int mazen = 1;
	while(r!=0 && c!=0){
		for(int y=0; y<=r+1; ++y){
			for(int x=0; x<=c+1; ++x){
				if (y==0 || x==0 || x==c+1 || y==r+1){
					maze[y][x] = false;
					continue;
				}
				scanf(" %c", &tmp);
				if (tmp!='#') {
					maze[y][x] = true;
				}
				if (tmp=='T'){
					tx = x;
					ty = y;
				}else if (tmp=='B'){
					bx = x;
					by = y;
				}else if (tmp=='S'){
					sx = x;
					sy = y;
				}
			}
		}
		// for(int y=0; y<22; ++y){
		// 	for(int x=0; x<22; ++x){
		// 		if(maze[y][x]){
		// 			cout << "1";
		// 		}else{
		// 			cout << "0";
		// 		}
		// 	}
		// 	cout << endl;
		// }
		V.clear();
		int mind = 1000;
		int dis = 0;
		string minS;
		Qs = 0;
		Qt = 0;
		Q[Qt++] = {tx + ty*22, 0};
		Q[Qt++] = {tx + ty*22, 1};
		Q[Qt++] = {tx + ty*22, 2};
		Q[Qt++] = {tx + ty*22, 3};
		V[Q[0]] = V[Q[1]] = V[Q[2]] = V[Q[3]] = "";
		Q[Qt++] = {-1, 0};
		while(mind >= dis && Qt-Qs > 1){
			if (Q[Qs].first == -1){
				dis++;
				Q[Qt++] = {-1, 0};
				Qs++;
			}
			int x = Q[Qs].first % 22;
			int y = Q[Qs].first / 22;
			int d = Q[Qs].second;
			int px = x + dirs[d][1];
			int py = y + dirs[d][0];
			string S = V[Q[Qs]];
			// cout << S << endl;
			// cout << x << " " << y << endl;
			Qs++;
			if (x==bx && y==by){
				if(pathTo(sx, sy, px, py, x, y)){
					string nS = pS + S;
					if (dis < mind){
						minS = nS;
						mind = dis;
						// cout << dis << endl;
					}else if(minS.size() > nS.size()){
						minS = nS;
					}
				}
			}
			for(int di = 0; di<4; ++di){
				int xd = dirs[di][1];
				int yd = dirs[di][0];
				if(maze[y+yd][x+xd] && maze[y+2*yd][x+2*xd]){
					pii MeI = {x+xd + 22*(y+yd), di};
					// cout << MeI.first << " " << MeI.second << endl;
					if(!V.count(MeI)){
						if(pathTo(x+xd, y+yd, px, py, x, y)){
							Q[Qt++] = MeI;
							V[MeI] = pS + dirC[di] + S;
							// cout << dirC[di] << endl;
						}
					}
				}
			}
		}
		printf("Maze #%d\n", mazen);
		if (Qs - Qt == 1){
			printf("Impossible.\n\n");
		}else{
			// for(int ch : minS){
			// 	printf("%c", ch);
			// }
			cout << minS;
			printf("\n\n");
		}

		scanf("%d%d", &r, &c);
		mazen++;
	}
}















